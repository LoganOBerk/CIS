#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int i = 0;
int recursiveLinearSearch(const int arr[], const int key, const int size, bool& searchStatus) {
	if (i == size) {
		return i;
	}
	if (arr[i] == key) {
		searchStatus = true;
		return i;
	}
	i++;
	return recursiveLinearSearch(arr, key, size, searchStatus);
}


int main() {
	const int SIZE = 8000;
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
		cout << "Found " << key << " after " << i + 1 << " searches" << endl;
		i = 0;
	}
	else {
		cout << "Not found after " << i << " searches";
		i = 0;
	}
	return 0;
}