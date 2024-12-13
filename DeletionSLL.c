#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d \n", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *dltatstart(struct Node *head)
{
  struct Node *q = head;
  head = head->next;
  free(q);
  return head;
}

struct Node *dltatend(struct Node *head)
{
  struct Node *p = head;
  struct Node *q = head->next;

  while (q->next != NULL)
  {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

struct Node *dltatindex(struct Node *head, int index)
{
  struct Node *p = head;
  struct Node *q = head->next;

  for (int i = 0; i < index - 1; i++)
  {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
  return head;
}

struct Node *dltbyvalue(struct Node *head, int value)
{
  struct Node *p = head;
  struct Node *q = head->next;

  while (q->data != value && q->next != NULL)
  {
    p = p->next;
    q = q->next;
  }
  if (q->data == value)
  {
    p->next = q->next;
    free(q);
  }

  return head;
}

int main()
{

  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;
  struct Node *fifth;

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));
  fifth = (struct Node *)malloc(sizeof(struct Node));

  head->data = 7;
  head->next = second;

  second->data = 5;
  second->next = third;

  third->data = 3;
  third->next = fourth;

  fourth->data = 6;
  fourth->next = fifth;

  fifth->data = 9;
  fifth->next = NULL;

  printf("Before Deletion:\n");
  LinkedListTraversal(head);

  printf("After Deletion at start:\n");
  head = dltatstart(head);
  LinkedListTraversal(head);

  printf("After Deletion at end:\n");
  head = dltatend(head);
  LinkedListTraversal(head);

  printf("After Deletion at index:\n");
  head = dltatindex(head, 1);
  LinkedListTraversal(head);

  printf("After Deletion by value:\n");
  head = dltbyvalue(head, 6);
  LinkedListTraversal(head);
}