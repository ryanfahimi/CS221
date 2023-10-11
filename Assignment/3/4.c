#include <stdio.h>

/* Converts a decimal number to binary.
   @param num The number to be converted.
   @return The binary representation of the number. */
long
convertToBinary (int num)
{
  // Base case: if the number is 0 or 1, return the number itself
  if (num == 0 || num == 1)
    {
      return num;
    }

  // Recursively get the binary representation of the quotient
  long binary = convertToBinary (num / 2);

  // Return the combined binary representation
  return num % 2 + 10 * binary;
}

int
main (void)
{
  int num;
  printf ("Enter a number: ");
  scanf ("%d", &num);
  printf ("The binary representation of %d is %ld\n", num,
          convertToBinary (num));
  return 0;
}