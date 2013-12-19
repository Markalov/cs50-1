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

struct list
{
    node* n;
    struct list* next;
};

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

bool insert(int value, node** tree)
{
    // passed in NULL
    if(tree == NULL)
        return false;
    // passed in node* whose value is NULL
    if(*tree == NULL)
    {
        *tree = build_node(value);
        return *tree != NULL;
    }
    return insert(value, value < (*tree)->value 
        ? &(*tree)->left : &(*tree)->right);
}

/*
bool contains(int value, node* tree)
{
    if(tree == NULL)
        return false;
    if(tree->value == value)
        return true;
    return contains(value, tree->left) || 
        contains(value, tree->right);
}
*/

bool contains(int value, node* tree)
{
    node* cur;
    struct list* list = malloc(sizeof(list));
    list->n = tree;
    list->next = NULL;

    while(list != NULL)
    {
        cur = list->n;
        list = list->next;
        if(cur->value == value)
            return true;
        if(cur->right != NULL)
        {
            struct list* new_list = malloc(sizeof(list));
            new_list->n = cur->right;
            new_list->next = list;
            list = new_list;
        }
        if(cur->left != NULL)
        {
            struct list* new_list = malloc(sizeof(list));
            new_list->n = cur->left;
            new_list->next = list;
            list = new_list;
        }
    }
    return false;
}

int main(void)
{
    node* node9 = build_node(9);
    node* node7 = build_node(7);
    node* node6 = build_node(6);
    node* node3 = build_node(3);
    node* node8 = build_node(8);
    node* node5 = build_node(5);
    node* node2 = build_node(2);

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
        
    node* root = node7;
    for(int i=0; i<10; i+=2)
    {
        printf("Inserting...%d...%s\n", i, 
            insert(i, &root) ? "OK" : "BAD");
    }

    // prints if tree contains 6
    for(int i=0; i<10; i++)
        printf("Tree contains %d? %d\n", i, contains(i, root));

    free(node9);
    free(node7);
    free(node6);
    free(node3);
}
