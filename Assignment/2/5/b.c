#include <stdio.h>

const char *findTheChar(const char *str, char chr)
{
    int k = 0;
    while (*(str + k) != '\0')
    {
        if (*(str + k) == chr)
            return str + k;
        k++;
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