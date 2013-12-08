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

        // check if the substring is not in the trie
        if(walker->children[alphaindex] == NULL)
        {
            return false;
        }
        // we must need to keep walking while not at end of word
        else
        {
            walker = walker->children[alphaindex];
        }
    }

    // if we've made it here, we may have correct word!
    return walker->is_word;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // initialize root node
    root = (node*) calloc(1, sizeof( node ));
    if(root != NULL)
    {
        root->is_word = false;
    }

    // try to open dictionary file
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        return false;
    }

    // iterate the entire dictionary file
    for(int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // prepare an iterating node
        node* walker = root;

        // iterate each character in line
        while(c != (int)'\n')
        {
            int letter = get_rel_alphaindex(c);

            // allocate space for a child node if needed
            if(walker->children[letter] == NULL)
            {
                walker->children[letter] = (node*) calloc(1, sizeof(node));

                // ensure that memory was allocated
                if(walker->children[letter] == NULL)
                {
                    return false;
                }
                
                walker->children[letter]->is_word = false;
            }
            // assign walker to the next node and move to next character
            walker = walker->children[letter];
            c = fgetc(fp);
        }
        // mark that a word has been entered and increment size
        walker->is_word = true;
        dict_size++;
    }

    fclose(fp);

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
* frees the tree of nodes, recursively, starting at index in the root node
*/
bool free_child(node* node)
{
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        // iterative case
        if(node->children[i] != NULL)
            free_child(node->children[i]);
    }
    // base case
    free(node);

    // if we made it here, all is good
    return true;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return free_child(root);
}

/**
* Gets a letter's position in alphabet relative to lowercase 'a' being index 0,
* 'z' being index 25, and "'" (apostrophe) being index 26.
*/ 
int get_rel_alphaindex(const char alpha)
{
    if(alpha == '\'')
        return 26;
    else    
        return tolower(alpha) - 'a';
}
