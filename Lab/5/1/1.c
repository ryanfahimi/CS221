#include <stdio.h>

/**
 * This is the main function.
 * It declares three integer variables and three integer pointers.
 * It initializes the integer variables with values 5, 6 and 12.
 * It initializes the integer pointers with the addresses of the integer variables.
 * It then calculates the sum of the values of the integer variables using the integer pointers.
 * Finally, it prints the sum to the console.
 * @param None
 * @return 0
 */
int main()
{
    int a = 5;
    int b = 6;
    int c = 12;

    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    int sum = *p1 + *p2 + *p3;

    printf("The sum is: %d", sum);

    return 0;
}