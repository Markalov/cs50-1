/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

#define ALPHABET_SIZE 27

typedef struct node
{
    bool is_word;
    struct node* children[ALPHABET_SIZE];
}
node;

node* root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // initialize root node
    root = (node*) malloc(sizeof( node ));
    if(root != NULL)
    {
        root->is_word = false;
    }

    // try to open dictionary file
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        printf("Could not load %s\n", dictionary);
        return false;
    }

    // iterate the entire dictionary file
    for(int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // prepare an iterating node 
        node* walker = root;

        // iterate each character in line
        int l = c;
        while(l != (int)'\n')
        {
            int letter;
            if(l == '\'')
            {
                letter = 26;
            }
            else
            {
                letter = tolower(l) - 'a';
            }

            // allocate space for a child node if needed
            if(walker->children[letter] == NULL)
            {
                walker->children[letter] = (node*) malloc(sizeof(node));

                // ensure that memory was allocated
                if(walker->children[letter] == NULL)
                {
                    printf("Seemed to run out of memory loading %s\n", dictionary);
                    return false;
                }
                
                walker->children[letter]->is_word = false;

                
            }
            // assign walker to the next node and move to next character
            walker = walker->children[letter];
            l = fgetc(fp);
        }
        walker->is_word = true;
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
