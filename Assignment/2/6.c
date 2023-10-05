#include <stdio.h>

/**
 * Returns a pointer to the larger of two integers.
 *
 * @param a A pointer to the first integer
 * @param b A pointer to the second integer
 * @return a pointer to the larger integer
 */
int *maxwell(int *a, int *b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

/**
 * Swaps the values of two integer pointers.
 *
 * @param a A pointer to the first integer value
 * @param b A pointer to the second integer value
 */
void swap1(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

/**
 * Swaps the values of two integers.
 *
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 */
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int array[6] = {5, 3, 4, 17, 22, 19};
    int *ptr = maxwell(array, &array[2]);
    *ptr = -1;
    ptr += 2;
    ptr[1] = 9;
    *(array + 1) = 79;
    printf("%d\n", &array[5] - ptr);
    swap1(&array[0], &array[1]);
    swap2(array, &array[2]);
    for (int i = 0; i < 6; i++)
        printf("%d\n", array[i]);
}