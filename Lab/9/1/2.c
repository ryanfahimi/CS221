#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  int sum = 0;

  // Starting from 1 because argv[0] contains the name of the program
  for (int i = 1; i < argc; i++)
    {
      sum += atoi (argv[i]); // Convert string to integer and add to sum
    }

  printf ("%d\n", sum);
  return 0;
}
