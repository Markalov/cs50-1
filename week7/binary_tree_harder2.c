#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
}
node;

/*
bool contains(int value, node* tree)
{
    if(tree == NULL)
        return false;

    if(value < tree->value)
        return contains(value, tree->left);
    else if(value > tree->value)
        return contains(value, tree->right);
    else
        return true;
}
*/

node* build_node(int value)
{
    node* node = malloc(sizeof( node ));
    if(node == NULL)
        return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
* declaring insert passing in a dbl ptr allows us to modify
* the address of tree...which means that if node* is NULL
* but node** isn't, we can change the node* to be the value 
* to which node** points.  We CANT modify what tree points
* to if we don't pass in by address, as we do here.
*/
bool insert(int value, node** tree)
{
    // ptr to ptr is NULL, aka the parameter tree == 'NULL'
    // in other words, node ** tree doesn't exist
    if(tree == NULL)
        return false;

    // TODO finish
    // ptr is NULL, aka it exists but pts to NULL
    /*
    * base case
    */
    if(*tree == NULL) 
    {
        *tree = build_node(value);
        if(*tree == NULL)
            return false;
        return true;
    }

    /*
    * recursive case
    */
    return insert(value, value < (**tree).value ? &(**tree).left : &(**tree).right);
    /*
    if(value < (*tree)->value) // or (**tree).value
    {
        return insert(value, &(**tree).left);
    }
    else
    {
        return insert(value, &(**tree).right);
    }
    */
}

bool contains(int value, node* tree)
{
    return tree != NULL && (value == tree->value ||
        (value < tree->value ? contains(value, tree->left) :
        contains(value, tree->right)));
}

int main(void)
{
/*  
    node* node9 = build_node(9);
    node* node7 = build_node(7);
    node* node6 = build_node(6);
    node* node3 = build_node(3);
    node* node8 = build_node(8);
    node* node5 = build_node(5);
    node* node2 = build_node(2);
*/

    if(!node9 || !node7 || !node6 || !node3 ||
        !node8 || !node5 || !node2)
    {
        printf("malloc failed\n");
        return 1;
    }

/*
    node7->left = node3;
    node7->right = node8;
    node8->right = node9;
    node3->left = node2;
    node3->right = node5;
    node5->right = node6;
*/
        
    // node* root = node7;
    node* root = NULL;
    for(int i=0; i<10; i+=2)
    {
        printf("Inserting...%d...%s", i, 
            insert(i, &root) ? "OK" : "BAD");
    }

    // prints if tree contains 6
    for(int i=0; i<10; i++)
        printf("Tree contains %d? %d\n", i, contains(i, root));

/*
    free(node9);
    free(node7);
    free(node6);
    free(node3);
*/
}
