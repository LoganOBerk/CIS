#include <iostream>
#include <random>

using namespace std;

int main(int argc, const char *argv[]) {

	int X[] = { 13, 17, 21, 27, 33 };
	int* xPtr = &X[2];
	//xPtr address location is moved back one and then derefrenced
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << *--xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Here we are derefrencing the -- operator which results in compiler error
	/*
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << (*--)xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	*/


	//Here we are derefrencing xPtr and as a result we get our 3rd position 21 and then decrementing by 1 so we get 20
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << -- * xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Here we are derefrencing xPtr and as a result we get our 3rd position 21 and then decrementing by 1 so we get 20
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << --(*xPtr);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Here we are decrementing the star operator resulting in a compiler error
	/*
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << (--*)xPtr;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	*/

	//Here we are derefrencing xPtr and then decrementing after the cout statement so our output is 21 and after its 20
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << *xPtr--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Here we are derefrencing xPtr and then decrementing after the cout statement so our output is 21 and after its 20
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << (*xPtr)--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Here we are derefrencing xPtr and then decrementing after the cout statement so our output is 21 and after its 20
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << *(xPtr)--;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	
	//Here we are derefrencing 
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << *(xPtr--);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Array content prior to pointer manipulation\n";
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << *(--xPtr);
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	int nums[100];
	int* numsPtr = nums;
	const int MIN = -39;
	const int MAX = 117;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(MIN, MAX);
	for (int i = 0; i < 100; i++) {
		int rand = distrib(gen);
		nums[i] = rand;
	}

	for (int i = 0; i < 100; i++) {
		cout << *(nums + i) << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 100; i++) {
		cout << nums[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 100; i++, numsPtr++) {
		if (*numsPtr < 0) {
			cout << *numsPtr << " ";
		}
		else {
			i++;
		}
	}
	cout << endl << endl;
	
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

	cout << "Executible : " << *argv << endl;
	for (int i = 1; i < argc; i++) {
		cout << "Argument " << i << " " << argv[i] << endl;
	}


	return 0;
};