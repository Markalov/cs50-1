#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat filename [filename ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        // TODO: open argv[i] and print its contents to stdout

        // open argv[i]
        FILE* fp = fopen(argv[i], "r");
        // check for successful file open
        if(fp == NULL)
        {
            printf("Couldn't read from %s\n", argv[i]);
        }
        else
        {
            // read the file, char-by-char
            char current;
            while((current = (char)fgetc(fp)) != EOF)
            {
                printf("%c", current);
            }
        }
        // close the file pointer
        fclose(fp);
    }

    return 0;
}

