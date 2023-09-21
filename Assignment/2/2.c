#include <stdio.h>

int main()
{
    int arr[5] = {11, 40, 27, 0, 3};
    int i;
    int *p = &i;

    for (i = 0; i < 5; i++)
    {
        printf("%d %p %d\n", i, arr + i, arr[i]);
    }

    i = 0;
    p = arr;
    while (p < (arr + 5))
    {
        printf("%d %p %d\n", i, p, *p);
        i++;
        p++;
    }

    return 0;
}