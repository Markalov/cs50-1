/****************************************************************************
 * puff.c 
 *
 * CS50
 * Problem Set 6
 *
 * Dumps contents of a huff-compressed file in human-readable form.
 ***************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

// first and last symbols to dump
#define FIRST '!'
#define LAST '~'

// number of columns to use
#define COLS 8

// prototypes 
bool add_node(Tree* node, Tree* huff_tree);

/**
* builds a huffman tree out of a "forest", 
* defined in forest.h, passed in as an 
* argument
*/
bool build_huff_tree(Forest* f, Tree* huff_tree)
{
    // return early if parameters won't work
    if(f == NULL || huff_tree == NULL)
        return false;

    Tree* cur = pick(f);
    // if we run out of forest, we're done
    if(cur == NULL)
        return true;

    bool added = add_node(cur, huff_tree);
    if(!added)
        return false;

    return build_huff_tree(f, huff_tree);
}

/**
* adds node to the huff_tree in the next
* logical open spot
*/
bool add_node(Tree* node, Tree* huff_tree)
{
    // return early if no add node or huff_tree exists
    if(huff_tree == NULL || node == NULL)
        return false;

    if(huff_tree->left == NULL)
    {
        huff_tree->left = node;
        huff_tree->frequency += node->frequency;
    }
    else if(huff_tree->right == NULL)
    {
        huff_tree->right = node;
        huff_tree->frequency += node->frequency;
    }
    /*
    * this is the last case, b/c we know nodes
    * will be ordered as we pick them (least to 
    * most), so we put the new node to the right
    * and the only subtree to the left
    */
    else
    {
        Tree* tmp = mktree();
        if(tmp == NULL)
            return false;
        memcpy(tmp, huff_tree, sizeof(Tree));

        // reset all values of huff_tree to zero
        huff_tree->symbol = 0;
        huff_tree->frequency = 0;
        huff_tree->left = NULL;
        huff_tree->right = NULL;

        huff_tree->left = tmp;
        huff_tree->frequency += tmp->frequency;
        huff_tree->right = node;
        huff_tree->frequency += node->frequency;
    }
    return true;
}

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s huffed_input_file puffed_output_file\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // open output
    FILE* output = fopen(argv[2], "w");
    if(output == NULL)
    {
        printf("Could not open %s for writing.\n", argv[2]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // build a forest of non-zero-frequency symbols
    Forest* forest = mkforest();
    for(int i=0; i < SYMBOLS; i++)
    {
        if(header.frequencies[i] > 0)
        {
            Tree* tree = mktree();
            tree->symbol = i;
            tree->frequency = header.frequencies[i];
            plant(forest, tree);
        }
    }

    // build ze huff tree out of the forest
    Tree* huff_tree = mktree();
    if(build_huff_tree(forest, huff_tree) == false)
    {
        printf("Memory error\n");
        rmtree(huff_tree);
        rmforest(forest);
        return 1;
    }

    printf("symbol: %c\n"
        "frequency: %d\n"
        "left: %p\n"
        "right: %p\n",
        huff_tree->symbol,
        huff_tree->frequency,
        huff_tree->left,
        huff_tree->right);

    // count the total # of bits in the file, minus the header
    Tree* walker = huff_tree;
    int bit;
    while ((bit = bread(input)) != EOF)
    {
        // we've found a letter
        if(walker->left == NULL && walker->right == NULL)
        {
            // print found character
            int printed = fprintf(output, "%c", walker->symbol);
            
            // end early if we couldn't print 1 character to file
            if(printed != 1)
            {
                printf("Unable to write to %s\n", argv[2]);
                rmtree(walker);
                rmtree(huff_tree);
                rmforest(forest);
                return 1;
            }

            // reset the walker tree to root of huff tree
            walker = huff_tree;
        }

        if(bit == 0)
            walker = walker->left;
        else 
            walker = walker->right;
    }
    printf("\n\n");

    rmtree(huff_tree);
    rmforest(forest);

    // close input and output files
    hfclose(input);
    fclose(output);

    // that's all folks!
    return 0;
}
