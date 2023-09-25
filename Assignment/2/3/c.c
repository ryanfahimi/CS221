#include <stdio.h>

void computeCube(int n, int *ncubed)
{
    *ncubed = n * n * n;
}

int main(void)
{
    int result;
    int *ptr = &result;
    computeCube(5, ptr);
    printf("Five cubed is %d\n", result);
    return 0;
}