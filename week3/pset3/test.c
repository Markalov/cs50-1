#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

bool lookup(string s, string dictionary[], int dSize);

int main(int argc, char *argv[])
{
    string arr[] = {"bar", "baz","blah","cowbell","eel","foo","qux"};
    /*
    for(int i=0; i<sizeof(arr)/sizeof(string); i++)
        printf("%s\n", arr[i]);
    */
    if(lookup("bark", arr, 7))
        printf("TRUE\n");
}

/**
 * Looks up word, s, in dictionary.  Iff found (for the first time), flags word
 * as found (so that user can't score with it again) and returns true.
 */
bool lookup(string s, string dictionary[], int dSize)
{
    // conditional on whether or not word is found
    bool isFound = false;

    // ensure the user has typed something ok to lookup
    if(s == NULL || strlen(s) < 1)
        return isFound;

    // initially, min is 0 and max is size of dictionary less 1
    int min = 0;
    int max = dSize-1;

    // lookup word in dictionary array using binary search
    while(max >= min)
    {
        int midpoint = (max-min)/2.0;
        int compare = strcmp(s, dictionary[midpoint]);

        if(compare < 0)
        {
            // the string is less than the current midpt
            max = midpoint - 1;
        }
        else if(compare > 0)
        {
            // the string is greater than the current midpt
            min = midpoint + 1;
        }
        else
        {
            // the string is equal to the current midpt
            isFound = true;
            return isFound;
        }
    }
    return isFound;
}

    /*
    int min = 0;
    int max = dSize-1;
    int midpoint = (max-min)/2.0;
   
    bool wordFound = false;

    bool charFound = false;
    bool lower = false;
    bool higher = false;
    while(max >= min)
    {
                
        // if the last character was found, the word was found
        if(charFound)
            wordFound = true;
        else if(lower)
            max = midpoint-1;
        else if(higher)
            min = midpoint+1;
        // reset the midpoint
        midpoint = round((max-min)/2.0);
        string current = dictionary[midpoint];

        bool charFound = false;
        bool lower = false;
        bool higher = false;


        for(int c=0, l=strlen(s); c<l; c++)
        {
            // check if the input word is logically lower in order
            if(current[c] > s[c])
            {
                // move the range lower
                lower = true;
            }
            // check if the input word is logically higher in order
            else if(current[c] < s[c])
            {
                // move the range higher
                higher = true;
            }
            // the current dictionary word and s still match
            else
            {
                charFound = true;
            }
        }
    }
    return wordFound;
    */

