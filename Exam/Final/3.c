#include <stdio.h>
#include <stdlib.h>

struct linkNode
{
  int value;
  struct linkNode *next;
};

void
reverseList (struct linkNode *head, struct linkNode *tail)
{
  struct linkNode *prev = NULL;
  struct linkNode *current = head;
  struct linkNode *next = NULL;

  while (current != tail)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  tail->next = prev;
}

void
printList (struct linkNode *node)
{
  while (node != NULL)
    {
      printf ("%d ", node->value);
      node = node->next;
    }
  printf ("\n");
}

int
main ()
{
  struct linkNode tail = { 3, NULL };
  struct linkNode node = { 2, &tail };
  struct linkNode head = { 1, &node };

  printList (&head);
  reverseList (&head, &tail);

  printList (&tail);
}
