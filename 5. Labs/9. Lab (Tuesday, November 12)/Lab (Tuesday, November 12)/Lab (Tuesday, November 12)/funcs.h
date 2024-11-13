#define FUNCS_H
#ifdef FUNCS_H
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct Record {
	int recordNumber = 0;
	char toolname[21] = "";
	int quantity = 0;
	double cost = 0;
};

struct Node {
	Record record;
	Node* next;
};


void sortInLinkedList(Node* nodeToAdd, Node*& list2) {
	if (list2 == nullptr) {
		list2 = nodeToAdd;
		nodeToAdd->next = nullptr;
		return;
	}

	if (nodeToAdd->record.recordNumber < list2->record.recordNumber) {
		nodeToAdd->next = list2;
		list2 = nodeToAdd;
		return;
	}

	Node* current = list2;
	while (current->next && current->next->record.recordNumber < nodeToAdd->record.recordNumber) {
		current = current->next;
	}

	nodeToAdd->next = current->next;
	current->next = nodeToAdd;
	
}
bool doesRecordExist(int input, Node*& list1, Node*& list2) {
	Node* current = list1;
	while (current) {
		if (current->record.recordNumber = input) {
			return true;
		}
		current = current->next;
	}
	return false;
}
void getValidRecordNumber(Record*& myRecord) {

	int input;
	while(true){
		cin >> input;
		if (cin.fail() || cin.peek() != '\n' || input > 100 || input < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Record Number Try again: ";
		}
		else {
			break;
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	myRecord->recordNumber = input;
}
int getValidRecordNumber() {

	int input;
	while (true) {
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}
void getValidTool(Record*& myRecord) {

	string input;
	bool wordStarted = false;
	getline(cin, input);
	int max;
	input.size() < 20 ? max = input.size() : max = 21;
	int j = 0;
	for (int i = 0; i < max; i++) {
		if (input[i] != ' ' && input[i] != '\t' || wordStarted) {
			myRecord->toolname[j++] = input[i];
			wordStarted = true;
		}
	}
}
void getValidQuantity(Record*& myRecord) {
	int input;
	while (true) {
		cin >> input;
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Quantity Try again: ";
		}
		else {
			break;
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	myRecord->quantity = input;
}
void getValidCost(Record*& myRecord) {
	double input;
	while (true) {
		cin >> input;
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Cost Try again: ";
		}
		else {
			break;
		}
	}
	myRecord->cost = round(input*100)/100;
}



Record* collectRecordData() {
	Record* myRecord = new Record;
	cout << "Enter a record number(1-100): ";
	getValidRecordNumber(myRecord);
	cout << "Enter a tool: ";
	getValidTool(myRecord);
	cout << "Enter a quantity: ";
	getValidQuantity(myRecord);
	cout << "Enter a cost: ";
	getValidCost(myRecord);
	

	return myRecord;
}

void placeInLinkedList(Node* nodeToAdd, Node*& list1) {
	if (!list1) {
		list1 = nodeToAdd;
		nodeToAdd->next = nullptr;
	}
	else {
		nodeToAdd->next = list1;
		list1 = nodeToAdd;
	}
}

void addRecord(Node*& list1, Node*& list2) {
	bool recordExists = false;
	Node* current = list1;
	Node* node1 = new Node;
	Node* node2 = new Node;
	node1->record = *collectRecordData();
	node2->record = node1->record;
	while (current) {
		if (current->record.recordNumber == node1->record.recordNumber ) {
			delete node1;
			delete node2;
			recordExists = true;
			break;
		}
		current = current->next;
	}
	if (!recordExists) {
		placeInLinkedList(node1, list1);
		sortInLinkedList(node2, list2);
	}
	else {
		cout << "===================================================" << endl;
		cout << "*Record exists already you cannot add this record!*" << endl;
		cout << "===================================================" << endl;
	}
}

void updateRecord(Node*& list1, Node*& list2) {
	cout << "Which record would you like to update? : ";
	int recordNum = getValidRecordNumber();
	Node* current = list1;
	if (!current) {
		cout << "No Records to read from!";
	}
	while (current != nullptr && current->record.recordNumber != recordNum) {
		current = current->next;
	}
	if (current != nullptr && current->record.recordNumber == recordNum) {
		current->record = *collectRecordData();
		list2->record = current->record;
	}
	
}
void deleteRecord(Node*& list1, Node*& list2) {
	cout << "Which record would you like to delete? : ";
	int recordNum = getValidRecordNumber(); 

	Node* current = list1;
	Node* prev = nullptr;
	if (!current) {
		cout << "No records to delete!" << endl;
		return;
	}

	while (current != nullptr && current->record.recordNumber != recordNum) {
		prev = current;
		current = current->next;
	}

	
	if (current == nullptr) {
		cout << "Record not found!" << endl;
		return;
	}
	if (prev == nullptr) {
		list1 = current->next;  
	}
	else {
		prev->next = current->next;  
	}
	delete current;
	delete prev;

	current = list2;
	prev = nullptr;
	if (!current) {
		cout << "No records to delete!" << endl;
		return;
	}

	while (current != nullptr && current->record.recordNumber != recordNum) {
		prev = current;
		current = current->next;
	}


	if (current == nullptr) {
		cout << "Record not found!" << endl;
		return;
	}
	if (prev == nullptr) {
		list2 = current->next;
	}
	else {
		prev->next = current->next;
	}

	delete current;
	cout << "Record deleted!" << endl;
}
void displayRecord(Node* list1, Node* list2) {
	cout << "Which record would you like to access? : ";
	int recordNum = getValidRecordNumber();
	cout << "\nContents of List1" << endl;
	cout << "---------------------" << endl;
	Node* current = list1;
	while (current != nullptr && current->record.recordNumber != recordNum ) {
		current = current->next;
	}
	if (current) {
		cout << "Record #: " << current->record.recordNumber << endl;
		cout << "Tool: " << current->record.toolname << endl;
		cout << "Quantity: " << current->record.quantity << endl;
		cout << "Cost: $" << current->record.cost << endl;
	}
	else {
		cout << "Record does not exist!" << endl;
	}
	cout << "\nContents of List2" << endl;
	cout << "---------------------" << endl;

	current = list2;
	while (current != nullptr && current->record.recordNumber != recordNum) {
		current = current->next;
	}
	if (current) {
		cout << "Record #: " << current->record.recordNumber << endl;
		cout << "Tool: " << current->record.toolname << endl;
		cout << "Quantity: " << current->record.quantity << endl;
		cout << "Cost: " << current->record.cost << endl;
	}
	else {
		cout << "Record does not exist!" << endl;
	}
}
void displayTools(Node* list1, Node* list2) {
	cout << "\nContents of unsorted list" << endl;
	cout << "---------------------" << endl;
	Node* current = list1;
	if (!current) {
		cout << "No Records to read from!";
	}
	while (current) {
		cout << "Record #: " << current->record.recordNumber << endl;
		cout << "Tool: " << current->record.toolname << endl;
		cout << "Quantity: " << current->record.quantity << endl;
		cout << "Cost: " << current->record.cost << endl;
		cout << endl;
		current = current->next;
	}
	cout << endl;

	cout << "\nContents of sorted list" << endl;
	cout << "---------------------" << endl;
	current = list2;
	if (!current) {
		cout << "No Records to read from!";
	}
	while (current) {
		cout << "Record #: " << current->record.recordNumber << endl;
		cout << "Tool: " << current->record.toolname << endl;
		cout << "Quantity: " << current->record.quantity << endl;
		cout << "Cost: " << current->record.cost << endl;
		cout << endl;
		current = current->next;
	}
	cout << endl;
}
void quit(bool& isRunning) {
	isRunning = false;
}

void collectUserInput(bool& isRunning, Node* list1, Node* list2) {

	int input;
	do{
		cout << "===========Hardware Store Inventory============" << endl;
		cout << " 1. Add a Record" << endl;
		cout << " 2. Update a Record" << endl;
		cout << " 3. Delete a Record" << endl;
		cout << " 4. List a Record" << endl;
		cout << " 5. List All Tools" << endl;
		cout << " 6. Quit" << endl;
		cout << "===============================================" << endl;
		cout << "Enter Valid Choice Here (1-6): ";
		

		cin >> input;
		switch (input) {
		case 1:
			addRecord(list1, list2);
			break;
		case 2:
			updateRecord(list1, list2);
			break;
		case 3:
			deleteRecord(list1, list2);
			break;
		case 4:
			displayRecord(list1, list2);
			break;
		case 5:
			displayTools(list1, list2);
			break;
		case 6:
			quit(isRunning);
			break;
		default:
			cout << "Invalid Response!" << endl;
			break;

		}
		cout << endl;
	} while (isRunning);


}

#endif
