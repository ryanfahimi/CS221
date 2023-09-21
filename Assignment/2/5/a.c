#include <stdio.h>

double mean(const double *scores, int numScores)
{
    int i = 0;
    double total = 0;
    while (i < numScores)
    {
        total += *(scores + i);
        i++;
    }
    return total / numScores;
}

int main(void)
{
    double scores[5] = {1, 2, 3, 4, 5};
    printf("mean = %f\n", mean(scores, 5));
    return 0;
}