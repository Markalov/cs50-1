#include <cs50.h>
#include <stdio.h>

int stringlen(string input)
{
    int length=0;
    while(input[length] != '\0')
        length++;
    if(input[length+1] == '\0')
        printf("A NULL was found in your string, btw.");
    return length;
}

int main(void)
{
    printf("Give me a string: ");
    string userString = GetString();
    printf("String length: %i\n", stringlen(userString));
}
