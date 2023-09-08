#include <stdio.h>

int sumFirstAndThird(int arr[])
{
    return arr[0] + arr[2];
}

int sumSubarray(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

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
