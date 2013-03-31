/*************************
**************************
* helloWorld.c
*
* Computer Science 50x
* Evan Sendra
*
* performs a simple hello world
* print to the screen to demonstrate
* how C programs can be compiled and 
* made in the cs50 appliance
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*
    * performs a mathematically "dumb" test...because of
    * course 2 is greater than 1
    */
    if(2>1)
    {
        string message = "Hello world!";
        printf("%s\n", message);
    } else {
        bool result = (1>2);
        printf("%d", result);
    }
}
