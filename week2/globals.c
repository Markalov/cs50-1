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

// globals 
int test = 3;

int main(void)
{
    int test = 4;
   printf("%d\n", test); 
}

void foo(void)
{
    printf("%d\n", test);
}
