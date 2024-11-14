#include "funcs.h"

const int MAX_RECORDS = 100;

int randomFileAccessComparisons = 0;
int unsortedListComparisons = 0;
int sortedListComparisons = 0;

void logComparison(fstream& logFile, const string& dataStructure) {
	if (dataStructure == "RandomFileAccess") {
		randomFileAccessComparisons++;
	}
	else if (dataStructure == "UnsortedList") {
		unsortedListComparisons++;
	}
	else if (dataStructure == "SortedList") {
		sortedListComparisons++;
	}
}

void writeSummary(fstream& logFile) {
	if (logFile.is_open()) {
		
		logFile.seekp(0, ios::beg);

		
		logFile << randomFileAccessComparisons << "\n";
		logFile << unsortedListComparisons << "\n";
		logFile << sortedListComparisons << "\n";

		
		logFile.flush();
	}
	else {
		cerr << "Failed to open log file for writing summary.\n";
	}
}

void printLogFile(fstream& logFile) {
	if (!logFile.is_open()) {
		cerr << "Failed to open log file for reading.\n";
		return;
	}

	
	logFile.seekg(0, ios::beg);

	
	logFile >> randomFileAccessComparisons;
	logFile >> unsortedListComparisons;
	logFile >> sortedListComparisons;

	
	cout << "\n--- Comparison Summary ---\n";
	cout << "Random File Access comparisons: " << randomFileAccessComparisons << "\n";
	cout << "Unsorted Linked List comparisons: " << unsortedListComparisons << "\n";
	cout << "Sorted Linked List comparisons: " << sortedListComparisons << "\n";
}


