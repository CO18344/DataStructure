
/***
  binary search tree
  version  : 1.0.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* right;
  struct Node* left;
};


struct TreeNode
{
  struct Node* node;
  struct TreeNode* next;
};

struct Stack {
  struct TreeNode* head;
  struct TreeNode* top;
};


struct Stack* create_stack(){
  struct Stack* target = (struct Stack*)malloc(sizeof(struct Stack));
  target->head = NULL;
  target->top = NULL;
}

int isempty(struct  Stack* st)
{
  return st->head == NULL;
}

void push(struct Stack* st, struct Node* node)
{
  // struct TreeNode* current,prev;
  struct TreeNode* node_tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  node_tree->node = node;
  node_tree->next = NULL;
  if(st->top == NULL)
  {
    st->top = node_tree;
    st->head = node_tree;
    return;
  }
  else
  {
    st->top->next = node_tree;
    st->top = node_tree;
  }
}


struct Node* pop(struct Stack *st)
{
  if(isempty(st))
  {
    return NULL;
  }
  struct Node* data = st->top->node;
  struct TreeNode* current = st->head;
  struct TreeNode* previous;

  while(current != st->top)
  {
    previous = current;
    current = current->next;
  }

  if(st->top == st->head)
  {
    struct TreeNode* val = st->top;
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
  struct TreeNode* current;
  current = st->head;
  if(st->head == NULL)
  {
    printf("Stack is empty");
  }
  else
  {
    while(current != NULL)
    {
      printf("%d\n", current->node->data);
      current = current->next;
    }
  }
}


/**
@insert_node_recur : insert the node in the tree in the with recursive method.
@ return : nothing
@ arg1 : the address of the pointer that is under analysation.
@ arg2 : the data part of the node.

*/


void insert_node_recur(struct Node **leaf, int key)
{
  if(key < (*leaf)->data)
  {
    if((*leaf)->left == NULL)
    {
      (*leaf)->left = (struct Node*)malloc(sizeof(struct Node));
      (*leaf)->left->data =  key;
      (*leaf)->left->left = NULL;
      (*leaf)->left->right = NULL;
    }
    else
      return insert_node_recur(&(*leaf)->left, key);
  }
  else if(key >= (*leaf)->data)
  {
    if((*leaf)->right == NULL)
    {
      (*leaf)->right = (struct Node*)malloc(sizeof(struct Node));
      (*leaf)->right->data = key;
      (*leaf)->right->left = NULL;
      (*leaf)->right->right = NULL;
    }
    else
      return insert_node_recur(&(*leaf)->right, key);
  }
}

void insert_node(struct Node **root, int key)
{
  if(*root == NULL)
  {
    *root = (struct Node*)malloc(sizeof(struct Node));
    (*root)->data =  key;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else
    return insert_node_recur(root, key);
}

// PreOrder traversal.

void preorder_traversal(struct Node *leaf)
{
  if(leaf)
  {
    printf("%d ", leaf->data);
    preorder_traversal(leaf->right);
    preorder_traversal(leaf->left);
  }
}

void preorder_traversal_without_recursion(struct Node *leaf)
{
  struct Stack* st = create_stack();
  while(1)
  {
    while(leaf)
    {
      printf("%d\n", leaf->data);
      push(st, leaf);
      leaf = leaf->left;
    }
    if(isempty(st))
      return;
    leaf = pop(st);
    leaf = leaf->right;
  }
}


struct Node* findmax(struct Node* leaf)
{
  if(leaf == NULL)
  {
    return NULL;
  }
  while(leaf->right  == NULL)
  {
    leaf = leaf->right;
  }
  return leaf;
}



// deleting the desired node in the binary tree
struct Node* delete_node(struct Node* node, int key)
{
  struct Node* temp;
  if(node == NULL)
  {
    printf("List is empty!!!\n");
  }
  if(key < node->data)
  {
    node = delete_node(node->left, key);
  }
  if(key > node->data)
  {
    node = delete_node(node->right, key);
  }
  else
  {
    if(node->left && node->right)
    {
      temp = findmax(node->left);
      node->data = temp->data;
      node = delete_node(node->left, node->data);
    }
    else
    {
      temp = node;
      if(node->left == NULL)
        node = node->right;
      if(node->right == NULL)
        node = node->left;
      free(temp);
    }
  }
  return node;
}


int main()
{
  // Binary Search tree.
  struct Node* root = NULL;
  insert_node(&root, 89);
  insert_node(&root, 23);
  insert_node(&root, 34);
  insert_node(&root, 65);
  insert_node(&root, 23);
  insert_node(&root, 90);
  insert_node(&root, 99);
  insert_node(&root, 80);
  insert_node(&root, 20);
  insert_node(&root, 1);
  preorder_traversal_without_recursion(root);
  delete_node(root, 34);

  return 0;
}
