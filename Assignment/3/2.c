#include <stdio.h>

/* Finds the maximum element in an array.
   @param arr The array to be processed.
   @param p The number of elements in the array.
   @param max The current maximum element.
   @return Returns the maximum element in the array. */
int
findMax (int *arr, int p, int max)
{
  // Base case: if the end of the array is reached
  if (p <= 0)
    {
      return max;
    }

  // If the current number is greater than max, update max
  if (*arr > max)
    {
      max = *arr;
    }

  // Recursively process the next element in the array
  return findMax (arr + 1, p - 1, max);
}

int
main (void)
{
  int arr[100], n;
  printf ("Enter the number of elements: ");
  scanf ("%d", &n);
  printf ("Enter the elements: ");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", arr + i);
    }
  printf ("The maximum element is: %d\n", findMax (arr, n, *arr));
  return 0;
}