#include <stdio.h>
#include <stdbool.h>

/**
 * This function returns true if the character is a digit.
 * @param ch The character
 * @return true if the character is a digit, false otherwise
 */
bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

/**
 * This function returns true if the character is a lower case letter.
 * @param ch The character
 * @return true if the character is a lower case letter, false otherwise
 */
bool isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

/**
 * This function returns true if the character is an upper case letter.
 * @param ch The character
 * @return true if the character is an upper case letter, false otherwise
 */
bool isUpper(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isDigit(ch))
    {
        printf("'%c' is a digit.\n", ch);
    }
    else
    {
        printf("'%c' is not a digit.\n", ch);
    }

    if (isLower(ch))
    {
        printf("'%c' is a lower case letter.\n", ch);
    }
    else
    {
        printf("'%c' is not a lower case letter.\n", ch);
    }

    if (isUpper(ch))
    {
        printf("'%c' is an upper case letter.\n", ch);
    }
    else
    {
        printf("'%c' is not an upper case letter.\n", ch);
    }

    return 0;
}