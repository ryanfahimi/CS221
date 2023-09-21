#include <stdio.h>
int *maxwell(int *a, int *b)
{
    if (*a > *b)
        return a;
    else
        return b;
}
void swap1(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void)
{
    int array[6] = {5, 3, 4, 17, 22, 19};
    int *ptr = maxwell(array, &array[2]);
    *ptr = -1;
    ptr += 2;
    ptr[1] = 9;
    *(array + 1) = 79;
    printf("%d\n", &array[5] - ptr);
    swap1(&array[0], &array[1]);
    swap2(array, &array[2]);
    for (int i = 0; i < 6; i++)
        printf("%d\n", array[i]);
}