#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct user
{
  char username[50];
  char password[256];
  char firstname[50];
  char lastname[50];
  char salt[10];
  int admin;
};

char *
cs221Hash (const char *password)
{
  return crypt (password, "00");
}

struct user *
createUsers (int *count)
{
  FILE *fp = fopen ("credential_file", "r");
  if (fp == NULL)
    {
      return NULL;
    }
  char line[256];
  *count = 0;
  while (fgets (line, sizeof (line), fp))
    {
      if (line[0] == '\n')
        {
          continue;
        }
      (*count)++;
    }
  fclose (fp);
  struct user *users = malloc (*count * sizeof (struct user));
  if (users == NULL)
    {
      return NULL;
    }
  FILE *fp2 = fopen ("/dev/random", "r");
  if (fp2 == NULL)
    {
      return NULL;
    }
  char salt[10];
  for (int i = 0; i < *count; ++i)
    {
      struct user *user = users + i;
      if (fread (salt, 1, sizeof (salt) - 1, fp2) != sizeof (salt) - 1)
        {
          free (users);
          fclose (fp2);
          return NULL;
        }
      salt[sizeof (salt) - 1] = '\0';
      strcpy (user->salt, salt);
    }
  fclose (fp2);
  return users;
}

void
populateUsers (void *users)
{
  FILE *fp = fopen ("credential_file", "r");
  if (fp == NULL)
    {
      return;
    }
  char line[256];
  int i = 0;
  while (fgets (line, sizeof (line), fp))
    {
      if (line[0] == '\n')
        {
          continue;
        }
      char *token = strtok (line, "\t");
      struct user *user = (struct user *)users + i;
      strcpy (user->firstname, token);
      token = strtok (NULL, "\t");
      strcpy (user->lastname, token);
      token = strtok (NULL, "\t");
      strcpy (user->username, token);
      token = strtok (NULL, "\t");
      strcpy (user->password, strcat (token, user->salt));
      token = strtok (NULL, "\t");
      user->admin = atoi (token);
      i++;
    }
  fclose (fp);
}

int
checkAdminPassword (char *password, struct user *users, int count)
{
  for (int i = 0; i < count; ++i)
    {
      if (strcmp ((users + i)->username, "admin") == 0)
        {
          if (strcmp ((users + i)->password,
                      strcat (cs221Hash (password), (users + i)->salt))
              == 0)
            {
              return 1;
            }
          else
            {
              return 0;
            }
        }
    }
  return 0;
}

struct user *
addUser (struct user *users, int *count, char *username, char *password,
         char *firstname, char *lastname, int admin)
{
  struct user *new_users
      = realloc (users, (*count + 1) * sizeof (struct user));
  if (new_users == NULL)
    {
      return NULL;
    }
  users = new_users;
  struct user *user = users + *count;
  FILE *fp = fopen ("/dev/random", "r");
  if (fp == NULL)
    {
      return NULL;
    }
  char salt[10]; // One extra byte for the null terminator
  if (fread (salt, 1, sizeof (salt) - 1, fp) != sizeof (salt) - 1)
    {
      fclose (fp);
      return NULL;
    }
  salt[sizeof (salt) - 1] = '\0'; // Ensure null termination
  strcpy (user->salt, salt);
  fclose (fp);
  strcpy (user->username, username);
  strcpy (user->password, strcat (cs221Hash (password), salt));
  strcpy (user->firstname, firstname);
  strcpy (user->lastname, lastname);
  user->admin = admin;
  (*count)++;
  return users;
}

void
saveUsers (struct user *users, int count)
{
  FILE *fp = fopen ("credential_file", "w");
  if (fp == NULL)
    {
      return;
    }
  for (int i = 0; i < count; ++i)
    {
      fprintf (fp, "%s\t%s\t%s\t%s\t%d\n", (users + i)->firstname,
               (users + i)->lastname, (users + i)->username,
               (users + i)->password, (users + i)->admin);
    }
  fclose (fp);
}

int
main (void)
{
  int user_count = 0;
  struct user *users = createUsers (&user_count);
  if (users == NULL)
    {
      return EXIT_FAILURE;
    }
  populateUsers (users);

  printf ("Enter admin password to add new users: ");
  char entered_admin_password[50];
  scanf ("%s", entered_admin_password);
  if (checkAdminPassword (entered_admin_password, users, user_count))
    {
      struct user new_user;
      printf ("Enter username: ");
      scanf ("%s", new_user.username);
      printf ("Enter first name: ");
      scanf ("%s", new_user.firstname);
      printf ("Enter last name: ");
      scanf ("%s", new_user.lastname);
      printf ("Enter password: ");
      scanf ("%s", new_user.password);
      printf ("Enter admin level: ");
      scanf ("%d", &(new_user.admin));
      users
          = addUser (users, &user_count, new_user.username, new_user.password,
                     new_user.firstname, new_user.lastname, new_user.admin);
      if (users == NULL)
        {
          free (users);
          return EXIT_FAILURE;
        }
    }
  saveUsers (users, user_count);
  free (users);
  return EXIT_SUCCESS;
}