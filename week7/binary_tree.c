#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}
node;

bool contains(int value);

node* root;

int main(void)
{
    root = (node*) malloc(sizeof( node ));
    root->val = 7;
    root->left = (node*) malloc(sizeof( node ));
    root->left->val = 3;
    root->right = (node*) malloc(sizeof( node ));
    root->right->val = 9;
    root->left->right = (node*) malloc(sizeof( node ));
    root->left->right->val = 6;
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
}

bool conatins(int value)
{
    // TODO
}
