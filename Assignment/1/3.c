#include <stdio.h>

/**
 * This is the main function.
 * It prints a pattern to the console.
 * @param None
 * @return 0
 */
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
