#pragma once
#include <iostream>
#include "LinkedList.h"
class Queue
{
protected:
    int count;

public:
    //  virtual bool isEmpty() = 0;

    virtual void enqueue(int element) = 0;
    virtual void dequeue() = 0;
    virtual void front() const = 0;
    virtual void rear() const = 0;
};
class LinkedQueue : public Queue
{
public:
    LinkedQueue()
    {
        count = 0;
    }
    virtual void front() const
    {
        std::cout << "Front: " << list.peekFromHead() << std::endl;
    }
    virtual void rear() const
    {
        std::cout << "Rear: " << list.peekFromTail() << std::endl;
    }
    virtual void enqueue(int element)
    {
        std::cout << "Enqueing:" << element << std::endl;
        list.addToTail(element);
    }
    virtual void dequeue()
    {
        std::cout << "Dequeing" << std::endl;
        list.removeFromHead();
    }

private:
    LinkedList list;
};