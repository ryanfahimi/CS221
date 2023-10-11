#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Checks if a string is a palindrome.
   @param str The string to be checked.
   @param s The starting index.
   @param e The ending index.
   @return true if the string is a palindrome, false otherwise. */
bool
isPalindrome (char *str, int s, int e)
{
  // Base case 1: If the indices have crossed each other, the string is a
  // palindrome
  if (s >= e)
    {
      return true;
    }

  // Base case 2: If characters at current indices are different, it's not a
  // palindrome
  if (*(str + s) != *(str + e))
    {
      return false;
    }

  // Recursively check the next set of characters
  return isPalindrome (str, s + 1, e - 1);
}

int
main (void)
{
  char str[100];
  printf ("Enter a string: ");
  scanf ("%s", str);
  printf ("%s is %sa palindrome\n", str,
          isPalindrome (str, 0, strlen (str) - 1) ? "" : "not ");
  return 0;
}
