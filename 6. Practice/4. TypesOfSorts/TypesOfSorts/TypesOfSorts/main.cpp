#include <iostream>
#include <vector>

using namespace std;

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

void bubbleSortArr(int* arr, int size) {
	//placeholder for current elm
	int currElm = 0;
	//size to itterate through for comparisons
	int lastUnsorted = size - 1;
	//flag to check if there was a swap
	bool swap = true;
	int i;
	while (swap) {
		//start at index 0 every itteration
		i = 0;
		swap = false;
		for (i; i < lastUnsorted; i++) {
			//check if the elements adjacent is greater than
			if (arr[i] > arr[i + 1]) {
				//swap the current elm with the adjacent if greater than
				currElm = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = currElm;
				swap = true;
			};
		}
		//reduce itteration size as the last element of each itteration will be a sorted element
		lastUnsorted--;
	}
}

void merge(int* arr, int* leftArr, int* rightArr, int left, int right) {
	int i = 0, j = 0, k = 0;
	
	while (i < left && j < right) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}

	while (i < left) {
		arr[k++] = leftArr[i++];
	}

	while (j < right) {
		arr[k++] = rightArr[j++];
	}
	
}
void mergeSortArr(int* arr, int size) {
	int left;
	int right;
	if (size == 1) {
		return;
	}
	if (size % 2 == 0) {
		left = size / 2;
		right = size / 2;
	}
	else {
		left = size / 2;
		right = size / 2 + 1;
	}

	int* leftArr = new int[left];
	int* rightArr = new int[right];
	
	for (int i = 0; i < left; i++) {
		leftArr[i] = arr[i];
	}
	
	for (int j = 0; j < right; j++) {
		rightArr[j] = arr[left + j];
	}

	mergeSortArr(leftArr, left);
	mergeSortArr(rightArr, right);

	merge(arr, leftArr, rightArr, left, right);
	
	delete[] leftArr;
	delete[] rightArr;
}

void insertionSortArr(int* arr, int size) {
	int curr;
	for (int i = 0; i < size; i++) {
		curr = arr[i];
		for (int j = 0; j < size; j++) {
			
			
		}

	}
}

int main() {
	int size = 5;
	int* arr = new int[size];
	initArr(arr, size);
	displayArr(arr, size);
	insertionSortArr(arr, size);
	displayArr(arr, size);

	return 0;
}