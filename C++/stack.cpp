// Stack 

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
public:
   Stack();
    void push(T key);
    T pop();
    bool isempty() const;
    void print();
private:
    int top;
    vector<T>* data;    
};

/************* definition *********************/


template <typename T>
Stack<T>::Stack()
{
    data = new vector<int>();
    top = -1;
}

template <typename T>
void Stack<T>::print()
{
    Stack<T> temp_stack;
}

template <typename T>
bool Stack<T>::isempty() const 
{
    return top == -1;
}

template <typename T>
void Stack<T>::push(T key)
{
    data->push_back(key);
}


template <typename T>
T Stack<T>::pop()
{
    if(!isempty())
    {
        return data->pop_back();
    }
    else 
    {
        cout << "Underflow" << endl;
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Checked" << endl;
    
    Stack<int>* st = new Stack<int>();
    st->push(23);
    st->push(27);

    return 0;
}
