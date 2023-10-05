#include <stdio.h>

/**
 * This function returns the sum of first and third element of an array.
 * @param arr The array
 * @return The sum of first and third element of the array
 */
int sumFirstAndThird(int arr[])
{
    return arr[0] + arr[2];
}

/**
 * This function returns the sum of elements of an array from start to end index.
 * @param arr The array
 * @param start The start index
 * @param end The end index
 * @return The sum of elements of the array from start to end index
 */
int sumSubarray(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * This function returns the sum of elements of the maximum subarray of an array.
 * @param arr The array
 * @param size The size of the array
 * @return The sum of elements of the maximum subarray of the array
 */
int sumMaxSubarray(int arr[], int size)
{
    int maxSum = arr[0];
    int currentSum;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            currentSum = sumSubarray(arr, i, j);
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main(void)
{
    int arr[6] = {1, -3, 2, 9, -2, 10};

    int size = sizeof(arr) / sizeof(arr[0]);

    if (size < 3)
    {
        printf("Array has less than three elements.\n");
        return 0;
    }

    printf("Sum of first and third element: %d\n", sumFirstAndThird(arr));
    printf("Sum of subarray: %d\n", sumSubarray(arr, 1, 3));
    printf("Sum of max subarray: %d\n", sumMaxSubarray(arr, size));

    return 0;
}
