/**
 *
 * A password strength meter and a default password generator,
 * as defined in the CS221 course website for Project 1.
 *
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Helper function: Checks if the given password contains the username.
   @param password The password to be checked.
   @param username The username to look for.
   @return Returns true if the password contains the username, false otherwise.
 */
bool contains_username (const char *username, const char *password)
{
  int user_len = strlen (username);
  int pass_len = strlen (password);

  /* Iterate through the password */
  for (int i = 0; i <= pass_len - user_len; i++)
    {
      bool match = true;

      /* Compare characters of username within password */
      for (int j = 0; j < user_len; j++)
        {
          if (tolower (password[i + j]) != tolower (username[j]))
            {
              match = false;
              break;
            }
        }

      /* If a match is found, return true */
      if (match)
        {
          return true;
        }
    }
  return false;
}

/* Checks if a given password adheres to strong password criteria.
   @param username The associated username.
   @param password The password to be checked.
   @return Returns true if the password is strong, false otherwise. */
bool isStrongPassword (const char *username, const char *password)
{
  /* Initial validations for length and username presence */
  if (strlen (password) < 8 || contains_username (username, password))
    {
      return false;
    }

  bool has_uppercase = false, has_lowercase = false, has_digit = false,
       has_four_letters = false;
  int consecutive_letters = 0;

  /* Iterate through the password and check for character types and consecutive
      letters */
  for (int i = 0; password[i]; i++)
    {
      if (isupper (password[i]))
        {
          has_uppercase = true;
          consecutive_letters++;
        }
      else if (islower (password[i]))
        {
          has_lowercase = true;
          consecutive_letters++;
        }
      else if (isdigit (password[i]))
        {
          has_digit = true;
          consecutive_letters = 0;
        }
      else
        {
          return false;
        }

      if (consecutive_letters == 4)
        {
          has_four_letters = true;
        }
    }

  /* Ensure all criteria are met */
  return has_uppercase && has_lowercase && has_digit && has_four_letters;
}

/* Checks if a given password adheres to strong default password criteria.
   @param username The associated username.
   @param password The password to be checked.
   @return Returns true if the password is a strong default, false otherwise.
 */
bool isStrongDefaultPassword (const char *username, const char *password)
{
  /* Length and username presence checks */
  if (strlen (password) < 8 || strlen (password) > 15
      || contains_username (username, password))
    {
      return false;
    }

  bool has_uppercase = false, has_lowercase = false, has_digit = false;

  /* Check for character types in the password */
  for (int i = 0; password[i]; i++)
    {
      if (isupper (password[i]))
        {
          has_uppercase = true;
        }
      else if (islower (password[i]))
        {
          has_lowercase = true;
        }
      else if (isdigit (password[i]))
        {
          has_digit = true;
        }
      else
        {
          return false;
        }
    }

  /* Ensure the three primary criteria are met */
  return has_uppercase && has_lowercase && has_digit;
}

/* Generates a random default password that adheres to criteria.
   @param defaultPassword The generated password will be stored here.
   @param username The associated username for checks. */
void generateDefaultPassword (char *defaultPassword, const char *username)
{
  const char *all_chars
      = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const int length
      = 8 + rand () % 8; /* Random length between 8 and 15 inclusive */

  /* Generate a password until it meets the criteria */
  do
    {
      for (int i = 0; i < length; i++)
        {
          defaultPassword[i] = all_chars[rand () % strlen (all_chars)];
        }
      defaultPassword[length] = '\0';
    }
  while (!isStrongDefaultPassword (username, defaultPassword));
}

int main (void)
{
  srand (time (NULL)); /* Initialize random seed for genuine randomness */
  char username[50], password[50], default_password[16];

  /* Prompt user for username and password. */
  printf ("Enter username: ");
  scanf ("%s", username);

  /* Loop until user provides a strong password. */
  while (true)
    {
      printf ("Enter new password: ");
      scanf ("%s", password);

      if (isStrongPassword (username, password))
        {
          printf ("Strong password!\n");
          break;
        }
      else
        {
          printf ("Your password is weak. Try again!\n");
        }
    }

  /* Generate and display a random default password. */
  generateDefaultPassword (default_password, username);
  printf ("Generated default password: %s\n", default_password);

  return 0;
}
