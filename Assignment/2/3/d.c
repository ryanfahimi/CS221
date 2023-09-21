#include <stdbool.h>
#include <stdio.h>

// return true if two C strings are equal
bool strequal(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i]) // compare corresponding characters
            return false;
        i++; // advance to the next character
    }
    return str1[i] == str2[i]; // both ended at same time ?
}

int main(void)
{
    char a[15] = "Chen, B.";
    char b[15] = "Chen, Y.J.";
    if (strequal(a, b))
        printf("They're the same person!\n");
}