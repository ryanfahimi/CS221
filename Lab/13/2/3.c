#include <stdio.h>
#include <stdlib.h>

typedef struct linkedNode
{
  int value;
  struct linkedNode *next;
} linkedNode;

void
insertInto (int v, int max_length, linkedNode **head, linkedNode **tail)
{
  linkedNode *newNode = (linkedNode *)malloc (sizeof (linkedNode));
  if (newNode == NULL)
    {
      printf ("Error: malloc failed in insertInto\n");
      exit (1);
    }
  linkedNode *current = *head;
  newNode->value = v;
  newNode->next = NULL;
  if (v <= (*head)->value)
    {
      newNode->next = *head;
      *head = newNode;
    }
  else
    {
      while (current->next != NULL && current->next->value < v)
        {
          current = current->next;
        }
      newNode->next = current->next;
      current->next = newNode;
      if (newNode->next == NULL)
        {
          *tail = newNode;
        }
    }
  current = *head;
  int length = 1;
  while (current->next != NULL)
    {
      length++;
      current = current->next;
    }
  if (length > max_length)
    {
      linkedNode *temp = *head;
      *head = (*head)->next;
      free (temp);
    }
}

void
printList (linkedNode *head)
{
  linkedNode *current = head;
  while (current != NULL)
    {
      printf ("%d ", current->value);
      current = current->next;
    }
  printf ("\n");
}

int
main ()
{
  int max_length = 5;
  linkedNode *head = (linkedNode *)malloc (sizeof (linkedNode));
  if (head == NULL)
    {
      printf ("Error: malloc failed in main\n");
      exit (1);
    }
  head->value = 0;
  head->next = NULL;
  linkedNode *tail = head;
  int i;
  for (i = 1; i < 10; i++)
    {
      insertInto (i, max_length, &head, &tail);
      printList (head);
    }
  return 0;
}
