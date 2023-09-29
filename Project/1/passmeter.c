#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * Helper function: Checks if the given password contains the username.
 * @param password The password to be checked.
 * @param username The username to look for.
 * @return Returns true if the password contains the username, false otherwise.
 */
bool containsUsername(const char *password, const char *username)
{
    int passLen = strlen(password);
    int userLen = strlen(username);

    for (int i = 0; i <= passLen - userLen; i++)
    {
        bool match = true;
        for (int j = 0; j < userLen; j++)
        {
            if (tolower(password[i + j]) != tolower(username[j]))
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return true;
        }
    }
    return false;
}

/**
 * Checks if a given password adheres to strong password criteria.
 * @param username The associated username.
 * @param password The password to be checked.
 * @return Returns true if the password is strong, false otherwise.
 */
bool isStrongPassword(const char *username, const char *password)
{
    if (strlen(password) < 8 || containsUsername(password, username))
    {
        return false;
    }

    bool hasUppercase = false, hasLowercase = false, hasDigit = false, hasFourLetters = false;
    int consecutiveLetters = 0;

    for (int i = 0; password[i]; i++)
    {
        if (isupper(password[i]))
        {
            hasUppercase = true;
            consecutiveLetters++;
        }
        else if (islower(password[i]))
        {
            hasLowercase = true;
            consecutiveLetters++;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = true;
            consecutiveLetters = 0;
        }
        else
        {
            return false;
        }

        if (consecutiveLetters == 4)
        {
            hasFourLetters = true;
        }
    }

    return hasUppercase && hasLowercase && hasDigit && hasFourLetters;
}

/**
 * Checks if a given password adheres to strong default password criteria.
 * @param username The associated username.
 * @param password The password to be checked.
 * @return Returns true if the password is a strong default, false otherwise.
 */
bool isStrongDefaultPassword(const char *username, const char *password)
{
    if (strlen(password) > 15 || containsUsername(password, username))
    {
        return false;
    }

    bool hasUppercase = false, hasLowercase = false, hasDigit = false;

    for (int i = 0; password[i]; i++)
    {
        if (isupper(password[i]))
        {
            hasUppercase = true;
        }
        else if (islower(password[i]))
        {
            hasLowercase = true;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = true;
        }
        else
        {
            return false;
        }
    }

    return hasUppercase && hasLowercase && hasDigit;
}

/**
 * Generates a random default password that adheres to criteria.
 * @param default_password The generated password will be stored here.
 * @param username The associated username for checks.
 */
void generateDefaultPassword(char *default_password, const char *username)
{
    const char *allChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int length = 8 + rand() % 8; // Random length between 8 and 15 inclusive

    do
    {
        for (int i = 0; i < length; i++)
        {
            default_password[i] = allChars[rand() % strlen(allChars)];
        }
        default_password[length] = '\0';
    } while (!isStrongDefaultPassword(username, default_password));
}

int main()
{
    srand(time(NULL)); // Initialize random seed for genuine randomness
    char username[50], password[50], defaultPassword[16];

    // Prompt user for username and password
    printf("Enter username: ");
    scanf("%s", username);

    // Loop until user provides a strong password
    while (true)
    {
        printf("Enter new password: ");
        scanf("%s", password);

        if (isStrongPassword(username, password))
        {
            printf("Strong password!\n");
            break;
        }
        else
        {
            printf("Your password is weak. Try again!\n");
        }
    }
    // Generate and display a random default password
    generateDefaultPassword(defaultPassword, username);
    printf("Generated default password: %s\n", defaultPassword);
    return 0;
}
