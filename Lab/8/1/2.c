#include <stdio.h>

/**
 * Converts an integer to a string representation recursively.
 *
 * @param n The integer to be converted.
 * @param result The buffer to store the resulting string.
 * @param base The base to be used for the conversion.
 * @return A pointer to the resulting string.
 */
char *recursiveIntToString(int n, char *result, int base)
{
    if (n == 0)
    {
        *result = '\0'; // terminate the string
        return result;
    }
    else
    {
        int current_digit = n % base;
        *result = current_digit + '0'; // convert digit to character
        return recursiveIntToString(n / base, result + 1, base);
    }
}

int main()
{
    char result1[10];
    char result2[10];

    recursiveIntToString(100, result1, 10);
    recursiveIntToString(100, result2, 8);

    printf("Number 100 in base 10: %s\n", result1); // 001
    printf("Number 100 in base 8: %s\n", result2);  // 441

    return 0;
}
