#include <stdio.h>

int
multiply (int n, int x)
{
  return n << x;
}
int
divide (int n, int x)
{
  return n >> x;
}
int
mod (int n, int x)
{
  return n & ((1 << x) - 1);
}
int
main (void)
{
  int i = 1;
  printf ("1 << 1 = %d.\n", i << 1);
  printf ("1 << 2 = %d.\n", i << 2);
  printf ("1 << 3 = %d.\n", i << 3);
  printf ("1 << 4 = %d.\n", i << 4);
  printf ("10 * 2^3 = %d.\n", multiply (10, 3));
  printf ("100 / 2^2 = %d.\n", divide (100, 2));
  printf ("66 %% 2^4 = %d.\n", mod (66, 4));
  return 0;
}