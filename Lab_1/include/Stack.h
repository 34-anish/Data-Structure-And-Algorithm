#pragma once
#include <iostream>
#include "LinkedList.h"
class Stack
{
public:
    //  virtual bool isEmpty() = 0;

    virtual void push(int element) = 0;
    virtual void pop() = 0;
    virtual void top() const = 0;
};
class LinkedStack : public Stack
{
public:
    virtual void top() const
    {
        std::cout << "Top: " << list.peekFromHead() << std::endl;
    }
    virtual void push(int element)
    {
        std::cout << "Pushing to the top" << std::endl;
        list.addToHead(element);
    }
    virtual void pop()
    {
        std::cout << "Poping the element::" << std::endl;
        list.removeFromHead();
    }

private:
    LinkedList list;
};