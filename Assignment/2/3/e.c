#include <stdio.h>

/**
 * This function returns a pointer to an array.
 * @param m A pointer to an integer
 * @return A pointer to an array
 */
int *getPtrToArray(int *m)
{
    static int anArray[5] = {5, 4, 3, 2, 1}; // declare anArray as a static variable
    *m = 5;
    return anArray;
}

/**
 * This function does nothing.
 * @param None
 * @return None
 */
void f()
{
    int junk[100];
    for (int k = 0; k < 100; k++)
        junk[k] = 123400000 + k;
}

int main(void)
{
    int n;
    int *ptr = getPtrToArray(&n);
    f();
    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);
    printf("\n");
    return 0;
}