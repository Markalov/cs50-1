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
#include <string.h>

int main(int argc, char * argv[])
{
    printf("%d", argc);
    for(int i=0; i<argc; i++)
        for(int j=0, n=strlen(argv[i]); j<n; j++)
            printf("%c\n", argv[i][j]);
}
