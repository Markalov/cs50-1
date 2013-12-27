/*************************
**************************
* swap_function.c
*
* Computer Science 50x
* Evan Sendra
*
* demonstrates pointers by swapping two
* values in a function
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

void swap(int* a, int* b);

int main(void)
{
    int x = 3;
    int y = 5;
    printf("x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("Swapped!\n");
    printf("x: %d, y: %d\n", x, y);
}

void swap(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

/*
void swap(int a, int b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
*/
