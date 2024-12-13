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

struct Node *insertatfirst(struct Node *head, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->next = head;
  ptr->data = data;
  return ptr;
}
struct Node *insertatend(struct Node *head, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;

  struct Node *p = head;

  while (p->next != NULL)
  {
    p = p->next;
  }

  p->next = ptr;
  ptr->next = NULL;
  return head;
}
struct Node *insertatindex(struct Node *head, int data, int index)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node *p = head;
  for (int i = 0; i != index - 1; i++)
  {
    p = p->next;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

struct node *insertafternode(struct Node *head, struct Node *prevNode, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;

  ptr->next = prevNode->next;
  prevNode->next = ptr;
  return head;
}
int main()
{

  struct Node *head;
  struct Node *second;
  struct Node *third;

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 7;
  head->next = second;

  second->data = 5;
  second->next = third;

  third->data = 3;
  third->next = NULL;
  printf("Before insertion:\n");
  LinkedListTraversal(head);

  printf("After insertion at start:\n");
  head = insertatfirst(head, 56);
  LinkedListTraversal(head);

  printf("After insertion at index:\n");
  head = insertatindex(head, 23, 1);
  LinkedListTraversal(head);

  printf("After insertion at end :\n");
  head = insertatend(head, 43);
  LinkedListTraversal(head);

  printf("After insertion after node:\n");
  head = insertafternode(head, second, 21);
  LinkedListTraversal(head);
}