#include <iostream>

int main() {

	// FINAL EXAM REVIEW

	// 1. FRIEND FUNCTIONS
	// - How to declare a friend function (mid+ level):
	//   Syntax: Use the `friend` keyword in the class definition.
	// - Friend functions are one-directional:
	//   Only the specified function or class has access to the private/protected members.

	// 2. MEMORY AND POINTERS
	// - Bytes for basic variables (know sizes for `int`, `float`, `double`, etc.).
	// - Why use a pointer to a pointer?
	//   Example: To pass by reference in a function, you can use `**` to modify the actual value directly.
	// - When is `**` usage good in the context of a linked list?
	//   Example: For modifying pointers themselves (e.g., reassigning head pointers).

	// 3. LINKED LISTS
	// - Variations:
	//   - Singly linked list: Can traverse only forward.
	//   - Circular linked list: Last node links back to the first.
	//   - Doubly linked circular list: Traverse both forward and backward.
	// - Operations:
	//   - Insert, delete, traverse.
	// - Node structure:
	//   - Know dynamic and regular implementations for singly and doubly linked lists.
	// - Be able to write a recursive insert into a linked list.

	// 4. ABSTRACT DATA TYPES (ADTs)
	// - Types: Stack, List, Heap, Queue, Priority Queue (queue within a queue).
	// - Standard functions for ADTs:
	//   - Add
	//   - Delete
	//   - Clear
	//   - Binary operations (check if full or empty).
	// - Binding:
	//   - Early binding: Compile-time.
	//   - Late binding: Runtime (dynamic memory).

	// 5. UML (Unified Modeling Language)
	// - Three components of a UML diagram:
	//   1. Class Name
	//   2. Attributes
	//   3. Methods
	// - Access modifiers:
	//   - Public: `+`
	//   - Private: `-`
	//   - Protected: `#`

	// 6. SORTING AND RECURSION
	// - Types of sorts (know key algorithms and their complexities).
	// - Basic recursion:
	//   - Understand how recursive functions work and termination conditions.

	// 7. LISTS
	// - Unordered collection of items.
	// - Hashing:
	//   - Assign an index to a value based on its data.
	//   - Problem: Collisions.
	//   - Goal: Ensure even distribution of values across indices.

	// 8. SEARCHING
	// - Basic binary search:
	//   - Complexity: O(log n).
	// - Recursive insertion into linked list (know the implementation).
	// - Common ADT methods (5 most frequent):
	//   Example: Insert, Remove, Search, Traverse, Update.

	// 9. TREES
	// - Definitions:
	//   - Complete Tree: Only gaps are on the rightmost positions of the lowest level.
	//   - Full Tree: All nodes have either 0 or 2 children.
	//   - Binary Tree: Each node has at most 2 children.
	//   - Binary Search Tree: A binary tree with ordered nodes (left < root < right).
	// - AVL Tree basics:
	//   - Balance factor: Max weight difference is ±1.
	//   - Rebalancing: After balance factor exceeds ±2.
	// - Traversal orders:
	//   - Pre-order: NLR (Node, Left, Right).
	//   - Post-order: LRN (Left, Right, Node).
	//   - In-order: LNR (Left, Node, Right).

	// 10. ARRAYS
	// - Array memory access:
	//   - Example:
	//     ```cpp
	//     int x[10];
	//     int* ptr = x; // Equivalent to &x[0]
	//     ```
	// - Formulas for parent and child nodes in an array-based representation of a binary tree:
	//   - Left child: `2 * i + 1`
	//   - Right child: `2 * i + 2`
	//   - Parent: `(i - 1) / 2`

	// Section 1: Friend Functions

// 1.1 Write a class MyClass that declares a friend function printData.
#include <iostream>
	class MyClass {
	private:
		int data;
	public:
		MyClass(int value) : data(value) {}
		friend void printData(const MyClass& obj);
	};

	void printData(const MyClass & obj) {
		std::cout << "Data: " << obj.data << std::endl;
	}


	// 1.2 Explain why friend functions are one-directional in nature.
	// Friend functions break encapsulation for specific purposes, allowing access to private/protected members of a class.
	// They do not provide reciprocal access to the friend function's scope.
	// Use Case: Overloading operators like << for output streams.

	// Section 2: Memory and Pointers

	// 2.1 Match data types to their sizes (typical 64-bit system):
	// int: 4 bytes, double: 8 bytes, char: 1 byte, bool: 1 byte, float: 4 bytes.

	// 2.2 Function using a pointer to a pointer to modify an integer.
	void modifyValue(int** ptr) {
		**ptr = 42;
	}

	// Explanation: The pointer-to-pointer gives indirect access to the integer value, allowing modifications at multiple indirection levels.

	// 2.3 Scenario for using pointer-to-pointer: Managing a double pointer in a linked list to add or remove nodes efficiently.

	// Section 3: Linked Lists

	// 3.1 Function to insert a new node recursively into a sorted singly linked list.
	struct Node {
		int data;
		Node* next;
	};

	Node* insertRecursively(Node * head, int value) {
		if (!head || head->data >= value) {
			Node* newNode = new Node{ value, head };
			return newNode;
		}
		head->next = insertRecursively(head->next, value);
		return head;
	}

	// 3.2 Differences between linked lists:
	// Singly Linked List: Nodes link to the next; use case: simple data structures.
	// Circular Linked List: Last node points to the first; use case: round-robin scheduling.
	// Doubly Linked List: Nodes link to both next and previous; use case: bidirectional traversal.

	// Section 4: Abstract Data Types (ADTs)

	// 4.1 Definitions of ADTs:
	// Stack: LIFO structure (e.g., function calls).
	// Queue: FIFO structure (e.g., task scheduling).
	// Priority Queue: Elements with priorities (e.g., Dijkstra's algorithm).

	// 4.2 Early vs. Late Binding:
	// Early Binding: Compile-time method selection (e.g., function overloading).
	// Late Binding: Runtime method selection (e.g., virtual functions).

	// Section 5: UML

	// 5.1 UML Diagram for Book class:
	// +-------------------+
	// |       Book        |
	// +-------------------+
	// |- title: string    |
	// |- author: string   |
	// # price: double     |
	// +-------------------+
	// |+ getTitle(): string|
	// |+ setPrice(double): void|
	// +-------------------+

	// 5.2 Significance of symbols:
	// +: Public, -: Private, #: Protected.

	// Section 6: Sorting and Recursion

	// 6.1 Sorting algorithms:
	// Bubble Sort: O(n^2), simple but inefficient.
	// Merge Sort: O(n log n), efficient divide-and-conquer.

	// 6.2 Recursive factorial function:
	int factorial(int n) {
		return (n <= 1) ? 1 : n * factorial(n - 1);
	}

	// Section 7: Lists and Hashing

	// 7.1 Definition of unordered list:
	// An unordered list has no specific order, unlike an ordered list where elements follow a sequence.

	// 7.2 Hashing concept:
	// Converts keys to indices in a hash table. Main problem: collisions.
	// Mitigation: Use separate chaining or open addressing.

	// Section 8: Searching

	// 8.1 Binary search function:
	int binarySearch(int arr[], int size, int target) {
		int left = 0, right = size - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] == target) return mid;
			if (arr[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}

	// 8.2 Five common ADT methods:
	// add, delete, clear, isFull, isEmpty.

	// Section 9: Trees

	// 9.1 Definitions:
	// Complete Tree: All levels filled except possibly the last, leftmost nodes filled.
	// Full Tree: All nodes have 0 or 2 children.
	// Binary Tree: Each node has at most 2 children.

	// 9.2 Binary tree array representation:
	// Array: [10, 5, 20, 3, 7, 15, 30]
	// Parent of index 5: index 2 (20).
	// Left child of index 2: index 5 (15).
	// Right child of index 2: index 6 (30).

	// 9.3 AVL tree rebalancing:
	// Performed after insertion/deletion if balance factor = |height(left) - height(right)| > 1.
	// Rotations: Left, Right, Left-Right, Right-Left.

	// Section 10: Arrays

	// 10.1 Accessing elements using pointer arithmetic:
	int arr[10] = { 0 };
	*(arr + 2) = 5; // Equivalent to arr[2] = 5;

	// 10.2 Array-based binary tree formulas:
	// Parent: (i - 1) / 2.
	// Left child: 2 * i + 1.
	// Right child: 2 * i + 2.

	return 0;
}
