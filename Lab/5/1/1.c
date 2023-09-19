#include <stdio.h>

int main()
{
    int a = 5;
    int b = 6;
    int c = 12;

    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    int sum = *p1 + *p2 + *p3;

    printf("The sum is: %d", sum);

    return 0;
}