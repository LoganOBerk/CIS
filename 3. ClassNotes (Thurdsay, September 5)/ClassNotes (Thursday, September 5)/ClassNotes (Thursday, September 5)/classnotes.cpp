#include "practicefornewfiles.h"

using namespace std;

void printx2(int a) {
	cout << a * 2 << " ";
}
int main() {

	/*
	
	//for each loop
	int numbers[] = { 1,2,3,4,5 };
	for (int number : numbers) {
		cout << number << ' ';
		cout << endl;

	}

	//for each loop, auto finds the datatype automatically
	int numbers[] = { 1,2,3,4,5 };
	for (auto number : numbers) {
		cout << number << ' ';
		cout << endl;

	}

	//for each loop, which allows the editing of array
	int numbers[] = { 1,2,3,4,5 };
	for (auto &number : numbers) {
		number *= 2;

	}

	//not allowed, pass by refrence variables are optimal for functions
	//If we do not want our variable to be modified we can use const but still use pass by refrence
	int numbers[] = { 1,2,3,4,5 };
	for (const auto &number : numbers) {
		
		number *= 2;
	

	}


	const int SIZE = 5;
	int arr[SIZE] = { 1,5,2,18,3 };
	cout << "Multiple of 2 of elements are: ";
		for_each(arr, arr + SIZE, printx2);
		//first value is where to start, second is where to stop(excluded)
		for_each(arr + 2, arr + 3, printx2);
		cout << endl;

	//objects and classes
	//ctrl + f is find and replace, quick replace which allows you to replace multiple instances of a character
	practicefornewfiles.h
	practicefornewfiles.cpp
		*/


	string messag = msg();
	cout << messag << endl;

	return 0;
}