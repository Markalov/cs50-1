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
#include <ctype.h>

// fn prototypes
int vigenereCipher(int p, int k);

int main(int argc, string argv[])
{
    /*
    * args should be name of prgm and a secret key 
    * secret key should be composed of all alpha 
    * chars
    */
    // ensure only one cmd line arg
    if(argc != 2)
    {
        printf("Usage: ./vigenere <alphabetic_secret_key>\n");
        return 1;
    }
    // set keyword to cmd line arg
    char* keyWord = argv[1];
    int keyWordLength = strlen(keyWord);
    // check that the cmd line arg is alphabetic
    for(int i = 0; i < keyWordLength; i++)
    {
        if(!isalpha(keyWord[i]))
        {
            printf("Usage: ./vigenere <alphabetic_secret_key>\n");
            return 1;
        }
    }
    // user inputs a string as the secret message
    char* secretMessage = GetString();
    int secretMessageLength = strlen(secretMessage);
    // apply a cipher if char in secretMessage is alphabetical
    for(int i = 0, j = i; i < secretMessageLength; i++)
    {
        /*
        * if we've surpassed keyWordLength
        * reset it's length
        */
        if(j == keyWordLength)
            j = 0;
        // don't increment b/c no cipher applied if !alphabetical
        if(!isalpha(secretMessage[i]))
        {
            printf("%c", secretMessage[i]);
        }
        else
        {
            // char is alphabetical, cipher it
            char cipheredChar = vigenereCipher(secretMessage[i], keyWord[j]);
            printf("%c", cipheredChar);
            j++;
        }
    }
    
    printf("\n"); 

}

/*
* input: 'p' a char a-z or A-Z as an int
* 'k' a char a-z or A-Z as an int
* rotates a char 'p' by 'k' places where [Aa, Zz] = [0, 25]
*/
int vigenereCipher(int p, int k)
{
    // reset 'key' char between 0,25; Aa = 0, Zz = 25
    if(k >= 65 && k <= 90)
        k -= 65;
    if(k >= 97 && k <= 122)
        k -= 97;
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
