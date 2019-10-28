#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node* next;
};

struct Stack
{
  struct Node* head;
  struct Node* top;
};


struct Stack* create_stack()
{
  struct Stack* target = (struct Stack*)malloc(sizeof(struct Stack));
  target->head = NULL;
  target->top = NULL;
}

int isempty(struct  Stack* st)
{
  return st->head == NULL;
}

void push(struct Stack* st, int data)
{
  // struct Node* current,prev;
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;

  if(st->top == NULL)
  {
    st->top = node;
    st->head = node;
    return;
  }
  else
  {
    st->top->next = node;
    st->top = node;
  }
}


int pop(struct Stack *st)
{
  if(isempty(st))
  {
    return 0;
  }
  int data = st->top->data;
  struct Node* current = st->head;
  struct Node* previous;

  while(current != st->top)
  {
    previous = current;
    current = current->next;
  }

  if(st->top == st->head)
  {
    struct Node* val = st->top;
    st->top = NULL;
    st->head = NULL;
    free(current);
  }
  else
  {
    st->top = previous;
    st->top->next = NULL;
    free(current);
  }

  return data;
}


void print(struct Stack *st)
{
  struct Node* current;
  current = st->head;
  if(st->head == NULL)
  {
    printf("Stack is empty");
  }
  else
  {
    while(current != NULL)
    {
      printf("%d\n", current->data);
      current = current->next;
    }
  }
}



int main()
{

  struct Stack* target_stack = create_stack();
  push(target_stack, 45);
  push(target_stack, 89);
  print(target_stack);
  int val = pop(target_stack);
  printf("data : %d\n\n", val);
  print(target_stack);
  push(target_stack, 789);
  push(target_stack, 89);
  print(target_stack);
  
  return 0;
}
