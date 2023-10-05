#include <stdio.h>
#include <time.h>

/**
 * This function guesses the correct unsigned short password by brute force method.
 * It calculates the time taken to guess the password by iterating through all possible values of unsigned short.
 * @param None
 * @return None
 */
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

/**
 * This function guesses an unsigned integer password by brute force method.
 * It sets an upper bound for the password and compares each guess with the correct password.
 * The function calculates the time it takes to guess the password and prints it to the console.
 * @param None
 * @return None
 */
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

/**
 * This function guesses an unsigned long password by brute force method.
 * It sets an upper bound for the password and compares each guess with the correct password.
 * The function calculates the time it takes to guess the password and prints it to the console.
 * @param None
 * @return None
 */
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
