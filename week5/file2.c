/**
* simple C program demonstrating how
* to read an entire text file
*/

#include <stdio.h>
#include <stdlib.h>

#define filename "ohai.txt"

int main(void)
{
    // open a file for reading
    FILE* fp = fopen(filename, "r");

    // check for successful open
    if(fp == NULL)
    {
        printf("couldn't open %s\n", filename);
        return 1;
    }

    // size of each line
    char output[256];

    // read from the file
    while(fgets(output, sizeof(output), fp) != NULL)
    {
        printf("%s", output);
        printf("\n\n%d\n", sizeof(output));
    }
    
    // report the error if we didn't reach the end of file
    if(!feof(fp))
    {
        printf("couldn't read entire file\n");
        fclose(fp);
        return 1;
    }

    // close the file
    fclose(fp);
    return 0;
}
