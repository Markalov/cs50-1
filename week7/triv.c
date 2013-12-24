#include <stdio.h>

void swap(int* x, int*y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void)
{
    int x = 1;
    int y = 25;
    printf("x is %d; y is %d\n\n", x, y);
    swap(&x, &y);
    printf("x is %d; y is %d\n\n", x, y);
}
