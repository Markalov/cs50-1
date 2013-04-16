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

int len(string input)
{
    int i=0;
    while(input[i] != '\0')
       i++;
    return i;
}

int main(void)
{
    printf("Give me a string: ");
    string s = GetString();

    printf("The length is: %d\n", len(s));
    return 0;
}
