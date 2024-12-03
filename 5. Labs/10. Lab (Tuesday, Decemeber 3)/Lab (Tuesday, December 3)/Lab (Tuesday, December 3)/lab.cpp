#include "labFuncs.h"

int main() {
	fstream file("integer.dat", ios::in | ios::out | ios::binary | ios::trunc);
	int size = 7;
	int* fileContents = new int[size];
	Node* head = nullptr;
	initFile(file, fileContents, size);
	printFileContents(file);

	file.close();
	return 0;
}