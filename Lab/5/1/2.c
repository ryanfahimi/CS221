#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    *(str + 1) = '@';

    printf("The modified string is: %s", str);

    return 0;
}