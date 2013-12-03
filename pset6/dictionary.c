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

int get_rel_alphaindex(const char alpha);

typedef struct node
{
    bool is_word;
    struct node* children[ALPHABET_SIZE];
}
node;

// declare global vars
node* root;
unsigned int dict_size;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // check if the root has been initialized
    if(root == NULL)
    {
        return false;
    }
    
    node* walker = root;

    for(int i = 0, l = strlen(word); i < l; i++)
    {
        // get the alphabet index of the current character of word
        int alphaindex = get_rel_alphaindex(*(word + i));

        // check if the word is in the trie and marked as word
        if(i == l-1 && walker->is_word)
        {
            return true;
        }
        // check if the substring is not in the trie
        else if(walker->children[alphaindex] == NULL)
        {
            return false;
        }
        // we must need to keep walking
        else
        {
            walker = walker->children[alphaindex];
        }
    }

    // protect against the impossible
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
        node* old_walker;

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
                letter = get_rel_alphaindex(l);
            }

            // allocate space for a child node if needed
            if(walker->children[letter] == NULL)
            {
                walker->children[letter] = (node*) malloc(sizeof(node));

                // ensure that memory was allocated
                if(walker->children[letter] == NULL)
                {
                    return false;
                }
                
                walker->children[letter]->is_word = false;

                
            }
            // assign walker to the next node and move to next character
            old_walker = walker;
            walker = walker->children[letter];
            l = fgetc(fp);
        }
        
        // mark that a word has been entered and increment size
        old_walker->is_word = true;
        dict_size++;
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dict_size;
}

/**
* frees the tree of nodes starting at index in the root node
* and traversing down the entire trie at each index
*/
node* free_nodes(node* nodei)
{
    if(nodei->children != NULL)
    {
        for(int i = 0; i < ALPHABET_SIZE; i++)
        {
            free(free_nodes(nodei->children[i]));
        }
    }
    else
    {
        return nodei;
    }
    return NULL;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    bool unloaded = free_nodes(root);
    free(root);
    return unloaded;
}

/**
* Gets a letter's position in alphabet relative to lowercase 'a' being index 0,
* 'z' being index 25, and "'" (apostrophe) being index 26.
*/ 
int get_rel_alphaindex(const char alpha)
{
    return tolower(alpha) - 'a';
}
