/*
linked list
*/
#include <iostream>
#include <cassert>

using namespace std;

class List;
class Iterator;

class Node
{
public:
  Node(int key);
private:
  int data;
  Node* next;
  Node* previous;

friend class List;
friend class Iterator;
};

class List
{
public:
  List();
  void push_back(int key);
  void insert(Iterator iter, int key);
  void remove(Iterator iter);
  Iterator begin();
  Iterator end();

private:
  Node* first;
  Node* last;

friend class Iterator;
};


class Iterator
{
public:
  Iterator();
  void next();
  void previous();
  bool equal(Iterator b) const;
  int get() const;
private:
  Node* position;
  List* container;

friend class List;
};


/********** definition ************/

Node::Node(int key)
{
  data = key;
  next = NULL;
  previous = NULL;
}

List::List()
{
  first = NULL;
  last = NULL;
}

void List::push_back(int key)
{
  Node* new_node = new Node(key);
  if(first == NULL)
  {
    first = new_node;
    last = new_node;
  }
  else
  {
    last->next = new_node;
    new_node->previous = last;
    last = new_node;
  }
}

void List::insert(Iterator iter, int key)
{
  if(iter.position == NULL)
  {
    push_back(key);
  }

  else
  {
    Node* new_node = new Node(key);
    Node* after = iter.position;
    Node* before =  after->previous;

    after->previous = new_node;
    new_node->next = after;
    new_node->previous = before;
    if(after == first)
    {
      first = new_node;
    }
    else
    {
      before->next = new_node;
    }
  }

}

void List::remove(Iterator iter)
{
  assert(iter.position != NULL);
  Node* new_node = iter.position;
  Node* after = new_node->next;
  Node* before = new_node->previous;
  if(new_node == last)
  {
    last = before;
  }
  else
  {
    after->previous = before;
  }

  if(new_node == first)
  {
    first = after;
  }
  else
  {
    before->next = after;
  }

  delete new_node;
}

Iterator List::begin()
{
  Iterator iter;
  iter.position = first;
  iter.container = this;

  return iter;
}

Iterator List::end()
{
  Iterator iter;
  iter.position = last;
  iter.container = this;

  return iter;
}

Iterator::Iterator()
{
  position = NULL;
  container = NULL;
}

void Iterator::next()
{
  position = position->next;
}

void Iterator::previous()
{
  position = position->previous;
}

bool Iterator::equal(Iterator b) const
{
  return position == b.position;
}

int Iterator::get() const
{
  return position->data;
}

int main(int argc, char* argv[])
{

  List staff;
  Iterator pos;

  staff.push_back(34);
  staff.push_back(45);
  staff.push_back(67);
  staff.push_back(65);
  staff.push_back(54);

  pos =  staff.begin();
  pos.next();
  pos.next();
  staff.remove(pos);

  Iterator d = staff.end();

  for(pos = staff.begin(); !pos.equal(d); pos.next())
  {
    cout << "data : " << pos.get() << endl;
  }

  return 0;
}
