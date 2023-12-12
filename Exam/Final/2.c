#include <stdio.h>
#include <stdlib.h>

struct point
{
  float x;
  float y;
  float z;
};

void
centerPoint (struct point **points, int n, struct point *center)
{
  float sumX = 0, sumY = 0, sumZ = 0;

  for (int i = 0; i < n; i++)
    {
      sumX += (*(points + i))->x;
      sumY += (*(points + i))->y;
      sumZ += (*(points + i))->z;
    }

  center->x = sumX / n;
  center->y = sumY / n;
  center->z = sumZ / n;
}

// Dummy implementation for setPoints
void
setPoints (struct point **points, int n)
{
  for (int i = 0; i < n; i++)
    {
      points[i] = (struct point *)malloc (sizeof (struct point));
      points[i]->x = i; // Example initialization
      points[i]->y = i; // Example initialization
      points[i]->z = i; // Example initialization
    }
}

int
main (void)
{
  struct point center;
  struct point *points[100];

  setPoints (
      points,
      100); // Dynamically allocates the points and initializes the points
  centerPoint (points, 100, &center);

  printf ("Center point is (%f, %f, %f)\n", center.x, center.y, center.z);

  // Free the allocated memory
  for (int i = 0; i < 100; i++)
    {
      free (points[i]);
    }

  return 0;
}
