#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
  char username[50];
  char password[50];
  int admin;
};

/**
 * Allocates memory for an array of users with the given maximum number of
 * users.
 *
 * @param max_number_of_users The maximum number of users to allocate memory
 * for.
 *
 * @return A pointer to the allocated memory for the array of users.
 */
struct user *
createUsers (int max_number_of_users)
{
  return (struct user *)calloc (max_number_of_users, sizeof (struct user));
}

/**
 * Initializes the array of users with default values.
 *
 * @param users A pointer to the array of users to initialize.
 * @param max_number_of_users The maximum number of users in the array.
 */
void
initUsers (void *users, int max_number_of_users)
{
  struct user *usersArray = (struct user *)users;
  for (int i = 0; i < max_number_of_users; ++i)
    {
      strcpy ((usersArray + i)->username, "default");
      strcpy ((usersArray + i)->password, "default");
      (usersArray + i)->admin = 0;
    }
}

/**
 * Adds a new user to the array of users.
 *
 * @param users A pointer to the array of users.
 * @param username The username of the new user.
 * @param password The password of the new user.
 * @param admin Whether the new user is an admin or not.
 * @param count A pointer to the number of users in the array.
 */
void
addUser1 (struct user *users, char *username, char *password, int admin,
          int *count)
{
  struct user *newUser = users + *count;
  strcpy (newUser->username, username);
  strcpy (newUser->password, password);
  newUser->admin = admin;
  (*count)++;
}

/**
 * Adds a new user to the array of users.
 *
 * @param users A pointer to the array of users.
 * @param newUser A pointer to the new user to add.
 * @param count A pointer to the number of users in the array.
 */
void
addUser2 (struct user *users, struct user *newUser, int *count)
{
  struct user *userToAdd = users + *count;
  *userToAdd = *newUser;
  (*count)++;
}

/**
 * Prints the users in the array of users.
 *
 * @param users A pointer to the array of users.
 * @param number_of_users The number of users in the array.
 */
void
printUser (struct user *users, int number_of_users)
{
  for (int i = 0; i < number_of_users; ++i)
    {
      printf ("username%d: %s\n", i, (users + i)->username);
      printf ("password%d: %s\n", i, (users + i)->password);
    }
}

/**
 * Finds all the admins in the array of users.
 *
 * @param users A pointer to the array of users.
 * @param number_of_users The number of users in the array.
 * @param adminCount A pointer to the number of admins in the array.
 *
 * @return A pointer to the array of admins.
 */
struct user **
findAllAdmins (struct user *users, int number_of_users, int *adminCount)
{
  struct user **admins = NULL;
  *adminCount = 0;

  for (int i = 0; i < number_of_users; ++i)
    {
      if ((users + i)->admin != 0)
        {
          (*adminCount)++;
        }
    }

  admins = (struct user **)malloc (*adminCount * sizeof (struct user *));
  if (!admins)
    {
      *adminCount = 0;
      return NULL;
    }

  int adminIndex = 0;
  for (int i = 0; i < number_of_users; ++i)
    {
      if ((users + i)->admin != 0)
        {
          *(admins + adminIndex) = users + i;
          adminIndex++;
        }
    }

  return admins;
}

int
main (void)
{
  struct user *users = createUsers (10);
  if (users == NULL)
    {
      return EXIT_FAILURE;
    }

  int userCount = 0;
  initUsers (users, 10);

  addUser1 (users, "admin", "s#1Pa5", 1, &userCount);
  addUser1 (users, "vahab", "fgH!12", 0, &userCount);

  struct user u1;
  u1.admin = 1;
  strcpy (u1.username, "usf");
  strcpy (u1.password, "gA24?m");
  addUser2 (users, &u1, &userCount);

  printUser (users, userCount);

  int adminCount = 0;
  struct user **adminUsers = findAllAdmins (users, userCount, &adminCount);
  if (adminUsers == NULL)
    {
      return EXIT_FAILURE;
    }
  free (adminUsers);

  free (users);
  return EXIT_SUCCESS;
}
