#include <stdio.h>
#include <stdlib.h>

void
setValue (int *arr, int len, int value, int index)
{
  if (index >= 0 && index < len) // Check index bounds
    {
      arr[index] = value;
    }
  else
    {
      printf ("Error: Index out of bounds.\n");
    }
}

int
main (void)
{
  int arr[10];
  int value;
  int index;

  printf ("Enter the value: ");
  scanf ("%d", &value);

  printf ("Enter the position: ");
  scanf ("%d", &index);

  setValue (arr, 10, value, index);

  return EXIT_SUCCESS;
}
