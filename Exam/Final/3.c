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
printList (struct linkNode *head)
{
  while (head != NULL)
    {
      printf ("%d ", head->value);
      head = head->next;
    }
  printf ("\n");
}

int
main ()
{
  struct linkNode head;
  struct linkNode tail;
  struct linkNode node;

  head.value = 1;
  head.next = &node;
  node.value = 2;
  node.next = &tail;
  tail.value = 3;
  tail.next = NULL;

  printList (&head);
  reverseList (&head, &tail);

  printList (&tail);
}
