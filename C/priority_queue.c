/***
  priority queue
*/

#include <stdio.h>
#include <stdlib.h>

struct Priority_Node
{
  int data;
  int priority;
  struct Priority_Node* next;
};

void Enqueue(struct Priority_Node** pqueue, int data_value, int priority_value)
{
  struct Priority_Node* previous;
  struct Priority_Node* current = *pqueue;
  struct Priority_Node* pn = (struct Priority_Node*)malloc(sizeof(struct Priority_Node));
  pn->data =  data_value;
  pn->priority = priority_value;
  pn->next = NULL;
  if(*pqueue == NULL)
  {
    *pqueue = pn;
  }
  else
  {
    while((current->priority < pn->priority) && (current != NULL))
    {
        previous = current;
        current = current->next;
    }
    if(current == *pqueue)
    {
      *pqueue = pn;
      pn->next = current;
    }
    else
    {
      previous->next = pn;
      pn->next = current;
    }
  }
}

int Dequeue(struct Priority_Node **queue)
{
  if(*queue == NULL)
  {
    printf("List is empty\n");
    return -1;
  }
  int data = (*queue)->data;
  struct Priority_Node* tar = *queue;
  *queue = (*queue)->next;
  free(tar);
  return data;
}

void print_list(struct Priority_Node* queue)
{
  struct Priority_Node* current = queue;
  if(current == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    while(current != NULL)
    {
      printf("data : %d and priority : %d\n", current->data, current->priority);
      current = current->next;
    }
  }
}

int size(struct Priority_Node* pqueue)
{
  if(pqueue == NULL)
    return 0;

  int size_number = 0;
  struct Priority_Node* current = pqueue;
  while(current != NULL)
  {
      current = current->next;
      size_number++;
  }
  return size_number;
}


int main()
{

  struct Priority_Node* pqueue = NULL;
  Enqueue(&pqueue, 78, 90);
  Enqueue(&pqueue, 43, 2);
  Enqueue(&pqueue, 89, 5);
  Enqueue(&pqueue, 898, 0);
  Enqueue(&pqueue, 89, 0);
  print_list(pqueue);
  printf("Data Dequeued : \n");
  int data = Dequeue(&pqueue);
  printf("data :  %d", data);
  printf("\nSize of the queue is %d\n", size(pqueue));
  return 0;
}
