#include <iostream>
#include <vector>

using namespace std;

void selectionSortArr(int* arr, int size) {
	//initialize vars
	int minElm;
	int minElmIndex;
	for (int i = 0; i < size; i++) {
		//assume min value is the current element
		minElmIndex = i;
		minElm = arr[i];

		//start at the next element
		for (int j = i + 1; j < size; j++) {

			//find minimum element and its index
			if (minElm > arr[j]) {
				minElm = arr[j];
				minElmIndex = j;
			}

		}

		//swap the minimum element with the current element
		arr[minElmIndex] = arr[i];
		arr[i] = minElm;
		
	}
	
}

void displayArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void initArr(int* arr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % size;
	}
}

void selectionSortVec(vector<int>& vec) {
	
}

void displayVec(vector<int>& vec) {

}

void initVec(vector<int>& vec) {

}


int main() {
	int size = 5;
	int* arr = new int[size];
	initArr(arr, size);
	displayArr(arr, size);
	selectionSortArr(arr, size);
	displayArr(arr, size);

	return 0;
}