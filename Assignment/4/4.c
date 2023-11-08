#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the scalar product of two vectors A and B of size n.
 * @param n The size of the vectors.
 * @param A Pointer to the first vector.
 * @param B Pointer to the second vector.
 * @return The scalar product of the two vectors.
 */
double
scalarProduct (int n, double *A, double *B)
{
  double result = 0.0;
  for (int i = 0; i < n; i++)
    {
      result += A[i] * B[i];
    }
  return result;
}

int
main (int argc, char *argv[])
{
  if (argc != 2)
    {
      printf ("Usage: %s <length of arrays>\n", argv[0]);
      return EXIT_FAILURE;
    }

  int n = atoi (argv[1]);
  if (n <= 0)
    {
      printf ("Please provide a positive integer for the array length.\n");
      return EXIT_FAILURE;
    }

  double *A = (double *)malloc (n * sizeof (double));
  double *B = (double *)malloc (n * sizeof (double));

  if (A == NULL || B == NULL)
    {
      printf ("Memory allocation failed.\n");
      free (A); // Safe to free even if it's NULL
      free (B);
      return EXIT_FAILURE;
    }

  printf ("Populate array A:\n");
  for (int i = 0; i < n; i++)
    {
      printf ("A[%d] = ", i);
      scanf ("%lf", &A[i]);
    }

  printf ("Populate array B:\n");
  for (int i = 0; i < n; i++)
    {
      printf ("B[%d] = ", i);
      scanf ("%lf", &B[i]);
    }

  double result = scalarProduct (n, A, B);
  printf ("Scalar product of A and B: %lf\n", result);

  free (A);
  free (B);
  return EXIT_SUCCESS;
}
