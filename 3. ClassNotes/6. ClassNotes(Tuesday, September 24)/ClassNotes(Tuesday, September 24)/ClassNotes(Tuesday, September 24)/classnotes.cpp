#include <iostream>
#include <string>

using namespace std;

class Student;


//char** argv can be written as char *argv[]
int main(int argc, const char **argv) { //used to pass arguments into main argc = arg count, argv = arg value
	int args = 1;

	cout << "The program is called " << *argv << endl; //gives address from windows
	//argc counts the arguments inside the debugger
	cout << "It has " << argc - 1 << " arguments:\n";

	while (args < argc) {
		cout << *(argv + args) << endl;
		++args;
	}

	//pointers arrays
	const int SIZE = 5;
	int number[SIZE];
	//all the same starts at index 0
	cout << "number :" << number;              
	cout << "&number :" << &number;
	cout << "&number[0]" << &number[0];

	//incrementing addresses
	int* P, x[10];
	P = &x[3];
	P++; //moves to next address

	
	for (int x = 0; x < SIZE; ++x) {
		//array notation
		cout << number[x];
	}

	
	for (int x = 0; x < SIZE; ++x) {
		//array offset notation uses arrayname
		cout << *(number + x);
	}

	
	for (int x = 0; x < SIZE; ++x, P++) {
		//pointer notation 
		cout << *P;
		cout << *P++;
	}

	
	for (int x = 0; x < SIZE; x++) {
		//pointer offset notation uses specific pointer
		cout << *(P + x);
	}

	//dynamically allocate memory using new

	new int; //returns memory address sized for int

	int* intPtr;
	intPtr = new int; //unless used immediately, always set nullptr
	*intPtr = 0;

	cout << *intPtr << endl;
	cout << intPtr << endl;

	//at the end of use we delete the new memory allocation
	delete intPtr;

	intPtr = nullptr;

	//can use the new keyword to assign a new memory location to an object

	Student *studentPtr;
	/*
	//this -> derefrences the pointer and calls its function
	studentPtr->setAll()
	*/
	return 0;
};