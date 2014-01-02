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
// bool add_node(Tree* node, Tree* huff_tree);

/**
* prints a charcter to a specified file
*/
bool fprintchar(FILE* fp, char c)
{
    // print found character
    int printed = fprintf(fp, "%c", c);
    
    // return false if likely the character wasn't printed 
    return printed == 1;
}

/**
* builds a huffman tree out of a "forest", 
* defined in forest.h, passed in as an 
* argument
*/
bool build_huff_tree(Forest** f)
{
    // return early if parameters won't work
    if(f == NULL || *f == NULL)
        return false;

    Tree* first = pick(*f);
    Tree* second = pick(*f);
    
    // there should always be at least 1 tree in the forest
    if(first == NULL)
        return false;

    // if we run out of forest, we're done
    if(second == NULL)
    {
        plant(*f, first);
        return true;
    }

    // else the first tree (lowest weight) becomes the
    // left child, second tree becomes right child
    Tree* joiner = mktree();
    if(joiner == NULL)
        return false;
    joiner->left = first;
    joiner->right = second;
    joiner->frequency += (first->frequency + second->frequency);
    if(!plant(*f, joiner)) 
        return false;  
    
    return build_huff_tree(f);
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

    // check checksum and build forest
    int checksum = header.checksum;
    Forest* forest = mkforest();
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];

        if(header.frequencies[i] > 0)
        {
            Tree* tree = mktree();
            tree->symbol = i;
            tree->frequency = header.frequencies[i];
            plant(forest, tree);
        }
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        rmforest(forest);
        return 1;
    }

    // build ze huff tree out of the forest
    // Tree* huff_tree = mktree();
    if(build_huff_tree(&forest) == false)
    {
        printf("Couldn't build huff tree\n");
        // rmtree(huff_tree);
        rmforest(forest);
        return 1;
    }

    Tree* huff_tree = pick(forest);
    if(huff_tree == NULL)
    {
        printf("Couldn't build huff tree\n");
        rmforest(forest);
    }

    Tree* walker = huff_tree;
    int bit;
    while ((bit = bread(input)) != EOF)
    {
        // we've found a letter
        // FLAG
        if(walker->left == NULL && walker->right == NULL)
        {
            if(!fprintchar(output, walker->symbol))
            {
                printf("Couldn't write to %s\n", argv[2]);
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

    // one more character to write...the last character
    if(!fprintchar(output, walker->symbol))
    {
        printf("Couldn't write to %s\n", argv[2]);
        rmtree(walker);
        // rmtree(huff_tree);
        rmforest(forest);
        return 1;
    }

    // free memory
    rmtree(huff_tree);
    rmforest(forest);

    // close input and output files
    hfclose(input);
    fclose(output);

    // that's all folks!
    return 0;
}
