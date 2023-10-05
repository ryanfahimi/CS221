#include <stdio.h>

/**
 * This is the main function.
 * It prints the address and value of variables to the console.
 * @param None
 * @return 0
 */
int main()
{
    int x = 2, y = 12;
    int *p = &x, *q = &y;

    printf("Address of x: %p, Value of x: %d\n", &x, x);
    printf("Value of p: %p, Value of *p: %d\n", p, *p);
    printf("Address of y: %p, Value of y: %d\n", &y, y);
    printf("Value of q: %p, Value of *q: %d\n", q, *q);
    printf("Address of p: %p\n", &p);
    printf("Address of q: %p\n", &q);

    return 0;
}