#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10

int hash_function(char* key);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./hash_table_prac [key] \n");
        return 1;
    }
    
    // hash the cmd-line input
    printf("%d\n", hash_function(argv[1]));
}

int 
hash_function(char* key)
{
    int sum = 0;
    // add ASCII values of all chars
    for(int i=0, l=strlen(key); i < l; i++)
    {
        printf("Sum of ascii for %c = %d + %d\n", key[i], sum, 
            tolower((int)key[i])-'a');
        sum += tolower((int)key[i]) - 'a';
    }
    return sum % SIZE;
}
