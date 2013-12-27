#include <stdio.h>
#include <cs50.h>
#include <limits.h>

// prototype
long long int factorial(int);

int main(void)
{
    printf("Give me a number: ");
    int x = GetInt();
    long long int f = factorial(x);
    long long int result = (f>LLONG_MAX || f<0 ? -1 : f);
    if(x < 0)
        printf("Factorials less than 0 undefined.\n");
    else
        printf("%lld\n", result);
}

long long int factorial(int n)
{
    if(n < 1)
    {
        return 1;
    }
    else 
    {
        return (long long int)n * factorial(n-1);
    }
}
