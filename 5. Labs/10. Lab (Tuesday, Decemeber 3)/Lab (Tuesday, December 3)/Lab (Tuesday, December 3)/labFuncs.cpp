#include "labFuncs.h"
int INTSIZE = sizeof(int);
void initFile(fstream& dataFile, int* arr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % size;
		dataFile.write(reinterpret_cast<const char*>(&arr[i]), INTSIZE);
	}
	dataFile.seekp(0, ios::beg);
};
void printFileContents(fstream& dataFile) {
	fileValidation(dataFile);
	int temp;
	while (dataFile.read(reinterpret_cast<char*>(&temp), INTSIZE)) {
		cout << temp << " ";
	}
	dataFile.seekg(0, ios::beg);
}
void fileValidation(fstream& currentFile) {
	currentFile.seekg(0, ios::end);
	if (!currentFile.is_open()) {
		cout << "File cant be read from!" << endl;
	}
	if (currentFile.tellg() == 0) {
		cout << "File is empty!" << endl;
	}
	currentFile.seekg(0, ios::beg);
};
void logError(fstream& errorLog) {

};
void printList(char& order) {

};

void initDoublyLinkedList(Node* head, fstream& dataFile) {
	int temp;
	dataFile.seekg(0, ios::beg);
	while (dataFile.read(reinterpret_cast<char*>(&temp), INTSIZE)) {
		Node* currentNode = new Node;
		currentNode->data = temp;
		if (!head) {
			head = currentNode;
		}
		
	}

}
void addInt(int& input) {

};
void deleteInt(int& input) {

};