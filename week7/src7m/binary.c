/****************************************************************************
 * binary.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Displays a number in binary.
 *
 * Demonstrates bitwise operators.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for number
    int n;
    do
    {
        printf("Non-negative integer please: ");
        n = GetInt();
    }
    while (n < 0);

    // print number in binary
    /**
    * prints num in binary by literally moving a 1 from 
    * bit 31 down to bit 0 (left to right) and asking if
    * there exists a 1 in the original number n by b.w.
    * ANDing the number with the mask which has just the 1
    * bit on at a time
    */
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        int mask = 1 << i; // shifts 1 b.w. to left i times
        if (n & mask)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    // that's all folks
    return 0;
}
