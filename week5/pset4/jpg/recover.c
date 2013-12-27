/****************************************************************************
* recover.c
*
* Computer Science 50
* Problem Set 4
*
* Recovers JPEGs from a forensic image.
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

/**
* define a structure with 4 bytes - the amount of 
* space taken up by a jpg signature
*/ 
typedef uint8_t BYTE;

/**
* define the signature of a section of (512) bytes
*/ 
typedef struct
{
    BYTE zero;
    BYTE one;
    BYTE two;
    BYTE three;
}
SIGNATURE;

int main(void)
{
    // open the memory card file
    FILE* memcard = fopen("card.raw", "r");
    if(memcard == NULL)
    {
        fclose(memcard);
        fprintf(stderr, "Could not read from memcard file\n");
        return 1;
    }

    // file signature of the section of (512) bytes
    SIGNATURE sectionSig;

    // the current jpg file we'll write jpg data to
    FILE* jpgFile;

    // 508 bytes which won't (likely) be a signature
    char buffer[508];

    // count the jpgs found
    int jpgCount = 0;

    // tells if we've started collecting jpgs
    bool foundJpg = false;

    // do for each section of bytes (buffer)
    while(fread(&sectionSig, sizeof(SIGNATURE), 1, memcard) > 0)
    {
        char* jpgName = malloc(sizeof(char) * 8);

        // read the rest of the section of 512 bytes into the buffer
        // no matter what
        fread(&buffer, 508, 1, memcard);

        // is this the start of a jpg?
        if(sectionSig.zero == 0xff && sectionSig.one == 0xd8 &&
            sectionSig.two == 0xff && (sectionSig.three == 0xe0 ||
            sectionSig.three == 0xe1))
        {
            foundJpg = true;
            
            // close the file, if we were writing to one previously
            if(jpgCount != 0)
                fclose(jpgFile);

            // try to open a jpg file named ###.jpg
            sprintf(jpgName, "%03d.jpg", jpgCount++);
            jpgFile = fopen(jpgName, "w");
            if(jpgFile == NULL)
            {
                fclose(jpgFile);
                fprintf(stderr, "Could not write %s.jpg\n", jpgName);
                return 2;
            }

            // write the first 4 bytes
            fwrite(&sectionSig, sizeof(SIGNATURE), 1, jpgFile);
            // write the next 508 bytes of the section
            fwrite(&buffer, 508, 1, jpgFile);
        }
        // have we already found a jpg? are we at the end of the photos?
        else if(foundJpg && jpgCount <= 51)
        {
            // recreate name of the jpg file
            sprintf(jpgName, "%03d.jpg", jpgCount);

            if(jpgFile == NULL)
            {
                fclose(jpgFile);
                fprintf(stderr, "Could not write %s\n", jpgName);
                return 3;
            }
            
            // write all 512 bytes to the file under jpgName
            fwrite(&sectionSig, sizeof(SIGNATURE), 1, jpgFile);
            fwrite(&buffer, 508, 1, jpgFile);
        }

        // free mem for jpgName string
        free(jpgName);
    }
    // ensure the last jpg is closed
    fclose(jpgFile);

    // close the mem card file
    fclose(memcard);
}
