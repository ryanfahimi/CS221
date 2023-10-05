#include <stdio.h>

/**
 * This function computes the cube of a number.
 * @param n The number to be cubed.
 * @param ncubed The pointer to the result.
 * @return None
 */
void computeCube(int n, int *ncubed)
{
    *ncubed = n * n * n;
}

/**
 * This is the main function.
 * It prints the cube of a number to the console.
 * @param None
 * @return 0
 */
int main(void)
{
    int result;
    int *ptr = &result;
    computeCube(5, ptr);
    printf("Five cubed is %d\n", result);
    return 0;
}