/*************************
**************************
* mario.c
*
* Computer Science 50x
* Evan Sendra
*
* builds a half pyramid of "#" blocks
* as seen in the old mario video games
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{

//put numRows too high so user will be prompted for new value
int numRows = 100;

while(numRows < 0 || numRows > 23)
{
    //numRows must be an int between 1 and 23
    printf("Height: ");
    numRows = GetInt();
}

//this loop tracks vertical iterations 
for(int i=1; i<=numRows; i++)
{
    //this loop tracks horizontal space printing
    for(int j=0; j<(numRows-i); j++)
        printf(" ");
    //this loop tracks horizontal block printing
    for(int k=0; k<(i+1); k++)
    {
        if(k==i)
            printf("#\n");
        else
            printf("#");
    }
}
//all is well
return 0;

} //end main
