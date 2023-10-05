#include <stdio.h>

/**
 * This is the main function.
 * It prints the sum of the digits of a number to the console.
 * @param None
 * @return 0
 */
int main()
{
    long int num, sum = 0;
    printf("Enter a number: ");
    scanf("%ld", &num);

    if (num < 0)
    {
        num = -num;
    }

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    printf("The sum of the digits is: %ld\n", sum);
    return 0;
}