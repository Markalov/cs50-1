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
    if(lookup("bar", arr, 7))
        printf("TRUE\n");
}

/**
 * Looks up word, s, in dictionary.  Iff found (for the first time), flags word
 * as found (so that user can't score with it again) and returns true.
 */
bool lookup(string s, string dictionary[], int dSize)
{
    // ensure the user has typed something ok to lookup
    if(s == NULL || strlen(s) < 1)
        return false;

    // lookup word in dictionary array using binary search
    int min = 0;
    int max = dSize-1;
    int midpoint;
   
    bool wordFound = false;
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
} 