void initFile(fstream& file) {
	Record record = {};
	for (int i = 0; i < MAX_RECORDS; i++) {
		file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
	}
	file.seekg(0, ios::beg);
}
void placeInFile(Record& hardware, fstream& file, fstream& logFile) {
	if (file.fail()) {
		file.clear();
	}
	if (file.is_open()) {
		file.seekp(sizeof(hardware) * (hardware.recordNumber - 1), ios::beg);
		file.write(reinterpret_cast<const char*>(&hardware), sizeof(Record));
		logComparison(logFile, "RandomFileAccess");
	}
	else {
		cout << "Failed to open file for writing!" << endl;
	}
}
void sortInLinkedList(Node* nodeToAdd, Node*& list2, fstream& logFile) {
	if (list2 == nullptr) {
		list2 = nodeToAdd;
		nodeToAdd->next = nullptr;
		return;
	}

	if (nodeToAdd->record.recordNumber < list2->record.recordNumber) {
		logComparison(logFile, "SortedList");
		nodeToAdd->next = list2;
		list2 = nodeToAdd;
		return;
	}

	Node* current = list2;
	while (current->next && current->next->record.recordNumber < nodeToAdd->record.recordNumber) {
		logComparison(logFile, "SortedList");
		current = current->next;
	}

	nodeToAdd->next = current->next;
	current->next = nodeToAdd;

}
bool doesRecordExist(int input, Node*& list1, Node*& list2, fstream& file, fstream& logFile, const string& dataStructure) {
	if (dataStructure == "UnsortedList") {
		Node* current1 = list1;
		while (current1) {
			logComparison(logFile, dataStructure);
			if (current1->record.recordNumber == input) {
				return true;
			}
			current1 = current1->next;
		}
	}
	else if (dataStructure == "SortedList") {
		Node* current2 = list2;
		while (current2) {
			logComparison(logFile, dataStructure);
			if (current2->record.recordNumber == input) {
				return true;
			}
			current2 = current2->next;
		}
	}
	else if (dataStructure == "RandomAccessFile") {
		if (file.fail()) {
			file.clear();
		}
		file.seekg(0, ios::beg);
		Record record;
		while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
			logComparison(logFile, dataStructure);
			if (record.recordNumber == input) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}
void getValidRecordNumber(Record*& myRecord) {

	int input;
	while (true) {
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
	myRecord->cost = round(input * 100) / 100;
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

Record* collectRecordData(int recordNum) {
	Record* myRecord = new Record;
	myRecord->recordNumber = recordNum;
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

void addRecord(Node*& list1, Node*& list2, fstream& file, fstream& logFile) {
	bool recordExists = false;
	Node* current1 = list1;
	Node* current2 = list2;
	Node* node1 = new Node;
	Node* node2 = new Node;
	Record* hardware = collectRecordData();
	recordExists = doesRecordExist(node1->record.recordNumber, list1, list2, file, logFile, "UnsortedList")
					&& doesRecordExist(node2->record.recordNumber, list1, list2, file, logFile, "SortedList")
					&& doesRecordExist(hardware->recordNumber, list1, list2, file, logFile, "RandomAccessFile");

	if (!recordExists) {
		node1->record = *hardware;
		node2->record = *hardware;
		placeInLinkedList(node1, list1);
		sortInLinkedList(node2, list2, logFile);
		placeInFile(*hardware, file, logFile);
	}
	else {
		delete node1;
		delete node2;
		cout << "===================================================" << endl;
		cout << "*Record exists already you cannot add this record!*" << endl;
		cout << "===================================================" << endl;
	}
	delete hardware;
}

void updateRecord(Node*& list1, Node*& list2, fstream& file, fstream& logFile) {
	cout << "Which record would you like to update? : ";
	int recordNum = getValidRecordNumber();
	Record* hardware = collectRecordData(recordNum);

	Node* current1 = list1;
	while (current1 != nullptr && current1->record.recordNumber != recordNum) {
		logComparison(logFile, "UnsortedList");
		current1 = current1->next;
	}
	if (!current1) {
		cout << "=====================================" << endl;
		cout << "*No Record exists for unsorted list!*" << endl;
	}

	if (current1 != nullptr && current1->record.recordNumber == recordNum) {
		current1->record = *hardware;
		placeInFile(*hardware, file, logFile);
	}

	Node* current2 = list2;
	while (current2 != nullptr && current2->record.recordNumber != recordNum) {
		logComparison(logFile, "SortedList");
		current2 = current2->next;
	}
	if (!current2) {
		cout << "*No Record exists for sorted list!  *" << endl;
	}

	if (current2 != nullptr && current2->record.recordNumber == recordNum) {
		current2->record = *hardware;
		
	}

	if (file.fail()) {
		file.clear();
	}
	bool foundRecord = false;
	Record record;
	file.seekg(0, ios::beg);
	while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
		logComparison(logFile, "RandomAccessFile");
		if (record.recordNumber == recordNum) {
			placeInFile(*hardware, file, logFile);
			foundRecord = true;
		}
	}
	if (!foundRecord) {
		cout << "*No Record exists for file!         *" << endl;
		cout << "=====================================" << endl;
	}
	delete hardware;
}
void deleteRecord(Node*& list1, Node*& list2, fstream& file, fstream& logFile) {
	cout << "Which record would you like to delete? : ";
	int recordNum = getValidRecordNumber();
	bool noSortRecord = false;
	bool noUnsortRecord = false;
	bool noFileRecord = false;

	Node* current1 = list1;
	Node* prev = nullptr;

	while (current1 != nullptr && current1->record.recordNumber != recordNum) {
		logComparison(logFile, "UnsortedList");
		prev = current1;
		current1 = current1->next;
	}

	if (current1 == nullptr) {
		cout << "=====================================" << endl;
		cout << "*Record in unsorted list not found! *" << endl;
		noUnsortRecord = true;
	}
	if (prev == nullptr && !noUnsortRecord) {
		list1 = current1->next;
	}
	else if(!noUnsortRecord){
		prev->next = current1->next;
	}

	Node* current2 = list2;
	prev = nullptr;

	while (current2 != nullptr && current2->record.recordNumber != recordNum) {
		logComparison(logFile, "SortedList");
		prev = current2;
		current2 = current2->next;
	}


	if (current2 == nullptr) {
		cout << "*Record in sorted list not found!   *" << endl;
		noSortRecord = true;
	}
	if (prev == nullptr && !noSortRecord) {
		list2 = current2->next;
	}
	else if(!noSortRecord){
		prev->next = current2->next;
	}

	if (file.fail()) {
		file.clear();
	}

	Record record;
	Record init{};
	file.seekg(sizeof(Record) * (recordNum - 1), ios::beg);
	file.read(reinterpret_cast<char*>(&record), sizeof(Record));
	if (record.recordNumber != 0) {
		file.seekp(sizeof(Record) * (recordNum - 1), ios::beg);
		file.write(reinterpret_cast<const char*>(&init), sizeof(Record));
	}
	else {
		cout << "*Record in file not found!          *" << endl;
		cout << "=====================================" << endl;
		noFileRecord = true;
	}
	if (!(noFileRecord || noSortRecord || noUnsortRecord)) {
		cout << "Records deleted!" << endl;
	}
	
}
void displayRecord(Node* list1, Node* list2, fstream& file, fstream& logFile) {
	cout << "Which record would you like to access? : ";
	int recordNum = getValidRecordNumber();
	cout << "\nContents of List1" << endl;
	cout << "---------------------" << endl;
	Node* current1 = list1;
	while (current1 != nullptr && current1->record.recordNumber != recordNum) {
		logComparison(logFile, "UnsortedList");
		current1 = current1->next;
	}
	if (current1) {
		cout << "Record #: " << current1->record.recordNumber << endl;
		cout << "Tool: " << current1->record.toolname << endl;
		cout << "Quantity: " << current1->record.quantity << endl;
		cout << "Cost: $" << current1->record.cost << endl;
	}
	else {
		cout << "Record does not exist!" << endl;
	}
	cout << "\nContents of List2" << endl;
	cout << "---------------------" << endl;

	Node* current2 = list2;
	while (current2 != nullptr && current2->record.recordNumber != recordNum) {
		logComparison(logFile, "SortedList");
		current2 = current2->next;
	}
	if (current2) {
		cout << "Record #: " << current2->record.recordNumber << endl;
		cout << "Tool: " << current2->record.toolname << endl;
		cout << "Quantity: " << current2->record.quantity << endl;
		cout << "Cost: $" << current2->record.cost << endl;
	}
	else {
		cout << "Record does not exist!" << endl;
	}

	cout << "\nContents of file" << endl;
	cout << "---------------------" << endl;
	
	
	if (file.fail()) {
		file.clear();
	}
	Record record;
	int offset = sizeof(record) * (recordNum - 1);
	file.seekg(offset, ios::beg);
	if (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
		if (record.recordNumber > 0 && record.recordNumber < 101) {
			cout << "Record #: " << record.recordNumber << endl;
			cout << "Tool: " << record.toolname << endl;
			cout << "Quantity: " << record.quantity << endl;
			cout << "Cost: $" << record.cost << endl;
		}
		else {
			cout << "Record does not exist!" << endl;
		}
	}
	
	
}
void displayTools(Node* list1, Node* list2, fstream& file) {
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
		cout << "Cost: $" << current->record.cost << endl;
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
		cout << "Cost: $" << current->record.cost << endl;
		cout << endl;
		current = current->next;
	}
	cout << endl;


	cout << "\nContents of file" << endl;
	cout << "---------------------" << endl;
	if (file.fail()) {
		file.clear();
	}
	Record record;
	bool readRecord = false;
	file.seekg(0, ios::beg);
	while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
		if (record.recordNumber > 0 && record.recordNumber < 101) {
			cout << "Record #: " << record.recordNumber << endl;
			cout << "Tool: " << record.toolname << endl;
			cout << "Quantity: " << record.quantity << endl;
			cout << "Cost: $" << record.cost << endl;
			cout << endl;
			readRecord = true;
		}
	};

	if (!readRecord) {
		cout << "No Records to read from!" << endl;
	}
}
void quit(bool& isRunning) {
	isRunning = false;
}

