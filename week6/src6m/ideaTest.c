#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*
    * prints the sizes of various data types, in bytes, which
    * will be specific to each system architecture
    */
    printf("
        int: %d\n
        unsigned int: %d\n
        long: %d\n
        long long: %d\n
        unsigned long long: %d\n
        float: %d\n
        float* : %d\n
        double: %d\n
        double* : %d\n
        char: %d\n
        char* : %d\n
        ", 
        sizeof(int)
        sizeof(unsigned int)
        sizeof(long)
        sizeof(long long)
        sizeof(unsigned long long)
        sizeof(float)
        sizeof(float*)
        sizeof(double)
        sizeof(double*)
        sizeof(char)
        sizeof(char*)
        );
}
