#include <stdio.h>
#include <cs50.h>

// convert celcius to farenheit
float c_to_f(float c)
{
    float deg_farenheit = ((1.8*c)+32);
    return deg_farenheit;
}

int main(void)
{
    printf("C: ");
    // get temperature in degrees celcius
    float deg_celcius = GetFloat();
    float deg_farenheit = c_to_f(deg_celcius);
    printf("F: %2.1f\n", deg_farenheit);
    return 0;
}
