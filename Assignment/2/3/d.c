#include <stdbool.h>
#include <stdio.h>

/**
 * This function compares two strings.
 * @param str1 The first string
 * @param str2 The second string
 * @return true if the strings are equal, false otherwise
 */
bool strequal(const char str1[], const char str2[])
{
    int i = 0;
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2) // compare corresponding characters
            return false;
        str1++; // advance to the next character
        str2++;
    }
    return *str1 == *str2; // both ended at same time ?
}

int main(void)
{
    char a[15] = "Chen, B.";
    char b[15] = "Chen, Y.J.";
    if (strequal(a, b))
        printf("They're the same person!\n");
}