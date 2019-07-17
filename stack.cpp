#include "stack.h"


/**** defintion of methods of class ******/

template <typename T>
Stack<T>::Stack()
{
  pos = -1;
}

template <typename T>
void Stack<T>::push(T key)
{
  if(pos > MAX_LENGTH)
  {
    cout << "Stack overflow";
  }
  else
  {
    pos++;
    data[pos] = key;
  }
}

template <typename T>
void Stack<T>::pop()
{
  if(pos < 0)
  {
    cout << "Stack underflow";
  }
  else
  {
    pos--;
  }
}

template <typename T>
void Stack<T>::print_stack() const
{
  cout << "stak_data" << endl;
  for(int i = pos; i >= 0; i--)
    cout << data[i] << endl;
  cout << "stack_data" << endl;
}
