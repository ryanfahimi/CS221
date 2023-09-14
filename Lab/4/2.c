#include <stdio.h>
#include <stdbool.h>

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool doesContainDigit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isDigit(str[i]))
        {
            return true;
        }
    }
    return false;
}

bool doesContainOneDigit(char *str)
{
    int digitCount = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isDigit(str[i]))
        {
            digitCount++;
            if (digitCount > 1)
            {
                return false;
            }
        }
    }
    return digitCount == 1;
}

int stringToInt(char *str)
{
    int result = 0;
    int i = 0;

    bool isNegative = false;
    if (str[0] == '-')
    {
        isNegative = true;
        i = 1;
    }

    while (str[i] != '\0')
    {
        int digit = str[i] - '0';

        result = result * 10 + digit;

        i++;
    }

    if (isNegative)
    {
        result = -result;
    }

    return result;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (doesContainDigit(str))
    {
        printf("The string contains digits.\n");
    }
    else
    {
        printf("The string does not contain any digit.\n");
    }

    if (doesContainOneDigit(str))
    {
        printf("The string contains only one digit.\n");
    }
    else
    {
        printf("The string does not contain only one digit.\n");
    }

    // int number = stringToInt(str);
    // printf("The number is %d.\n", number);

    return 0;
}