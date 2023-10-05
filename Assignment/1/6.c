#include <stdio.h>

/**
 * This function calculates the greatest common divisor of two numbers.
 * @param a The first number
 * @param b The second number
 * @return The greatest common divisor of the two numbers
 */
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

/**
 * This is the main function.
 * It prints the greatest common divisor of two numbers to the console.
 * @param None
 * @return 0
 */
int main()
{
    int a, b;
    printf("Enter the first number : ");
    scanf("%d", &a);
    printf("Enter the second number : ");
    scanf("%d", &b);

    int result = gcd(a, b);
    printf("The greatest common divisor of %d and %d is %d\n", a, b, result);
    return 0;
}
