/*************************
**************************
* caesar.c
*
* Computer Science 50x
* Evan Sendra
*
* implements the caesar cipher, which is 
* algorithmically stated as c = (p+k) % 26, 
* to a command line argument
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

// fn prototypes
int rotate(int p, int k);

int main(int argc, string argv[])
{



}

/*
* input: a char a-z or A-Z
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
            p = 65+(sum-90);
            return p;
        }
        // if sum !exceed 90, no need to reset
        else
            return p;
    }
}
