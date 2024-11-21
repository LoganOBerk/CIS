#include <iostream>

using namespace std;

int main() {

	//Selection Sort
	//divides the list into two parts: the sub-list of sorted items(built from left to right)
	//search find smallest swap with first and continue recursive
	//O(N^2) is worst case
	//
	//Bubble Sort
	//also refered to as a sinking sort
	//larger values viewed as heavier sink to buttom
	//smaller values viewed as lighter, therfore bubble up to top of list
	// 
	//step through list to be sorted 
	//comparing neighboring elements then swap based on weights
	//until no more swaps occur
	//Worst Case O(n^2)
	//Best Case O(n) comparisons, O(1)
	// 
	//Insertion sort
	//In-place comparison sort
	//Usually beats both selection sort and bubble sort on average
	//Can think of this sort as similar to ordering cards in a players hand
	//
	//itterated through the list and grows a sorted list 1 element at a time
	//consider first element sorted then place next item in list in order
	//
	//Quick sort
	//partial exchange sort
	//much more efficient sorting algorithm but more complex
	//in-place comparison sort not a stable sort
	//identical elements are not sorted in the same order they appear in input
	//
	//divide and conquer algorithm
	//pick an element called a pivot from the list
	//
	//if there is more than one item in values[first]...values[last]
	//select splitVal //pivot point
	//split the array so that
	//
	//KNOW WHICH IS MORE EFFICIENT HARDEST TO IMPLEMENT AND WHAT EACH SORT IS
	//Most efficient Quick sort
	//
	//Merge Sort
	//divide list into n sublist until each sublist contains exactly 1 element
	//merge repeatedly merge sublists to produce new sorted sublists, until only one sorted sublist remains
	//
	//Heap Sort
	//comparison sort, think of it as an improved selection sort
	//based on binary heap data structure
	//in terms of a linked list a node can have 0 1 or 2 children
	//a complete binary tree is when every level is filled except possibly last and all nodes are as far left as possible
	//gaps are on lowest level right hand side
	//
	//simple sorts
	//straight selection sort
	//bubble sort
	//insertion sort
	//
	//complex
	//quick sort
	//merge sort
	//heap sort
	//
	//
	//Lists vs Sorted Lists
	//operations
	//Ref other ADTs for the overlapping operations for basic operations
	//isEmpty()
	//getLength()
	//insertPosition()
	//deletePosition()
	//clear()
	//getEntry()
	//getPosition()
	//search()
	//
	//getPosition() returns position if found
	//
	//cointainer adapter
	//sequence container
	//associative container


	return 0;
}