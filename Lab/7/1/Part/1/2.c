#include <stdio.h>

/**
 * This function prints a square of asterisks.
 * @param lines The array of strings that represent the square
 * @param lineNumber The number of lines in the square
 * @return None
 */
void printSquare(char **lines, int lineNumber)
{

    for (int i = 1; i < lineNumber - 1; ++i)
    {
        char *line = lines[i];
        for (int j = 1; j < 9; ++j)
        {
            *(line + j) = ' ';
        }
    }
}

/**
 * This is the main function.
 * It declares an array of strings that represent a square of asterisks.
 * It then calls the printSquare function to modify the square.
 * Finally, it prints the modified square to the console.
 * @param None
 * @return 0
 */
int main(void)
{
    char line1[] = "**********";
    char line2[] = "**********";
    char line3[] = "**********";
    char line4[] = "**********";
    char line5[] = "**********";
    char line6[] = "**********";
    char *lines[] = {line1, line2, line3, line4, line5, line6};

    printSquare(lines, 6);

    for (int i = 0; i < 6; ++i)
    {
        printf("%s\n", lines[i]);
    }

    return 0;
}
