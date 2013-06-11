/*************************
**************************
* rand.c
*
* Computer Science 50x
* Evan Sendra
*
* plays with the C random function
**************************
*************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    printf("%d\n", RAND_MAX);
    for(int i=0; i<10; i++)
        printf("%d: %d\n", i, rand());
}
