/*************************
**************************
* vigenere.c
*
* Computer Science 50x
* Evan Sendra
*
* implements the vigenere cipher, which is 
* algorithmically stated as c = (p+k[char]) % 26, 
* to a command line argument
**************************
*************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

// fn prototypes
int rotate(int p, int k);

int main(int argc, string argv[])
{
    /*
    * args should be name of prgm and a secret key 
    * secret key should be a digit but no error
    * checking for if(key isdigit)
    */
    if(argc != 2)
    {
        printf("Usage: ./caesar <secret_key>\n");
        return 1;
    }
    // set k for the cipher to the cmd line arg 
    int key = atoi(argv[1]);
    string secretMessage = GetString();
    int length = strlen(secretMessage);
    // cipher each character from 0 to end of string
    for(int i = 0, n = length; i < n; i++)
    {
       int originalChar = (int)secretMessage[i]; 
       char currentChar = rotate(originalChar, key); 
       // rotate secretMessage with casesar cipher
       printf("%c", currentChar);
    }
    printf("\n");
}

/*
* input: a char a-z or A-Z as an int
* rotates a char 'p' by 'k' places
*/
int rotate(int p, int k)
{
    // returns unmanipulated input if !a-z or !A-Z
    if(p < 65)
        return p;
    if(p > 90 && p < 97)
        return p;
    if(p > 122)
        return p;
    // set secret key 'k' between [0,25]
    k = k % 26;
    // add key to initial char 'p'
    int sum = p + k;
    // case 1: p[65,90] [A-Z]
    if(p >= 65 && p <= 90)
    {
        // if sum exceeds 90, reset to 65
        if(sum > 90)
        {
            sum = 64+(sum-90);
            return sum;
        }
        // if sum !exceed 90, no need to reset
        else
            return sum;
    }
    // case 2: p[97,122] [a,z]
    if(p >= 97 && p <= 122)
    {
        // if sum exceeds 122, reset to 97
        if(sum > 122)
        {
            sum = 96+(sum-122);
            return sum;
        }
        // if sum !exceed 122, no need to reset
        else 
            return sum;
    }
    // last resort error code 126 which is ~ as %c
    return 126;
}
