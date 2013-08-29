/**
* simple program demonstrating 
* text i/o with files in C
*/

#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // open a file for writing
    FILE* fp;
    fp = fopen("ohai.txt", "w");

    // write something to the file
    fprintf(fp, "ohai world!\n"
        "I hope you like this program\n"
        "Kthxbai.\n");

    // close the file
    return fclose(fp);
}
