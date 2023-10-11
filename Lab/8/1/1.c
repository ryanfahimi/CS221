#include <stdio.h>

/**
 * Recursively compares two strings and returns 0 if they are equal, 1 otherwise.
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return 0 if the strings are equal, 1 otherwise.
 */
int recursiveStrcmp(const char *str1, const char *str2)
{
    if (*str1 == '\0' && *str2 == '\0')
    { // Both strings end at the same position
        return 0;
    }
    else if (*str1 != *str2)
    { // Mismatch found
        return 1;
    }
    else
    { // Current characters are the same, proceed to the next characters
        return recursiveStrcmp(str1 + 1, str2 + 1);
    }
}

int main()
{
    const char *s1 = "hello";
    const char *s2 = "hello";
    const char *s3 = "hell";

    printf("Comparing %s and %s: %d\n", s1, s2, recursiveStrcmp(s1, s2)); // 0
    printf("Comparing %s and %s: %d\n", s1, s3, recursiveStrcmp(s1, s3)); // 1

    return 0;
}
