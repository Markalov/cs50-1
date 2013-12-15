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

int main(void)
{
    node node9 = {9, NULL, NULL};
    node node6 = {6, NULL, NULL};
    node node3 = {3, NULL, NULL};
    node node7 = {7, NULL, NULL};

    node7.left = &node3;
    node7.right = &node9;
    node3.right = &node6;
}

bool conatins(int value)
{
    // TODO
}
