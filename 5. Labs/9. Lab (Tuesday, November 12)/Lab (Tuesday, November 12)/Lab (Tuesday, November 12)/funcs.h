#define FUNCS_H
#ifdef FUNCS_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Record {
	int recordNumber;
	char toolname[21];
	int quantity;
	double cost;
};

struct Node {
	Record record;
	Node* next;
};

void unsortedLinkedList(Node*& nodeToAdd, Node* head) {
	if (!head) {
		head = nodeToAdd;
		nodeToAdd->next = nullptr;
	}
	else {
		head->next = nodeToAdd;
		nodeToAdd->next = nullptr;
	}
}
void getValidRecordNumber(Record*& myRecord) {

	int input;
	while(true){
		cin >> input;
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Record Number Try again: ";
		}
		else {
			break;
		}
	}
	myRecord->recordNumber = input;

}
void getValidTool(Record*& myRecord) {

	string input;
	string temp;
	bool wordStarted = false;
	getline(cin, input);
	int max;
	input.size() < 20 ? max = input.size() : max = 21;
	for (int i = 0; i < max; i++) {
		if (input[i] != ' ' && input[i] != '\t' || wordStarted) {
			temp += input[i];
			wordStarted = true;
		}
	}
}
void getValidQuantity(Record*& myRecord) {

}
void getValidCost(Record*& myRecord) {

}
void collectRecordData() {
	Record* myRecord = new Record;
	cout << "Enter a record number: ";
	getValidRecordNumber(myRecord);
	cout << "Enter a tool: ";
	getValidTool(myRecord);
	cout << "Enter a quantity: ";
	getValidQuantity(myRecord);
	cout << "Enter a cost: ";
	getValidCost(myRecord);
}
void addRecord() {

}
void updateRecord() {

}
void deleteRecord() {

}
void displayRecord() {

}
void displayTools() {
	
}
void quit(bool& isRunning) {
	isRunning = false;
}

void collectUserInput(bool& isRunning) {
	cout << "What would you like to do?" << endl;
	cout << "--------------------------" << endl;
	cout << " 1. Add a Record" << endl;
	cout << " 2. Update a Record" << endl;
	cout << " 3. Delete a Record" << endl;
	cout << " 4. List a Record" << endl;
	cout << " 5. List All Tools" << endl;
	cout << " 6. Quit" << endl;
	
	int input;
	bool valid;
	do{
		cout << "Enter Valid Choice Here: ";
		cin >> input;
		switch (input) {
		case 1:
			addRecord();
			valid = true;
			break;
		case 2:
			updateRecord();
			valid = true;
			break;
		case 3:
			deleteRecord();
			valid = true;
			break;
		case 4:
			displayRecord();
			valid = true;
			break;
		case 5:
			displayTools();
			valid = true;
			break;
		case 6:
			quit(isRunning);
			valid = true;
			break;
		default:
			cout << "Invalid Response!" << endl;
			break;

		}
	} while (!valid);


}

#endif
