#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This function simulates a coin toss.
 * @param None
 * @return true if the coin toss results in heads, false otherwise
 */
bool toss()
{
    return rand() % 2; // Returns 0 for tails and 1 for heads
}

int main(void)
{
    srand(time(0)); // Set the seed of the pseudorandom number generator using the current time

    char quit = ' ';
    scanf(" %c", &quit);
    while (quit != 'n')
    { // quit if the user enters 'n'
        if (toss())
        {
            printf("It's a head.\n");
        }
        else
        {
            printf("It's a tail.\n");
        }
        printf("Keep tossing? (y/n)\n");
        scanf(" %c", &quit);
    }
    return 0;
}
