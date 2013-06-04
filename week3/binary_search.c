#include <cs50.h>
#include <math.h>
#include <stdio.h>
// define constants
#define SIZE 8

bool search(int needle, int haystack[], int size)
{
    // vars for first iteration
    int min = 0;
    int max = size-1;
    int midpoint = round((max/2.0));

    // search as long as [min, max] is not empty
    while(max >= min)
    {
            // adjust midpoint at each iteration
            midpoint = min+round((max-min)/2.0);
           
            if(needle < haystack[midpoint]) 
            {
                // make midpoint new max of range
                max = midpoint-1;
            }
            else if(needle > haystack[midpoint])
            {
                // make midpoint new min in range
                min = midpoint+1;
            }
            else
            {
                // must have found the needle
                return true;
            }
   }

    // haven't returned true, so return false
    return false;
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;
}
