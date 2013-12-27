#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}
node;

// make a reference to the head node
node* head = NULL;

// functions
bool add(node* node)
{
    // check if the list is empty
    if(head == NULL)
    {
        if(node != NULL)
        {
            head = node;
            return true;
        }
        else
            return false;
    }
    else
    {
        // traverse to empty spot in the list
        node* crawler = head;
        while(crawler->next != NULL)
        {
            crawler = crawler->next;
        }
        crawler->next = node;
        return true;
    }
}

// TODO find out best way to make a linkedlist structure with functions
// i.e. probably not best to do this in main
