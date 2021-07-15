#include <iostream>
#include "Stack.h"
#include "Queue.h"
int main()
{
    //Integer Stack with maxSize 4
    Stack<int> *int_Stack = new ArrayStack<int>(4);
    int data;
    int_Stack->pop(data);
    int_Stack->push(10);
    int_Stack->push(20);
    int_Stack->push(30);
    int_Stack->push(40);
    int_Stack->push(50);
    int_Stack->top(data);
    std::cout << "Top: " << data << std::endl;
    int_Stack->pop(data);
    std::cout << "Popped Data is:" << data << std::endl;
    int_Stack->push(60);
    int_Stack->push(70);
    int_Stack->top(data);
    std::cout << "Top: " << data << std::endl;

    //Character Stack with maximum size 2
    std::cout << "****Character Stack*****" << std::endl;
    Stack<char> *char_Stack = new ArrayStack<char>(2);
    char_Stack->push('a');
    char_Stack->push('b');
    char_Stack->push('c');
    char data_char;
    char_Stack->top(data_char);
    std::cout << "Top: " << data_char << std::endl;
    char_Stack->pop(data_char);
    std::cout << "Popped Data: " << data_char << std::endl;
    char_Stack->top(data_char);
    std::cout << "Top: " << data_char << std::endl;
    char_Stack->pop(data_char);
    std::cout << "Popped Data: " << data_char << std::endl;
    char_Stack->top(data_char);

    // Circular Queue with n-1 space used
    Queue <int> *int_Queue = new ArrayQueue <int> (4);
    std::cout<<"****Integer Queue*****"<<std::endl;
    int_Queue->enqueue(2);
    int_Queue->enqueue(5);
    std::cout << "Dequeuing:" << int_Queue->dequeue() << std::endl;
    int_Queue->front();
    int_Queue->back();
    int_Queue->enqueue(4);
    std::cout << "Dequeuing:" << int_Queue->dequeue() << std::endl;
    int_Queue->front();
    int_Queue->back();
    int_Queue->enqueue(3);
    int_Queue->enqueue(7);

    std::cout <<"*****Character Queue *****" << std::endl;
    Queue<char> *char_Queue = new ArrayQueue<char>(3);
    char_Queue->enqueue('a');
    char_Queue->enqueue('b');
    char_Queue->enqueue('z');
    char data_char_a;
    char_Queue->front();
    char_Queue->back();
    std::cout << "Dequeuing:" << char_Queue->dequeue() << std::endl;
    char_Queue->front();
    char_Queue->back();
    std::cout << "Dequeuing:" << char_Queue->dequeue() << std::endl;
    char_Queue->front();
    char_Queue->back();
    std::cout << "Dequeuing:" << char_Queue->dequeue() << std::endl;
    char_Queue->front();
    char_Queue->back();

    // std::cout << "Rear: " << data_char_a << std::endl;
}
