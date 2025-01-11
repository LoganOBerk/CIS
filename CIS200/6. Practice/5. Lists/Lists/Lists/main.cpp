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
	if (!head || head->data >= value) {
		nodeToAdd->next = head;
		head = nodeToAdd;
		return;
	}
	
	while (currentNode->next && currentNode->next->data < value) {
		currentNode = currentNode->next;
	}
	nodeToAdd->next = currentNode->next;
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

int binSearch(int arr[], int size, int value) {
	int left = 0, right = size - 1;
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == value) return mid;
		if (arr[mid] < value) left = mid + 1;
		else right = mid - 1;
	}
	return binSearch(arr, left + right , value);
}

int binarySearch(int arr[], int left, int right, int target) {
	if (left > right) {
		return -1; // Element not found
	}

	int mid = left + (right - left) / 2;

	// Check if the target is at the middle
	if (arr[mid] == target) {
		return mid;
	}

	// If target is smaller, search the left half
	if (target < arr[mid]) {
		return binarySearch(arr, left, mid - 1, target);
	}

	// If target is larger, search the right half
	return binarySearch(arr, mid + 1, right, target);
}

int main() {

	SinglyNode* head = nullptr;

	insert(head, 3);
	insert(head, 1);
	insert(head, 0);
	printList(head);

	remove(&head, 3);
	printList(head);


	int arr[5] = {2,4,6,8,10};
	cout << binSearch(arr, 5, 10);
	
	
	

	return 0;
}