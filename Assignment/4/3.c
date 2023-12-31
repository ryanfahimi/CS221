#include <stdio.h>
#include <stdlib.h>

struct foo
{
  int a;
  char b;
};

int
main (void)
{
  struct foo *arr[5];
  int x;
  for (x = 0; x < 5; x++)
    {
      *(arr + x) = (struct foo *)malloc (sizeof (struct foo));
      if (*(arr + x) != NULL)
        {
          (*(*(arr + x))).a = 0;   // equivalent to arr[x]->a = 0;
          (*(*(arr + x))).b = 'b'; // equivalent to arr[x]->b = 'b';
        }
    }

  // Free the allocated memory
  for (x = 0; x < 5; x++)
    {
      free (*(arr + x));
    }

  return EXIT_SUCCESS;
}
