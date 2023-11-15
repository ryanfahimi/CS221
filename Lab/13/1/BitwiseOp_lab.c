#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct new_user
{
  char username[50];
  char password[50];
  bool write;
  bool read;
  bool execute;
};

typedef unsigned char bitmap8;

struct user
{
  char username[50];
  char password[50];
  bitmap8 permissions;
};

void
compare ()
{
  printf ("The size of new_user is %llu.\n", sizeof (struct new_user));
  printf ("The size of user is %llu.\n", sizeof (struct user));
}

void
grantPermission (int bitIndex, struct user *user)
{
  user->permissions |= (1 << bitIndex);
}

void
revokePermission (int bitIndex, struct user *user)
{
  user->permissions &= ~(1 << bitIndex);
}

int
checkPermission (int bitIndex, struct user *user)
{
  return user->permissions & (1 << bitIndex);
}

void
printPermissions (struct user *user)
{
  if (checkPermission (0, user))
    {
      printf ("%s has write permission.\n", user->username);
    }
  else
    {
      printf ("%s doesn't have write permission.\n", user->username);
    }
  if (checkPermission (1, user))
    {
      printf ("%s has read permission.\n", user->username);
    }
  else
    {
      printf ("%s doesn't have read permission.\n", user->username);
    }
  if (checkPermission (2, user))
    {
      printf ("%s has execute permission.\n", user->username);
    }
  else
    {
      printf ("%s doesn't have execute permission.\n", user->username);
    }
}

void
setPermissions (int new_permissions, struct user *user)
{
  // Clear existing permissions
  user->permissions = 0;

  // Set permissions based on new_permissions
  if (new_permissions & 4)
    {                            // Check for read permission (binary 100)
      grantPermission (1, user); // Grant read permission
    }
  if (new_permissions & 2)
    {                            // Check for write permission (binary 010)
      grantPermission (0, user); // Grant write permission
    }
  if (new_permissions & 1)
    {                            // Check for execute permission (binary 001)
      grantPermission (2, user); // Grant execute permission
    }
}

int
main (void)
{
  struct user user;
  strcpy (user.username, "admin");
  strcpy (user.password, "s#1Pa5");
  user.permissions = 0; // Sets the permissions to 0
  grantPermission (0, &user);
  grantPermission (1, &user);
  printPermissions (&user);
  revokePermission (1, &user);
  grantPermission (2, &user);
  printPermissions (&user);
  // setPermissions (7, &user);
  // printPermissions (&user);
  return EXIT_SUCCESS;
}