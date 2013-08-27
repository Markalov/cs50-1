/**
* typewriter.c
* 
* cs50
* 
* demonstrate writing to a file
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    // ensure one and only one command line argument
    if (argc != 2)
    {
        printf("Usage: %s [name of document]\n", argv[0]);
        return 1;
    }

    // open a new document for writing
    FILE* fp = fopen(argv[1], "w");

    // check for successful open
    if(fp == NULL)
    {
        printf("Could not create %s\n", argv[1]);
        return 2;
    }

    // get text from user and save to file
    while(true)
    {
        // get text from user
        printf("Enter a new line of text (or \"quit\"):\n");
        string input = GetString();

        // if user wants to quit
        if (input != NULL && strcmp(input, "quit") == 0)
        {
            free(input);
            break;
        }
        // if user wants to enter text
        else if (input != NULL)
        {
            fputs(input, fp);
            fputs("\n", fp);
            printf("CHA-CHING!\n\n");
            free(input);
        }
    }

    // close the file and end successfuly
    fclose(fp);
    return 0;
}
