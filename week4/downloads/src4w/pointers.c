/****************************************************************************
 * pointers.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Prints a given string one character per line.
 *
 * Demonstrates pointer arithmetic.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // get line of text
    // remember s is just the memory address of the first byte
    // in the "string" s
   char* s = GetString();
    if (s == NULL)
        return 1;
 
    // print string, one character per line
    for (int i = 0, n = strlen(s); i < n; i++)
        printf("%c\n", *(s+i));
    
    // free string
    free(s);

    return 0;
}
