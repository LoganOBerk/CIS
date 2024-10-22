#include "funcs.h"

int main() {
	const int SIZE = 2000;
	bool searchStatus = false;
	int myArray[SIZE];
	for (int i = 0; i < SIZE; i++) {
		myArray[i] = i + 1;
	}

	int input;

		
		cout << "Please enter key: ";
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter key: ";
		}
	const int key = input;
	
	recursiveLinearSearch(myArray, key, SIZE, searchStatus);
	if (searchStatus) {
		cout << "found" << endl;
		cout << key << " after " << i + 1 << " searches" << endl;
		i = 0;
	}
	else {
		cout << "Not found after " << i << " searches";
		i = 0;
	}
	cout << endl;

	cout << "Enter a number to take the factorial of: ";
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a number to take the factorial of: ";
	}
		
	cout << factorial(input);

	return 0;
}