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
float divide(int numerator, int denominator);

#include <stdio.h>
#include <cs50.h>

int main(void)
{

}

float divide(int numerator, int denominator)
{
    // if user gives us bad input
    while(numerator<=0 && denominator>0)
    {
    printf("non-negative numerator: ");
    numerator = GetInt();
    printf("positive denominator: ");   
    denominator = GetInt();                                    
    }
    // when user gives us good input
    float quotient = (numerator/denominator);
    return quotient;
}
