/*************************
**************************
* {name_of_program}.c
*
* Computer Science 50x
* Evan Sendra
*
* {description_of_what_program_does}
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

#define ALPHA 26

int main(void)
{
    /*
    * prints the alphabet
    *
    for(int i=65, n=65+ALPHA; i<n; i++)
        printf("%c: %d\n", i, i);

    for(int i=97, n=97+ALPHA; i<n; i++)
        printf("%c: %d\n", i, i);
    */

    for(int i=0; i<255; i++)
        printf("%c: %d\n", i, i);

}
