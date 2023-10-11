#include <stdio.h>
#include <string.h>

/* Reverses a string.
   @param str The string to be reversed.
   @param i The index.
   @param s The size. */
void
reverse (char *str, int i, int s)
{
  // Base case: If the indices meet or cross over, return
  if (i >= s)
    {
      return;
    }

  // Swap the characters using pointer arithmetic
  char temp = *(str + i);
  *(str + i) = *(str + s - 1);
  *(str + s - 1) = temp;

  // Recursively process the next set of characters
  reverse (str, i + 1, s - 1);
}

int
main (void)
{
  char str[100];
  printf ("Enter a string: ");
  scanf ("%s", str);
  reverse (str, 0, strlen (str));
  printf ("The reversed string is: %s\n", str);
  return 0;
}
