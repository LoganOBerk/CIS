/************************
* Programer Name: Logan Berk
*
* Purpose: Show how pointers can be used, args can be used, and how arrays can be accessed differently with pointers
*
* Create Date: 9/24/2024
*
* Modified Date: 9/24/2024
*************************/


#include <iostream>
#include <random>

using namespace std;

void question1();
void question2();

int main(int argc, const char *argv[]) {

	question1();
	question2();

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Printing Arguments/File path to .exe file" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Executible : " << *argv << endl;
	if (argc == 1) {
		cout << "There are 0 arguments at the moment." << endl;
	}
	for (int i = 1; i < argc; i++) {
		cout << "Argument " << i << ": " << argv[i] << endl;
	}


	return 0;
};

void question1() {
	int X[] = { 13, 17, 21, 27, 33 };
	int* xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *--xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *(--xPtr);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 20 << endl;
	cout << "\tActual   : " << -- * xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 20 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 20 << endl;
	cout << "\tActual   : " << --(*xPtr);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 20 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	/*
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << (*--)xPtr; //compiler error
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;


	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << (--*)xPtr; //compiler error
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	*/

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 21 << endl;
	cout << "\tActual   : " << *xPtr--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 21 << endl;
	cout << "\tActual   : " << (*xPtr)--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 20 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 21 << endl;
	cout << "\tActual   : " << *(xPtr)--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *xPtr << endl;

	X[0] = 13;
	X[1] = 17;
	X[2] = 21;
	X[3] = 27;
	X[4] = 33;
	xPtr = &X[2];

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 21 << endl;
	cout << "\tActual   : " << *(xPtr--);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "\tExpected : " << 17 << endl;
	cout << "\tActual   : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}
void question2() {
	int nums[100];
	int* numsPtr = nums;
	const int MIN = -39;
	const int MAX = 117;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(MIN, MAX);

	//Filling with random numbers
	for (int i = 0; i < 100; i++) {
		int rand = distrib(gen);
		nums[i] = rand;
	}
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array Notation print" << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < 100; i++) {
		cout << nums[i] << " ";
	}
	cout << endl << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array Offset Notation print" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 100; i++) {
		cout << *(nums + i) << " ";
	}
	cout << endl << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Pointer Notation print negative numbers" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 100; i++, numsPtr++) {
		if (*numsPtr < 0) {
			cout << *numsPtr << " ";
		}
		else {
			i++;
		}
	}
	cout << endl << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Pointer Offset Notation print numbers greater than 100" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	numsPtr = nums;
	for (int i = 0; i < 100; i++) {
		if (*(numsPtr + i) >= 100) {
			cout << *(numsPtr + i) << " ";
		}
		else {
			i++;
		}
	}
	cout << endl << endl;
}