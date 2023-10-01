#include <stdio.h>

void longestCommonString(char *str1, char *str2, char *result)
{
    int len1 = 0, len2 = 0, maxLen = 0;
    char *longest = NULL;

    while (*(str1 + len1))
    {
        len1++;
    }
    while (*(str2 + len2))
    {
        len2++;
    }

    for (int start1 = 0; start1 < len1; start1++)
    {
        for (int start2 = 0; start2 < len2; start2++)
        {
            int currLen = 0;
            char *substr1 = str1 + start1;
            char *substr2 = str2 + start2;
            while (*substr1 && *substr2 && *substr1 == *substr2)
            {
                currLen++;
                substr1++;
                substr2++;
            }
            if (currLen > maxLen)
            {
                maxLen = currLen;
                longest = str1 + start1;
            }
        }
    }

    if (longest)
    {
        while (maxLen--)
        {
            *result++ = *longest++;
        }

        *result = '\0';
    }
}

int main()
{
    char str1[50], str2[50], result[50];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    longestCommonString(str1, str2, result);

    if (*result == '\0')
    {
        printf("There is no common substring.\n");
    }
    else
    {
        printf("The longest common substring is %s\n", result);
    }
    return 0;
}
