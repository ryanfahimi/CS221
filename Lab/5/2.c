#include <stdio.h>

int sumOfHeadAndTail(int *arr, int length)
{
    int sum = *arr + *(arr + length - 1);
    return sum;
}

int sumOfLargestTwo(int *arr, int length)
{
    int *largest = arr;
    int *secondLargest = arr + 1;
    if (*secondLargest > *largest)
    {
        largest = arr + 1;
        secondLargest = arr;
    }
    for (int i = 2; i < length; i++)
    {
        if (*(arr + i) > *largest)
        {
            secondLargest = largest;
            largest = arr + i;
        }
        else if (*(arr + i) > *secondLargest)
        {
            secondLargest = arr + i;
        }
    }
    int sum = *largest + *secondLargest;
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(int);
    int sum1 = sumOfHeadAndTail(arr, length);
    int sum2 = sumOfLargestTwo(arr, length);
    printf("The sum is %d.\n", sum1);
    printf("The sum of the largest two is %d.\n", sum2);
    return 0;
}