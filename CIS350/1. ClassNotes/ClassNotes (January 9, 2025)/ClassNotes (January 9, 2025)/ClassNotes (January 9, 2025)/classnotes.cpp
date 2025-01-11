#include <iostream>

//PSUEDO CODE
//Algorithm arrayMin(A, n)
//	Input an array A of n integers
//	Output the minimum element of A
//		
//	currentMin <- A[0]
//	for i <- 1 to n - 1 do
//		if A[i] < currentMin then
//			currentMin <- A[i]
//	return currentMin 
int arrayMin(int* A, int n) {
	int currentMin = A[0];

	for (int i = 1; i < n; i++) {
		if (A[i] < currentMin) {
			currentMin = A[i];
		}
	}
	return currentMin;
}

int arrayMax(int* A, int n) {
	int currentMax = A[0];

	for (int i = 1; i < n; i++) {
		if (A[i] > currentMax) {
			currentMax = A[i];
		}
	}
	return currentMax;
}


int main() {

	int n = 100;
	int *arr = new int[n];
	srand((unsigned)time(NULL));
	
	for (int i = 0; i < n; i++) {
		arr[i] = 1 + (rand() % 100);
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << arrayMax(arr, n);

	std::cout << std::endl;
	std::cout << arrayMin(arr, n);
	

	return 0;
}