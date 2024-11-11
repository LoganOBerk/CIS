#include <iostream>
using namespace std;


struct Node {
	long myData;
	Node* nextNode;
};

void insertNode(Node* nodeVar, Node*& head) {
	if (!head) { //empty list?
		head = nodeVar;
	}
	else {
		if (head->myData >= nodeVar->myData) { //insert after head
			if (head->myData == nodeVar->myData) {
				return;
			}
			//find insert location
			Node* tempPtr = head,
				* prevPtr = nullptr;
			while (tempPtr && tempPtr->myData >= nodeVar->myData) {
				prevPtr = tempPtr;
				tempPtr = tempPtr->nextNode;
			}
			if (prevPtr->myData == nodeVar->myData) {
				cout << "matching value" << endl;
				return;
			}
			prevPtr->nextNode = nodeVar;
			nodeVar->nextNode = tempPtr;
			//head->nextNode = nodeVar;
		}
		else {
			nodeVar->nextNode = head;
			head = nodeVar;
		}
	}
}

void printList(Node* listPtr) {
	while (listPtr) {
		cout << listPtr->myData << endl;
		listPtr = listPtr->nextNode;
	}
}

//decreasing order
int main() {
	Node* headNode = nullptr, * localNode;

	localNode = new Node;
	localNode->myData = 88;
	localNode->nextNode = nullptr;
	insertNode(localNode, headNode);
	localNode = nullptr;
	printList(headNode);
	cout << endl;
	
	localNode = new Node;
	localNode->myData = -14;
	localNode->nextNode = nullptr;
	insertNode(localNode, headNode);
	printList(headNode);
	cout << endl;
	
	localNode = new Node;
	localNode->myData = 100;
	localNode->nextNode = nullptr;
	insertNode(localNode, headNode);
	localNode = nullptr;
	printList(headNode);
	cout << endl;

	localNode = new Node;
	localNode->myData = 35;
	localNode->nextNode = nullptr;
	insertNode(localNode, headNode);
	localNode = nullptr;
	printList(headNode);
	cout << endl;
	
	return 0;
}