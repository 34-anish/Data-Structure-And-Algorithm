//#include "header.h"
#include <iostream>

template <class T>
class Stack
{
public:
    virtual void push(T data) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty()  = 0;
    virtual bool isFull()  = 0;
    virtual void top()  = 0;
    virtual void traverse()  = 0;
};

template <class T>
class ArrayStack : public<T> Stack
{
private:
    T *array;
    int index;
    int maxsize;

public:
    ArrayStack(int defvalue);
    void push(T data);
    void pop();
    bool isEmpty() ;
    bool isFull() ;
    void top() ;
    void traverse() ;
};

template <class T>
ArrayStack<T>::ArrayStack(int defvalue = 5) : index(-1), maxsize(defvalue), array(new int[maxsize]) {}

template <class T>
bool ArrayStack<T>::isFull() 
{
    return index > maxsize - 1;
}

template <class T>
bool ArrayStack<T>::isEmpty() 
{
    return index < 0;
}

template <class T>
void ArrayStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Pop() popped : " << array[index];
        index -= 1;
    }
}

template <class T>
void ArrayStack<T>::push(T data)
{
    if (isFull())
    {
        std::cout << "Stack is full" << std::endl;
    }
    else
    {
        index++;
        array[index] = data;
    }
}

template <class T>
void ArrayStack<T>::top() 
{
    std::cout << "Top stack: " << array[index] << std::endl;
}

template <class T>
void ArrayStack<T>::traverse() 
{
    for (int i = 0; i <= index; i++)
    {
        std::cout << array[i] << " ";
    }
}

int main()
{
    ArrayStack <int> a[5];
    // Stack<int> *a = new ArrayStack<int>;
    // a.push(5);
    // a.push(4);
    // a.push(3);
    // a.push(2);
    // a.push(1);
    // a.traverse();
    // a.pop();
    // a.traverse();
}