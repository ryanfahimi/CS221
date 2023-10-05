#include <stdio.h>

/**
 * This function returns the maximum number in an array.
 * @param arr The array
 * @param len The length of the array
 * @return The maximum number in the array
 */
int maxInArray(int *arr, int len)
{
    int max = *arr;
    for (int i = 1; i < len; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}

int main()
{
    int array[3] = {10, 20, 30};

    int max = maxInArray(array, 3);
    printf("The maximum number in the array is: %d", max);

    return 0;
}