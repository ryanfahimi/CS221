#include <stdio.h>

/**
 * This function finds the minimum of an array.
 * @param MyArray The array to find the minimum of.
 * @param n The number of elements in the array.
 * @param pToMin A pointer to a pointer to the minimum of the array.
 * @return None
 */
void findmin(int MyArray[], int n, int **pToMin)
{
    if (n <= 0)
        return; // no items, no minimum!
    *pToMin = MyArray;
    for (int i = 1; i < n; i++)
    {
        if (MyArray[i] < **pToMin)
            *pToMin = MyArray + i;
    }
}

/**
 * This is the main function.
 * It prints the minimum of an array to the console.
 * @param None
 * @return 0
 */
int main(void)
{
    int nums[4] = {45, 13, 5, 66};
    int *p;
    findmin(nums, 4, &p);
    printf("The minimum is at address %p\n", p);
    printf("It's at position %ld\n", p - nums);
    printf("Its value is %d\n", *p);
}