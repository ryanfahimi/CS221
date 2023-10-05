#include <stdio.h>

/**
 * This is the main function.
 * It declares a character array of size 100.
 * It then reads a string from the console and stores it in the character array.
 * It then modifies the second character of the character array.
 * Finally, it prints the modified character array to the console.
 * @param None
 * @return 0
 */
int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    *(str + 1) = '@';

    printf("The modified string is: %s", str);

    return 0;
}