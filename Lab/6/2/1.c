#include <stdio.h>

int getLength(char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void longestCommonString(char *str1, char *str2, char *result)
{
    int len1 = getLength(str1);
    int len2 = getLength(str2);
    int maxLen = 0;
    char *longest = NULL;

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            int currLen = 0;
            while (i + currLen < len1 && j + currLen < len2 && str1[i + currLen] == str2[j + currLen])
            {
                currLen++;
            }
            if (currLen > maxLen)
            {
                maxLen = currLen;
                longest = &str1[i];
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
    fgets(str1, 50, stdin);
    printf("Enter the second string: ");
    fgets(str2, 50, stdin);

    longestCommonString(str1, str2, result);

    if (result[0] == '\0')
    {
        printf("There is no common substring.\n");
    }
    else
    {
        printf("The longest common substring is %s\n", result);
    }
    return 0;
}
