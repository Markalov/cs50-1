#include <stdio.h>
#define SIZE 8

void sort(int array[], int size)
{
    // loop through unsorted portion and put into proper place in sorted portion
    for(int i=1; i<size-1; i++)
    {
        int j;
        // keep track of current element
        int element = array[i];
        // loop from current element down to spot where either 
        // j=0 or the element is bigger than the next spot to the
        // left
        for(j=i; j>0 && array[j-1] > element; j--)
        {
            // shift elements one spot to the left
            array[j] = array[j-1];
        }
        // the element is now in the right position at the j-th
        // index
        array[j] = element;
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
