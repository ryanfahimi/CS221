#include <stdio.h>
#include <string.h>

void
setBool (char *arr, int index, int boolValue)
{
  int charIndex = index / 8;
  int bitPos = index % 8;
  if (boolValue)
    {
      arr[charIndex] |= (1 << bitPos); // Set the bit
    }
  else
    {
      arr[charIndex] &= ~(1 << bitPos); // Clear the bit
    }
}

int
getBool (char *arr, int index)
{
  int charIndex = index / 8;
  int bitPos = index % 8;
  return (arr[charIndex] & (1 << bitPos)) != 0;
}

int
main (void)
{
  char arr[10];
  memset (arr, 0, 10);

  setBool (arr, 78, 1);
  setBool (arr, 40, 0);

  int b78 = getBool (arr, 78); // b78 is 1
  int b40 = getBool (arr, 40); // b40 is 0

  printf ("b78 = %d\n", b78);
  printf ("b40 = %d\n", b40);

  return 0;
}
