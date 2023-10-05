#include <stdio.h>

/**
 * This function returns the mean of an array of numbers.
 * @param scores The array of numbers
 * @param numScores The length of the array
 * @return The mean of the array
 */
double mean(const double *scores, int numScores)
{
    double total = 0;
    for (int i = 0; i < numScores; i++)
    {
        total += *(scores + i);
    }
    return total / numScores;
}

int main(void)
{
    double scores[5] = {1, 2, 3, 4, 5};
    printf("mean = %f\n", mean(scores, 5));
    return 0;
}