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

// function prototypes
int square(int x);

int main(void)
{
    printf("%d\n", square(2));
}

// write the function
int square(int x)
{
    return x*x;
}
