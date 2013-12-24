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
void build_huff_tree(Forest* f, Tree* huff_tree)
{
    // return early if parameters won't work
    if(f == NULL || huff_tree == NULL)
        return;

    Tree* cur = pick(f);
    // if we run out of forest, we're done
    if(cur == NULL)
        return;

    add_node(cur, huff_tree);
    build_huff_tree(f, huff_tree);
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
        tmp->left = huff_tree;
        tmp->frequency += huff_tree->frequency;
        tmp->right = node;
        tmp->frequency += node->frequency;
        *huff_tree = *tmp;
        // this last line fails b/c the actual mem
        // of huff_tree becomes tmp, which is also
        // the left child of tmp, so we have a recursive
        // or cyclical definition...TODO fix...
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

    /*
    // determine number of rows to use
    const int rows = (int) ceil((LAST - FIRST) / (double) COLS);

    // dump frequencies in a nice table
    printf("\n");
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int index = FIRST + row + rows * col;
            if (index > LAST)
            {
                break;
            }
            printf("%c %-6d  ", index, header.frequencies[index]);
        }
        printf("\n");
    }
    printf("\n");
    */

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
    build_huff_tree(forest, huff_tree);

    // TODO uncomment the below 
    // rmforest(forest);

    // dump bits contiguously
    int bit;
    while ((bit = bread(input)) != EOF)
    {
        printf("%d", bit);
    }
    printf("\n\n");

    // close input
    hfclose(input);

    // that's all folks!
    return 0;
}
