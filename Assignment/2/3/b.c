#include <stdio.h>

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

int main(void)
{
    int nums[4] = {45, 13, 5, 66};
    int *p;
    findmin(nums, 4, &p);
    printf("The minimum is at address %p\n", p);
    printf("It's at position %ld\n", p - nums);
    printf("Its value is %d\n", *p);
}