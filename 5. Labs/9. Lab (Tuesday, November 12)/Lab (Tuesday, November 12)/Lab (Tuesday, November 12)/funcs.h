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


void sortInLinkedList(Node*& nodeToAdd, Node* list1) {

}
bool doesRecordExist(int input, Node*& list1) {
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



Record* collectRecordData(Node* list1) {
	Record* myRecord = new Record;
	cout << "Enter a record number: ";
	getValidRecordNumber(myRecord);
	cout << "Enter a tool: ";
	getValidTool(myRecord);
	cout << "Enter a quantity: ";
	getValidQuantity(myRecord);
	cout << "Enter a cost: ";
	getValidCost(myRecord);
	

	return myRecord;
}

void placeInLinkedList(Node*& nodeToAdd, Node*& list1) {
	if (!list1) {
		list1 = nodeToAdd;
		nodeToAdd->next = nullptr;
	}
	else {
		nodeToAdd->next = list1;
		list1 = nodeToAdd;
	}
}

void addRecord(Node*& list1) {
	bool recordExists = false;
	Node* current = list1;
	Node* node = new Node;
	node->record = *collectRecordData(list1);
	while (current) {
		if (current->record.recordNumber == node->record.recordNumber) {
			delete node;
			recordExists = true;
			break;
		}
		current = current->next;
	}
	if (!recordExists) {
		placeInLinkedList(node, list1);
	}
	else {
		cout << "===================================================" << endl;
		cout << "*Record exists already you cannot add this record!*" << endl;
		cout << "===================================================" << endl;
	}
}

void updateRecord(Node*& list1) {
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
		current->record = *collectRecordData(list1);
	}
}
void deleteRecord(Node*& list1) {
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
	cout << "Record deleted!" << endl;
}
void displayRecord(Node* list1) {
	cout << "Which record would you like to access? : ";
	int recordNum = getValidRecordNumber();
	Node* current = list1;
	while (current != nullptr && current->record.recordNumber != recordNum ) {
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
void displayTools(Node* list1) {
	Node* current = list1;
	if (!current) {
		cout << "No Records to read from!";
	}
	while (current) {
		cout << current->record.toolname;
		if (current->next) {
			cout << ", ";
		}
		current = current->next;
	}
	cout << endl;
}
void quit(bool& isRunning) {
	isRunning = false;
}

void collectUserInput(bool& isRunning, Node* list1) {

	int input;
	do{
		cout << "What would you like to do?" << endl;
		cout << "--------------------------" << endl;
		cout << " 1. Add a Record" << endl;
		cout << " 2. Update a Record" << endl;
		cout << " 3. Delete a Record" << endl;
		cout << " 4. List a Record" << endl;
		cout << " 5. List All Tools" << endl;
		cout << " 6. Quit" << endl;
		cout << "Enter Valid Choice Here: ";

		cin >> input;
		switch (input) {
		case 1:
			addRecord(list1);
			break;
		case 2:
			updateRecord(list1);
			break;
		case 3:
			deleteRecord(list1);
			break;
		case 4:
			displayRecord(list1);
			break;
		case 5:
			displayTools(list1);
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
