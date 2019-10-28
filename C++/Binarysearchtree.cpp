/** Binary Search Tree 
  ; here main function is not fully organised so if any one want to organise the main function 
  function to make it user friendly will be welcomed.
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class BST;
class Node
{
public:
  Node();
  Node(int key);
private:
  int data;
  Node* right;
  Node* left;
friend class BST;
};

class BST
{
public:
    BST();
    void insert_node(int data);
    Node* delete_node(int data);
    Node* search_node(int data);
    Node* findmax();
    void print_tree();
    void to_vector(vector<int>& tree_data);
private:
    void insert_node(Node* node, int data);
    Node* delete_node(Node* node, int data);
    Node* search_node(Node* node, int data);
    void print_tree(Node* node);
    void to_vector(vector<int>& tree_data,Node *node);
    Node* root;
};

/**************** definition ********************/
// default constructer
Node::Node()
{

}

Node::Node(int key)
{
  data = key;
  left = NULL;
  right = NULL;
}

BST::BST()
{
  root = NULL;
}

Node* BST::findmax()
{
  if(root == NULL)
  {
    return NULL;
  }
  Node* current = root;
  while(current->right != NULL)
  {
    current = current->right;
  }
  return current;
}

void BST::insert_node(int data)
{
  if(root == NULL)
  {
    root =  new Node(data);
  }
  else
  {
    return insert_node(this->root, data);
  }
}

void BST::insert_node(Node* node, int data)
{
  if(data < node->data)
  {
    if(node->left == NULL)
        node->left = new Node(data);
    else
      return  insert_node(node->left, data);
  }
  else if(data >= node->data)
  {
    if(node->right == NULL)
      node->right = new Node(data);
    else
      return insert_node(node->right, data);
  }
}


void BST::print_tree()
{
  if(root == NULL)
  {
    cout << "NULL TREE" << endl;
  }
  return print_tree(root);
}

void BST::print_tree(Node* node)
{
  if(node != NULL)
  {
    print_tree(node->left);
    cout << node->data << " ";
    print_tree(node->right);
  }
}

Node* BST::search_node(int data)
{
  if(root == NULL)
  {
    return NULL;
  }
  else
  {
    return search_node(root, data);
  }
}

Node* BST::search_node(Node* node, int data)
{
  if(node == NULL)
  {
    cout <<  data << " : Not Found" << endl;
    return NULL;
  }
  if(data == node->data)
    return node;
  else if(data < node->data)
    return search_node(node->left, data);
  else if(data > node->data)
    return search_node(node->right, data);
}

Node* BST::delete_node(int data)
{
  if(root == NULL)
  {
    cout << data << " : NOT FOUND IN THE TREE " << endl;
    return NULL;
  }
  return delete_node(root, data);
}

Node* BST::delete_node(Node* node, int data)
{
  Node* temp;
  Node* target;
  if(node == NULL)
  {
    cout << data << " : NOT FOUND IN THE TREE...." << endl;
    return NULL;
  }
  if(data < node->data)
    node->left = delete_node(node->left, data);
  else if(data > node->data)
    node->right = delete_node(node->right, data);
  else // target found
  {
      if(node->left != NULL && node->right != NULL)
      {
        temp = node;
        target = findmax();
        node->data = target->data;
        node->left = delete_node(node->left, node->data);
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

void BST::to_vector(vector<int>& tree_data)
{
  //vector<int> tree_data;
  return to_vector(tree_data,root);
}

void BST::to_vector( vector<int>& tree_data ,Node* node)
{
  if(node != NULL)
  {
    to_vector(tree_data,node->left);
    tree_data.push_back(node->data);
    to_vector(tree_data,node->right);
  }
}

// print vector
void print_vector(vector<int>& data)
{
  for(int t : data)
  {
    cout << t << " ";
  }
  cout << endl;
}


int main(int argc, char const *argv[]) {

  BST bst;
  bst.insert_node(23);
  bst.insert_node(12);
  bst.insert_node(153);
  bst.insert_node(8);
  bst.insert_node(0);
  bst.insert_node(-12);
  //bst.print_tree();
  vector<int> test_data;
  bst.to_vector(test_data);
  print_vector(test_data);
  return 0;
}
