#include "DoublyLinkedList.h"

// Node constructor
Node::Node(int value) : data(value), prev(nullptr), next(nullptr), prevEvenOdd(nullptr), nextEvenOdd(nullptr) {}

// DoublyLinkedList constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr), headEven(nullptr), headOdd(nullptr) {}

// Find a node with a specific value
Node* DoublyLinkedList::findNode(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

// Insert a node in ascending order
void DoublyLinkedList::insertDescending(Node* newNode) {
    if (!head || head->data > newNode->data) { // New node is the smallest or list is empty
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
    }
    else { // Insert in ascending order
        Node* current = head;
        while (current->next && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

// Update sub-lists for even and odd numbers
void DoublyLinkedList::updateSubList(Node* newNode) {
    Node** subListHead = (newNode->data % 2 == 0) ? &headEven : &headOdd;
    Node* current = *subListHead;
    if (!current || current->data > newNode->data) { // New node is the smallest
        newNode->nextEvenOdd = *subListHead;
        if (*subListHead) (*subListHead)->prevEvenOdd = newNode;
        *subListHead = newNode;
    }
    else { // Insert in ascending order
        while (current->nextEvenOdd && current->nextEvenOdd->data < newNode->data) {
            current = current->nextEvenOdd;
        }
        newNode->nextEvenOdd = current->nextEvenOdd;
        if (current->nextEvenOdd) current->nextEvenOdd->prevEvenOdd = newNode;
        current->nextEvenOdd = newNode;
        newNode->prevEvenOdd = current;
    }
}

// Add a value to the list
void DoublyLinkedList::add(int value) {
    if (value <= 0) throw invalid_argument("Value must be greater than 0.");
    if (findNode(value)) throw invalid_argument("Value already exists in the list.");
    Node* newNode = new Node(value);
    insertDescending(newNode);
    updateSubList(newNode);
}

// Delete a value from the list
void DoublyLinkedList::deleteValue(int value) {
    Node* target = findNode(value);
    if (!target) throw invalid_argument("Value not found in the list.");
    if (target->prev) target->prev->next = target->next;
    if (target->next) target->next->prev = target->prev;
    if (head == target) head = target->next;

    Node** subListHead = (value % 2 == 0) ? &headEven : &headOdd;
    if (*subListHead == target) {
        *subListHead = target->nextEvenOdd;
    }
    else {
        Node* current = *subListHead;
        while (current && current->nextEvenOdd != target) {
            current = current->nextEvenOdd;
        }
        if (current) current->nextEvenOdd = target->nextEvenOdd;
    }
    delete target;
}

// Print the list
void DoublyLinkedList::print(char listType, char order) {
    Node* current = nullptr;
    if (listType == 'E') current = headEven;
    else if (listType == 'O') current = headOdd;
    else current = head;

    if (order == 'A') { // Ascending order
        while (current) {
            cout << current->data << " ";
            current = (listType == 'E' || listType == 'O') ? current->nextEvenOdd : current->next;
        }
    }
    else { // Descending order
        while (current && ((listType == 'E' || listType == 'O') ? current->nextEvenOdd : current->next)) {
            current = (listType == 'E' || listType == 'O') ? current->nextEvenOdd : current->next;
        }
        while (current) {
            cout << current->data << " ";
            current = (listType == 'E' || listType == 'O') ? current->prevEvenOdd : current->prev;
        }
    }
    cout << endl;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
