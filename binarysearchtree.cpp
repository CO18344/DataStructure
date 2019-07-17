/**
  binary search tree
*/

#include <iostream>
#include <string>

using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int key);
  struct Node* search(int key);
  void delete_tree();

private:
  void insert(int key, struct Node* leaf);
  struct Node* search(int key, struct Node* leaf);
  void delete_tree(struct Node* leaf);

  struct Node* root;
};



/****** definition ************/

BinarySearchTree::BinarySearchTree()
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
  delete_tree();
}

void BinarySearchTree::insert(int key, struct Node* leaf)
{
  if(key < leaf->data)
  {
    if(leaf->left != NULL)
    {
      return insert(key, leaf->left);
    }
    else
    {
      leaf->left = new Node;
      leaf->left->data = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  }

  else if(key >= leaf->data)
  {
    if(leaf->right != NULL)
    {
      return insert(key, leaf->right);
    }
    else
    {
      leaf->right = new Node;
      leaf->right->data = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }

  }
}

struct Node* BinarySearchTree::search(int key, struct Node* leaf)
{
  if(leaf != NULL)
  {
    if(key ==  leaf->data)
    {
      return leaf;
    }
    else if(key < leaf->data)
    {
      return search(key, leaf->left);
    }
    else if(key > leaf->data)
    {
      return search(key, leaf->right);
    }
  }
  else return NULL;
}


void BinarySearchTree::delete_tree(struct Node* leaf)
{
  if(leaf != NULL)
  {
    delete_tree(leaf->left);
    delete_tree(leaf->right);

    delete leaf;
  }
}


void BinarySearchTree::insert(int key)
{
  if(root == NULL)
  {
    root = new Node;
    root->data = key;
    root->left = NULL;
    root->right = NULL;
  }
  else
  {
    return insert(key, root);
  }
}

struct Node* BinarySearchTree::search(int key)
{
  return search(key, root);
}


void BinarySearchTree::delete_tree()
{
  delete_tree(root);
}

int main()
{

  BinarySearchTree b1;
  b1.insert(34);
  b1.insert(45);
  b1.insert(57);
  b1.insert(89);

  int val;
  while(cin >> val)
  {
    if(!cin.fail())
    {
      struct Node* found = b1.search(val);
      if(found != NULL)
      {
        cout << val << " found " << " at " << found << endl;
      }
      else
      {
        cout << "Not found" << endl;
      }
    }
    else
    {
      break;
    }
  }

  return 0;
}
