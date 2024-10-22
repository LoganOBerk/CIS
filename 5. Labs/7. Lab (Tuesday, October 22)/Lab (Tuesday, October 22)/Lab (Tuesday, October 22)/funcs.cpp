#include "funcs.h"



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

int a = 1;
int factorial(int x) {
	a *= x;
	x = x - 1;
	if (x - 1 == 0) {
		return a;
	}
	return factorial(x);
}
