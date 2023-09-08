#include <stdio.h>
#include <time.h>

void guess_unsigned_short_password()
{
    const unsigned short int upper_bound = -1; // 2^16 - 1
    const unsigned short int correct_password = -1;
    unsigned short int guess;
    clock_t start, end;
    float seconds;
    start = clock();
    for (guess = 0; guess <= upper_bound; guess++)
    {
        if (guess == correct_password)
        {
            break;
        }
    }
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("It takes at most %f seconds to guess the unsigned short password.\n", seconds);
}

void guess_unsigned_int_password()
{
    const unsigned int upper_bound = -1; // 2^32 - 1
    const unsigned int correct_password = -1;
    unsigned int guess;
    clock_t start, end;
    float seconds;
    start = clock();
    for (guess = 0; guess <= upper_bound; guess++)
    {
        if (guess == correct_password)
        {
            break;
        }
    }
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("It takes at most %f seconds to guess the unsigned int password.\n", seconds);
}

void guess_unsigned_long_password()
{
    const unsigned long upper_bound = -1; // 2^64 - 1
    const unsigned long correct_password = -1;
    unsigned long guess;
    clock_t start, end;
    float seconds;
    start = clock();
    for (guess = 0; guess <= upper_bound; guess++)
    {
        if (guess == correct_password)
        {
            break;
        }
    }
    end = clock();
    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("It takes at most %f seconds to guess the unsigned long password.\n", seconds);
}

int main()
{
    guess_unsigned_short_password();
    guess_unsigned_int_password();
    guess_unsigned_long_password();

    return 0;
}
