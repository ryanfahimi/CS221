#include <stdio.h>

/**
 * This is the main function.
 * It prints the factorial of a number to the console.
 * @param None
 * @return 0
 */
int main()
{
    int n, factorial = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    printf("The Factorial of %d is: %d\n", n, factorial);
    return 0;
}
