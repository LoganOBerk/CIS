#include <iostream>

//SEARCH ALGORITHMS
	//	-linear search
	//	-bianary search
	//  -hashing

//LINEAR SEARCH
//works with sorted/ unsorted
int search(int arr[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

//Worst Case O(n)
//Best Case O(1)
//Average Case
//	if successful (n+1)/2
//	unsuccessful n
//	combined simplifies to O(n)

//BINARY SEARCH
//only works with sorted
int binarySearch(int arr[], int l, int r, int x) {
	int m = l + (r - 1) / 2;

	if (arr[m] == x) {
		return m;
	}
	if (arr[m] < x) {
		l = m + 1;
	}
	if (arr[m] > x) {
		r = m - 1;
	}
}

//Worst Case O(logn)
//Best Case O(1)

//HASHING 
//converts a value to another unique value and the unique value is then used as the index in a hash table if the value is an int
//what if two keys have the same value?
//	this results in a collision
//Collision handling
//	Chaining: Make each cell of hash table point to a linked list of records that have same hash function value
//		requires additional memory outside of the table
//	Open Addressing: Each table entry contains a record or NIL(not in list)
//		every entry stored in table
//
//Hash(key) = num % 100;
//
//tendancy of elements to become unevently distributed
//Solutions:
//	linear probing with a constant (HashValue + constant) % array_size
//  quadratic probing (HashValue + i^2) % array_size
//	random probing Uses a pseudo-random number generator to determine the increment to HashValue
//	Bucket or Chain a bucket or a linked list of elements is created when collisions occur
//
//Worst Case O(n)
//Best O(1)
//Average O(1)
//Your hash is unique to the value and once you go to the index based on your hash then you have to check if you have a linked list which value you want
//
//Tree/Graph
//	-breadth first
//	-depth first
//	-best first
//	-A*
//	Branch and Bound


int main() {

	//doubly linked list contains a pointer to next and previous pointer
	//circular linked list regular doubly but connecting ends so that there arent null pointers

	

	return 0;
}