#include <iostream>

using namespace std;
//LINKED LISTS
//	A list is a linear collection of like elements
//	Linear means each list element has a unique predecessor
//
//Programmer must
//	choose a concrete data representation for the list
//	implement the list operations
//
//Transformers
//	insert
//	delete
//
//Observers
//	is empty
//	is full etc..
//
//How to implement a list
//	use a built in array stored in contiguous memory locations
//	use a linked list (to avoid excessive data movement from insertions and deletions)
//		not necessarily stored in contigous memory locations
//
//Linked List
//	can be built-in dynamic data pointers or array or structs
//
//Linked list is a list in which the order is determined by the explicit link(pointer) member in each node
//	the nodes are typically structs but can be classes
//	each node contains a component member and also a link(pointer) member that gives the location of the next node in the list
//Dynamic linked list, nodes are linked together by pointers and an external pointer or head pointer points to the first node in the list
//	the link member (a pointer) holds the memeory address of the next node in the list
//if memory is avalible in an area called the free store(or heap), operator new allocates the requested object and returns a pointer to the memory allocated
struct Node {
	char info;
	Node* next;
};
typedef Node* NodePtr;

NodePtr head = nullptr;
NodePtr ptr;

//.info results in some char, .next results in some memory address

class SortedList2 {
	~SortedList2() {
		//delete each node
	}
	//same syntax inside a class
};

int main() {
	Node* ptr1; Node* ptr2;

	ptr1 = new Node;
	ptr1->info = 'A'; ptr1->next = nullptr;
	ptr2 = new Node;
	ptr2->info = 'B';
	ptr2->next = ptr1;
	ptr2->next->next = new Node;
	ptr2->next->info = 'C';
	ptr2->next->next->info = 'D';

	ptr = head;
	while (ptr != nullptr) {
		cout << ptr->info;
		ptr = ptr->next;
	}
	//insert at the front of the list
	NodePtr location = nullptr;
	location = new Node;
	location->info = 'A';
	location->next = head;
	head = location;

	//delete first node from the list
	char item = head->info;
	Node* tempPtr = head;
	head = head->next;
	delete tempPtr;
	tempPtr = nullptr;

	//algorithm to insert an item into its proper place ina sorted linked list
	//	find proper position for the new element in the sorted list obtain node for insertion and place item in it
	Node* currPtr = head;
	Node* prevPtr = nullptr;
	while (currPtr != nullptr && item > currPtr->info) {
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}

	return 0;
}