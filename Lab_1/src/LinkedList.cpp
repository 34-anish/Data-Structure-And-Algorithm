#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    HEAD = nullptr;
    TAIL = nullptr;
}

LinkedList::~LinkedList()
{
    delete TAIL;
}

//checks if the Linked List is empty or not
bool LinkedList::isEmpty() const
{
    return HEAD == nullptr && TAIL == nullptr;
}

//Adding an element to the Head
void LinkedList::addToHead(const int data)
{
    Node *newNode = new Node(data, HEAD);
    this->HEAD = newNode;

    if (this->TAIL == NULL)
    {
        this->TAIL = this->HEAD;
    }
}

//Adding an element to the Tail
void LinkedList::addToTail(const int data)
{
    Node *newNode = new Node(data, NULL);

    if (isEmpty())
    {

        this->HEAD = newNode;
        this->TAIL = newNode;
    }
    else
    {
        this->TAIL->next = newNode;
        this->TAIL = newNode;
    }
}

void LinkedList::traverse(const char separator) const
{
    if (isEmpty())
    {
        std::cout << "List is empty!" << std::endl;
    }
    else
    {
        std::cout << "List contains: " << std::endl;
        Node *tempNode = HEAD;
        while (tempNode != nullptr)
        {
            std::cout << tempNode->info << separator;
            tempNode = tempNode->next;
        }
        std::cout << std::endl;
    }
}

void LinkedList::removeFromHead()
{
    if (!isEmpty())
    {
        if (this->HEAD == this->TAIL)
        {
            TAIL = nullptr;
        }
        Node *nodetodelete = this->HEAD;
        HEAD = nodetodelete->next;
        delete nodetodelete;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

void LinkedList::removeFromTail()
{
    if (!isEmpty())
    {
        Node *nodetodelete = this->TAIL;
        if (HEAD == TAIL)
        {
            HEAD = nullptr;
            TAIL = nullptr;
        }
        else
        {
            Node *pred = HEAD;
            do
            {
                pred = pred->next;
            } while (pred->next != TAIL);

            TAIL = pred;
            pred->next = NULL;
        }

        delete nodetodelete;
    }

    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

int LinkedList ::peekFromHead() const
{
    if (!isEmpty())
    {
        return this->HEAD->info;
    }
    else
    {
        std::cout << "The list is empty" << std::endl;
        return -69;
    }
}

int LinkedList ::peekFromTail() const
{
    if (!isEmpty())
    {
        return this->TAIL->info;
    }
    else
    {
        std::cout << "The list is empty" << std::endl;
        return -69;
    }
}

void LinkedList::remove(int data)
{
    if (isEmpty())
    {
        std::cout << " List is empty" << std::endl;
    }
    else
    {
        if (HEAD->info == data)
        {
            removeFromHead();
        }
        else
        {
            Node *temp = HEAD->next;
            Node *prev = HEAD;
            while (temp != NULL)
            {
                if (temp->info == data)
                {
                    break;
                }
                else
                {
                    prev = prev->next;
                    temp = temp->next;
                }
            }
            if (temp != NULL)
            {
                prev->next = temp->next;
                delete temp;
                if (prev->next == nullptr)
                {
                    TAIL = prev;
                }
            }
            // else
            // {
            //     std::cout << "NO data found" <<std::endl;
            // }
        }
    }
}

bool LinkedList ::search(int data) const
{
    Node *p = HEAD;

    while (p != NULL && p->info != data)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        std::cout << "Did not find the element:" << data << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Found the element:" << data << std::endl;
        return 1;
    }
}

Node *LinkedList::retrieve(int data, Node *dataOutPtr) const
{
    Node *p = HEAD;

    while (p != NULL && p->info != data)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        std::cout << "Not found" << std::endl;
        return nullptr;
    }
    else
    {
        dataOutPtr = p;
        return dataOutPtr;
    }
}

void LinkedList ::add(const int data, Node *predecessor)
{
    if (isEmpty() || predecessor == nullptr)
    {
        addToHead(data);
    }
    else if (predecessor == TAIL)
    {
        addToTail(data);
    }
    else
    {
        Node *newNode = new Node(data, predecessor->next);
        predecessor->next = newNode;
    }
}
