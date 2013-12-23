#include <stdio.h>

int main(void)
{
    for(int i=0; i < 5; ++i)
        printf("%c", (char) 32); // should print a space
    printf("\n\n");
}
