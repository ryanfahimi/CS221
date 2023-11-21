#include <stdio.h>
#include <stdlib.h>

void
writeToFile ()
{
  char buffer[20];
  printf ("Enter the content:\n");
  fgets (buffer, sizeof (buffer),
         stdin); // Using fgets to prevent buffer overflow

  FILE *f = fopen ("out.txt", "w");
  if (f == NULL)
    {
      printf ("Can't write file out.txt\n");
      return;
    }

  fputs (buffer, f); // Correct use of fputs with file pointer
  fclose (f);
}

int
main (void)
{
  writeToFile ();
  return EXIT_SUCCESS;
}
