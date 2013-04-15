/*************************
**************************
* {name_of_program}.c
*
* Computer Science 50x
* Evan Sendra
*
* {description_of_what_program_does}
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

// define constants
#define N 10000

int main(void)
{
   // bracket type array
   int x[N];

   // pointer type array
   // int *x = malloc(sizeof(int) * N);

   for(int i=0; i<N; i++)
   {
        x[i] = i*i;
        printf("%d\n", x[i]);
   }
}
