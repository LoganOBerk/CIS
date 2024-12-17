#include <iostream>

using namespace std;


struct DoublyNode {
	int data;
	DoublyNode* prev;
	DoublyNode* next;
};
struct SinglyNode {
	int data;
	SinglyNode* next;

	SinglyNode(int d, SinglyNode* n = nullptr) : data(d), next(n){}
};

void printList(SinglyNode* head) {
	SinglyNode* currentNode = head;
	while (currentNode) {
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}

void insert(SinglyNode*& head, int value) {
	SinglyNode* currentNode = head;
	SinglyNode* nodeToAdd = new SinglyNode(value);
	if (!head) {
		head = nodeToAdd;
		return;
	}
	
	while (currentNode->next) {
		currentNode = currentNode->next;
	}
	currentNode->next = nodeToAdd;
}



void remove(SinglyNode** head, int value) {
	if (!(*head)) return;

	SinglyNode* current = *head;
	SinglyNode* prev = nullptr;
	while (current->next && current->data != value) {
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	delete current;
}

void insertSorted(SinglyNode*& head, int value) {
	SinglyNode* currentNode = head;
	SinglyNode* nodeToAdd = new SinglyNode(value);
	if (!head) {
		head = nodeToAdd;
		return;
	}

	while (currentNode->next && currentNode->data <= value) {
		currentNode = currentNode->next;
	}
	currentNode->next = nodeToAdd;
	if (currentNode->next) {
		nodeToAdd->next = currentNode->next->next;
	}
}

void insertSortedRecursive(SinglyNode*& head, int value) {
	SinglyNode* nodeToAdd = new SinglyNode(value);
	if (!head || head->data >= value) {
		nodeToAdd->next = head;
		head = nodeToAdd;
		return;
	}

	if (head->data <= value) {
		return insertSortedRecursive(head->next, value);
	}

}

void sort(SinglyNode** head, int value) {
	SinglyNode* node = new SinglyNode(value);
	if (!(*head) || (*head)->data >= value) {
		node->next = *head;
		*head = node;
		return;
	}

	SinglyNode* current = *head;
	while (current->next && current->data < value) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
}

int main() {

	SinglyNode* head = nullptr;

	sort(&head, 3);
	sort(&head, 1);
	sort(&head, 0);
	printList(head);

	remove(&head, 3);
	printList(head);
	
	
	

	return 0;
}