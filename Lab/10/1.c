/* malloclab.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 30

/**
 * Converts a string to lowercase.
 *
 * @param str A pointer to the string.
 * @return A pointer to the lowercase string.
 */
char *
toLower (const char *const str)
{
  int length = strlen (str);
  char *lowercaseStr = (char *)malloc (sizeof (char) * (length + 1));

  if (!lowercaseStr)
    {
      printf ("ERROR - malloc failed in toLower: Returning NULL!\n");
      return NULL;
    }

  for (int i = 0; i < length; i++)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        {
          lowercaseStr[i] = str[i] + 'a' - 'A';
        }
      else
        {
          lowercaseStr[i] = str[i];
        }
    }

  lowercaseStr[length] = '\0'; // Null-terminate the new string
  return lowercaseStr;
}

int
main (int argc, char *argv[])
{
  char wordArray[MAX_WORD_LENGTH]; /* a string */
  char *word;                      /* also a string , of length ? */
  printf ("Enter a word (<%d chars): ", MAX_WORD_LENGTH);
  scanf ("%s", wordArray);
  word = (char *)malloc (sizeof (char) * (strlen (wordArray) + 1));
  /* allocate enough space */
  if (word == NULL)
    {
      printf ("ERROR - malloc failed : Exiting Program!\n\n");
      return 1;
    }
  strcpy (word, wordArray); /* copy the string into the
                               allocated space */
  printf ("You entered: %s\n", word);
  free (word); /* necessary? */
  char *lowerWord = toLower (wordArray);
  printf ("Lower case string: %s\n", lowerWord);
  free (lowerWord);
  return 0;
}