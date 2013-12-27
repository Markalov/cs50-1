/****************************************************************************
 * string1.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Prints a given string one character per line.
 *
 * Demonstrates strings as arrays of chars and use of strlen.
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get line of text
    string s = GetString();

    // print string, one character per line
    for (int i = 0, l=strlen(s); i < l; i++)
    {
        // char c = s[i];
        printf("%c\n", s[i]);
    }

    return 0;
}
