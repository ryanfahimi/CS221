#include <stdio.h>

const char *findTheChar(const char *str, char chr)
{
    while (*str != '\0')
    {
        if (*str == chr)
            return str;
        str++;
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