/*************************
**************************
* this_old_man.c
*
* Computer Science 50x
* Evan Sendra
*
* prints a variation of the good 
* "This Old Man, he played..." song
**************************
*************************/

#include <stdio.h>
#include <cs50.h>

// fn prototypes
void verse(char* number, char* onMy);

int main(void)
{

// variables of the song
char* numbers[10];
char* items[10];

// set numbers of the song
numbers[0] = "one";
numbers[1] = "two";
numbers[2] = "three";
numbers[3] = "four";
numbers[4] = "five";
numbers[5] = "six";
numbers[6] = "seven";
numbers[7] = "eight";
numbers[8] = "nine";
numbers[9] = "ten";

// set items for the song
items[0] = "thumb";
items[1] = "shoe";
items[2] = "knee";
items[3] = "door";
items[4] = "hive";
items[5] = "sticks";
items[6] = "heaven";
items[7] = "gate";
items[8] = "spine";
items[9] = "again";

// loop thru da song
for(int i=0; i < 10; i++)
    verse(numbers[i], items[i]);

printf("That's all folks!\n");
return 0;

}

/*
* prints a verse of the "This Old Man" jingle
* depending upon the number given and the 
* item on which the old man played
*/
void verse(char* number, char* item)
{
    printf("This old man, he played %s\n", number);
    printf("He played knick-knack on my %s\n", item);
    printf("Knick-knack paddywhack, give your dog a bone\n");
    printf("This old man came rolling home!\n\n");
}
