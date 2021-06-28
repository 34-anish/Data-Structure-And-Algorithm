#pragma once

class Node
{
public:
    int info;
    Node *next;

    Node() : next(nullptr) {}

    Node(int info, Node *next) : info(info), next(next) {}
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    void addToHead(const int data);
    void addToTail(const int data);
    void traverse(const char separator = ' ') const;
    void removeFromHead();
    void removeFromTail();
    int peekFromHead() const;
    int peekFromTail() const;
    void remove(int data);

    bool search(int data) const;

    void add(const int data, Node *predecessor);

    Node *retrieve(int data, Node *dataOutPtr) const;

private:
    Node *HEAD;
    Node *TAIL;
};
