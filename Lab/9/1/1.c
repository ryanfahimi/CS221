#include <stdio.h>
#include <string.h>

// Returns the second int in intArr
int
getSecond (void *intArr)
{
  int *arr = (int *)intArr;
  return arr[1];
}

// Returns i mod 2, i is an unsigned int
int
mod2 (int *i)
{
  return (unsigned int)(*i) % 2;
}

// Returns the last character in str
char
theLastChar (void *str)
{
  char *s = (char *)str;
  int length = strlen (s);
  return s[length - 1];
}

int
main (void)
{
  int intArr[5] = { 20, 4, 10, 6, 5 };
  printf ("The second int is %d.\n", getSecond ((void *)intArr));

  unsigned int i = 0xfffffff1;
  printf ("%u mod 2 is %d.\n", i, mod2 ((int *)&i));

  char str[] = "USF";
  printf ("The last character is %c.\n", theLastChar ((void *)str));

  return 0;
}
