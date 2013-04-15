/*************************
**************************
* greedy.c
*
* Computer Science 50x
* Evan Sendra
*
* prints the minimum amount of coins to give back 
* to user for a varied purchase amount 
**************************
*************************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
float amount = -1.0;
//ensure that user gives positive amount
while(amount < 0)
{
printf("How much change is owed?\n");
amount = GetFloat();
}

//convert amount to just cents
int dollars = (int)amount;
int changeFromDollars = dollars*1e2;
float cents = amount - dollars;
int changeFromCents = round(1e2*cents);
int change = changeFromDollars + changeFromCents;

//figure out minimum coins to give to user
int coins = 0;

while(change >= 25)
{
    change -= 25;
    coins++;
}
while(change >= 10)
{
    change -= 10;
    coins++;
}
while(change >= 5)
{
    change -= 5;
    coins++;
}
while(change >= 1)
{
    change --;
    coins++;
}

printf("%i\n", coins);
return 0;

}
