
/*
  This is the datastructure named as binary search
  have some specific property


  left node has value less than the parent Node
  right node has value more than the parent node

**/

#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};

class BinaryTree
{
public:
  BinaryTree();
  ~BinaryTree();

  void insert(int key);
  struct Node* search(int key);
  void delete_tree();

private:
  void insert(int key, struct Node* leaf);
  struct Node* search(int key, struct Node* leaf);
  void delete_tree(struct Node* leaft);

  struct Node* root;
};

/****** defining the class of the BINRAYTREE ********/


BinaryTree::BinaryTree()
{
  root = NULL;
}

BinaryTree::~BinaryTree()
{
  delete_tree();
}

void BinaryTree::insert(int key, struct Node* leaf)
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

  else if(key > leaf->data)
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

struct Node* BinaryTree::search(int key, struct Node* leaf)
{
  if(leaf != NULL)
  {
  if(key == leaf->data)
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

void BinaryTree::delete_tree(struct Node* leaf)
{
  if(leaf != NULL)
  {
    delete_tree(leaf->left);
    delete_tree(leaf->right);
    delete leaf;
  }
}

void BinaryTree::insert(int key)
{
  if(root != NULL)
    return insert(key, root);
  else
  {
    root = new Node;
    root->data = key;
    root->left = NULL;
    root->right = NULL;
  }
}
struct Node* BinaryTree::search(int key)
{
  return search(key, root);
}

void BinaryTree::delete_tree()
{
  return delete_tree(root);
}


int main(int argc, char* argv[])
{

  BinaryTree b1;
  b1.insert(12);
  b1.insert(45);
  b1.insert(56);
  b1.insert(78);


  int num;
  while(cin >> num)
  {
    if(!cin.fail())
    {
      Node* data1 = b1.search(num);
      cout << data1 << endl;
      if(data1 != NULL)
      {
        cout << num << " is found" << endl;
      }
      else
      {
        cout << num << " not found " << endl;
      }
    }
    else{
      break;
    }
  }

  exit(0);

  return 0;
}
