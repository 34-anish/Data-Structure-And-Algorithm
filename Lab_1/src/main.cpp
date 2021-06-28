#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
    std::cout << "----Linked List---- " << std::endl;
    LinkedList list;
    list.removeFromHead();
    list.addToHead(5);
    list.traverse();
    list.removeFromHead();
    list.traverse();
    list.removeFromHead();
    list.traverse();

    int in_linkedlist = 10;
    int notin_linkedlist = 69;
    list.addToHead(5);
    list.addToHead(in_linkedlist);
    list.traverse();
    list.search(in_linkedlist);
    list.search(notin_linkedlist);
    Node *outputptr;
    std::cout << "Memory address of " << notin_linkedlist << " is: " << list.retrieve(69, outputptr) << std::endl;
    std::cout << "Memory address of " << in_linkedlist << " is: " << list.retrieve(10, outputptr) << std::endl;

    // Adding a new number after 5
    Node *predecessor = list.retrieve(5, outputptr);
    list.add(0, predecessor);
    list.traverse();

    list.addToHead(25);
    list.traverse();
    list.removeFromTail();
    list.traverse();
    list.removeFromHead();
    list.traverse();

    list.removeFromHead();
    list.traverse();

    std::cout << " --------STACK OPERATION--------" << std::endl;

    LinkedStack a;
    a.top();
    a.push(5);
    a.top();
    a.push(10);
    a.top();
    a.pop();
    a.top();
    a.pop();
    a.top();
    a.pop();
    a.top();

    std::cout << "----Queue operation  ----" << std::endl;
    LinkedQueue a1;
    a1.front();
    a1.enqueue(6);
    a1.front();
    a1.rear();
    a1.enqueue(7);
    a1.front();
    a1.rear();
    a1.enqueue(8);
    a1.front();
    a1.rear();
    a1.dequeue();
    a1.front();
    a1.rear();
    a1.dequeue();
    a1.front();
    a1.rear();
    a1.dequeue();
    a1.front();
    a1.rear();
    a1.dequeue();
    a1.front();
    a1.rear();
}
