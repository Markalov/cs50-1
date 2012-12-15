/*
*
* Evan Sendra
* cs50x
* Pset 1 -- division
* 
* Asks a user for a non-negative numerator & positive denominator and performs division.
*
*/

//function prototypes
float divide(float numerator, float denominator);

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // make vars bad values initially so user will be asked for new ones
    float numerator = 0;
    float denominator = 0;
    // if user gives us bad input
    while(numerator<=0)
    {
    printf("non-negative numerator: ");
    numerator = GetFloat();                                 
    }
    while(denominator<=0)
    {
    printf("positive denominator: ");
    denominator = GetFloat();
    }
    // user has given good input
    float quotient = divide(numerator, denominator);
    string percent_sign = "%";
    printf("%.2f%s\n", quotient, percent_sign);
}

// divide two positive integers and return a percentage
float divide(float numerator, float denominator)
{
    // when user gives us good input
    float quotient = (numerator/denominator);
    float percentage = quotient*100;
    // note that the return value won't have a percent symbol or any formatting 
    return percentage;
}
