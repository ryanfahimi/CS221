#include <stdio.h>

/**
 * This function copies the contents of one string to another.
 * @param dest The destination string
 * @param src The source string
 * @return None
 */
void mystrcpy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main()
{
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);
    mystrcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    return 0;
}
