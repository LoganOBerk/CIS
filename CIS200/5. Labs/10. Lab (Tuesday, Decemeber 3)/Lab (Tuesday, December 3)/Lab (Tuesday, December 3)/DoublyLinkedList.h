#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* prevEvenOdd;
    Node* nextEvenOdd;

    Node(int value);
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* headEven;
    Node* headOdd;

    Node* findNode(int value);
    void insertDescending(Node* newNode);
    void updateSubList(Node* newNode);

public:
    DoublyLinkedList();
    void add(int value);
    void deleteValue(int value);
    void print(char listType, char order);
    ~DoublyLinkedList();
};

#endif
