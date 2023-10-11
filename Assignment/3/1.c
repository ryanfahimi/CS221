#include <stdio.h>

/* Converts a string to uppercase.
   @param str The string to be converted. */
void
toUpperCase (char *str)
{
  // Base case: If the string is empty (reached null terminator), return
  if (*str == '\0')
    {
      return;
    }

  // If the character is lowercase, convert it to uppercase
  if (*str >= 'a' && *str <= 'z')
    {
      *str = *str - ('a' - 'A');
    }

  // Recursively process the next character
  toUpperCase (str + 1);
}

int
main (void)
{
  char str[100];
  printf ("Enter a string: ");
  scanf ("%s", str);
  toUpperCase (str);
  printf ("The string in uppercase is: %s\n", str);
  return 0;
}
