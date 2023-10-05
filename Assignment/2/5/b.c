#include <stdio.h>

/**
 * This function returns the pointer to the first occurrence of a character in a string.
 * @param str The string
 * @param chr The character
 * @return The pointer to the first occurrence of the character in the string
 */
const char *findTheChar(const char *str, char chr)
{
    for (int k = 0; *(str + k) != '\0'; k++)
    {
        if (*(str + k) == chr)
        {
            return (str + k);
        }
    }
    return NULL;
}

int main(void)
{
    const char *ptr = findTheChar("Hello, world!", 'w');
    if (ptr != NULL)
        printf("Found the character: %c\n", *ptr);
    else
        printf("The character was not found.\n");
    return 0;
}