#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source destination\n");
        return 1;
    }

    // TODO: copy the contents of argv[1] to argv[2]
    // open source for reading and destination for writing
    FILE* sourceFp = fopen(argv[1], "r");
    FILE* destFp = fopen(argv[2], "w");

    // check for file open success
    if(sourceFp == NULL || destFp == NULL)
    {
        printf("couldn't copy %s to %s\n", argv[1], argv[2]);
        return 1;
    }

    // read each char from source, and write it to destination
    char current;
    while((current = fgetc(sourceFp)) != EOF)
    {
        fputc(current, destFp);
    }

    // close the file pointers and free the mem
    fclose(sourceFp);
    fclose(destFp);

    return 0;
}

