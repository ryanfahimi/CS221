#include <stdio.h>

int
wordCount (const char *filename)
{
  FILE *file = fopen (filename, "r");
  if (file == NULL)
    {
      printf ("Error opening file");
      return -1; // Returning -1 to indicate an error
    }

  int count = 0;
  int inWord = 0;
  char ch;

  while ((ch = fgetc (file)) != EOF)
    {
      if (ch == ' ')
        {
          if (inWord)
            {
              count++;    // End of a word
              inWord = 0; // Reset inWord flag
            }
        }
      else
        {
          inWord = 1; // Inside a word
        }
    }

  if (inWord)
    { // If the last word doesn't end with a space
      count++;
    }

  fclose (file);
  return count;
}

int
main ()
{
  const char *filename = "test.txt";
  int word_count = wordCount (filename);

  if (word_count >= 0)
    {
      printf ("Number of words in file: %d\n", word_count);
    }

  return 0;
}
