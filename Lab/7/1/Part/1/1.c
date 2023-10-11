#include <stdio.h>

/**
 * This function finds the longest common substring between two strings.
 * @param str1 The first string
 * @param str2 The second string
 * @param result The longest common substring
 * @return None
 */
void longestCommonString(char *str1, char *str2, char *result)
{
    int maxLen = 0;
    char *maxStart = NULL;

    for (int str1_offset = 0; *(str1 + str1_offset); str1_offset++)
    {
        for (int str2_offset = 0; *(str2 + str2_offset); str2_offset++)
        {
            int currLen = 0;
            char *substr1 = str1 + str1_offset;
            char *substr2 = str2 + str2_offset;
            while (*substr1 && *substr2 && *substr1 == *substr2)
            {
                currLen++;
                substr1++;
                substr2++;
            }
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxStart = str1 + str1_offset;
            }
        }
    }

    if (maxStart)
    {
        while (maxLen--)
        {
            *result++ = *maxStart++;
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
