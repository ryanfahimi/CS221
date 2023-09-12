#include <stdio.h>
#include <stdbool.h>

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

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