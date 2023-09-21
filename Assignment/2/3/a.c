#include <stdio.h>

int main(void)
{
    int MyArray[3] = {10, 20, 30};
    int *p = MyArray;
    *p = 70; // set MyArray[0] to 70
    p++;
    *p = 60; // set MyArray[1] to 60
    p++;
    *p = 50; // set MyArray[2] to 50

    do
    {
        printf("%d\n", *p); // print values
        p--;
    } while (p >= MyArray);

    return 0;
}