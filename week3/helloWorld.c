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

int main(void)
{
    printf("Enter your name, pweeease: ");
    string name = GetString();
    printf("hello, %s!\n", name);
}
