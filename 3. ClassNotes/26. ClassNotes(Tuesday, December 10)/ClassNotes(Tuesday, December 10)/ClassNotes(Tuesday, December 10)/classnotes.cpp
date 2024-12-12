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

	return 0;
}
