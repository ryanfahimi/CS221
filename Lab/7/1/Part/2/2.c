#include <stdio.h>

/**
 * This function replaces all occurrences of a character in a string with another character.
 * @param s The string
 * @param a The character to replace
 * @param b The character to replace a with
 * @return The number of occurrences of a in s
 */
int replace(char *s, char a, char b)
{
    int count = 0;
    char *p = s;
    while (*p != '\0')
    {
        if (*p == a)
        {
            *p = b;
            count++;
        }
        p++;
    }
    return count;
}

int main()
{
    char str[100], a, b;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a character to replace: ");
    scanf(" %c", a);
    printf("Enter a character to replace %c with: ", a);
    scanf(" %c", b);
    int count = replace(str, a, b);
    printf("Replaced %d occurrences of '%c' with '%c'.\n", count, a, b);
    printf("New string: %s\n", str);
    return 0;
}