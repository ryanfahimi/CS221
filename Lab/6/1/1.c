#include <stdio.h>

/**
 * This function reverses an array.
 * @param arr The array
 * @param length The length of the array
 * @return None
 */
void reverseArray(int *arr, const int length)
{
    int *pStart = arr;
    int *pEnd = arr + length - 1;
    while (pStart < pEnd)
    {
        int temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++;
        pEnd--;
    }
}

int main(void)
{
    int array[15];
    int len = sizeof(array) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        array[i] = i;
    } // Now the array is [0, 1, 2 ... 14]
    reverseArray(array, len);
    printf("The reversed array is ");
    for (int i = 0; i < len; ++i)
    {
        printf("%d", array[i]);
        if (i != len - 1)
        {
            printf(", ");
        }
        else
        {
            printf(".\n");
        }
    } // the output array should be 14, 13, 12 ... 0
    return 0;
}
