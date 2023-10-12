#include <stdio.h>
#include <string.h>

#define NUM_OF_USERS 10
#define MAX_USER_INPUT_SIZE 100

void
addUser (const char *username, const char *password, int *user_count,
         char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE])
{
  if (*user_count < NUM_OF_USERS)
    {
      strcpy (*(*creds + *user_count), username);
      strcpy (*(*(creds + 1) + *user_count), password);
      (*user_count)++;
    }
}

int
getUserIndex (const char *username,
              char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE], int user_count)
{
  for (int i = 0; i < user_count; i++)
    {
      if (strcmp (*(*creds + i), username) == 0)
        {
          return i;
        }
    }
  return -1;
}

void
replaceSecondChar (char new_char, const char *username, int user_count,
                   char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE])
{
  int index = getUserIndex (username, creds, user_count);
  if (index != -1 && strlen (*(*creds + index)) > 1)
    {
      char *second_char = *(*creds + index) + 1;
      *second_char = new_char;
    }
}

void
printAll (char *creds, int user_count)
{
  for (int i = 0; i < user_count; i++)
    {
      printf ("username: %s, password: %s\n", creds + i * MAX_USER_INPUT_SIZE,
              creds + ((i + NUM_OF_USERS) * MAX_USER_INPUT_SIZE));
    }
}

void
swapUser (const char *username1, const char *username2, int user_count,
          char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE])
{
  int index1 = getUserIndex (username1, creds, user_count);
  int index2 = getUserIndex (username2, creds, user_count);

  if (index1 != -1 && index2 != -1)
    {
      char temp[MAX_USER_INPUT_SIZE];

      strcpy (temp, *(*creds + index1));
      strcpy (*(*creds + index1), *(*creds + index2));
      strcpy (*(*creds + index2), temp);

      strcpy (temp, *(*(creds + 1) + index1));
      strcpy (*(*(creds + 1) + index1), *(*(creds + 1) + index2));
      strcpy (*(*(creds + 1) + index2), temp);
    }
}

void
deleteUser (const char *username, int *user_count,
            char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE])
{
  int index = getUserIndex (username, creds, *user_count);
  if (index != -1)
    {
      for (int i = index; i < (*user_count) - 1; i++)
        {
          strcpy (*(*creds + i), *(*creds + i + 1));
          strcpy (*(*(creds + 1) + i), *(*(creds + 1) + i + 1));
        }
      (*user_count)--;
    }
}

int
main (void)
{
  char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE];
  int user_count = 0;
  addUser ("admin", "s#1Pa5", &user_count, creds);
  addUser ("vahab", "fgH!12", &user_count, creds);
  replaceSecondChar ('@', "vahab", user_count, creds);
  printf ("The total number of users: %d\n", user_count);
  printAll (creds[0][0], user_count);
  return 0;
}
