#include <stdio.h>

/**
 * This program demonstrates the behavior of short int data type when it overflows.
 * It initializes myVar with a value that exceeds the maximum value that can be stored in a short int.
 * It then initializes myVar with a value that is within the range of a short int.
 * Finally, it prints the values of myVar to the console.
 * @param None
 * @return 0
 */
int main()
{
    short int myVar;
    myVar = 10000 * 10000;
    printf("%d\n", myVar);
    myVar = 1000 * 1000;
    printf("%d\n", myVar);
    return 0;
}
