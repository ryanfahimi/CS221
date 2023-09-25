#include <stdio.h>

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