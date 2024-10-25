#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int recursiveLinearSearch(const int arr[], const int key, const int size, bool& searchStatus) {
	if (size == 0) {
		return size;
	}
	if (arr[size - 1] == key) {
		searchStatus = true;
		return size;
	}
	return recursiveLinearSearch(arr, key, size - 1, searchStatus);
}


int main() {
	const int SIZE = 7000;
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

	int numsearches = sizeof(myArray)/sizeof(myArray[0]) - recursiveLinearSearch(myArray, key, SIZE, searchStatus);
	if (searchStatus) {
		cout << "Found " << key << " after " << numsearches + 1 << " searches" << endl;
		
	}
	else {
		cout << "Not found after " << numsearches << " searches";
		
	}
	return 0;
}