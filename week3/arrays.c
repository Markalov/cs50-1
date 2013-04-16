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

#define LAST 100 

int main(void)
{
    float foo[LAST];
    for(int i=0; i<LAST; i++)
        printf("%f\n", foo[i]);
}
