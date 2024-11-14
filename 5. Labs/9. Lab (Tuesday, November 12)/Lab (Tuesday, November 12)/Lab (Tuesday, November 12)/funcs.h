#define FUNCS_H
#ifdef FUNCS_H
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

extern const int MAX_RECORDS;

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

// File Operations
void logComparison(fstream&, const string&);
void writeSummary(fstream&);
void printLogFile(fstream&);
void initFile(fstream&);
void placeInFile(Record&, fstream&, fstream&);

// Linked List Operations
void placeInLinkedList(Node*, Node*&);
void sortInLinkedList(Node*, Node*&, fstream&);

// Record Operations
void addRecord(Node*&, Node*&, fstream&, fstream&);
void updateRecord(Node*&, Node*&, fstream&, fstream&);
void deleteRecord(Node*&, Node*&, fstream&, fstream&);
void displayRecord(Node*, Node*, fstream&, fstream&);
void displayTools(Node*, Node*, fstream&);

// Record Validation
bool doesRecordExist(int, Node*&, Node*&, fstream&, fstream&, const string&);
void getValidRecordNumber(Record*&);
int getValidRecordNumber();
void getValidTool(Record*&);
void getValidQuantity(Record*&);
void getValidCost(Record*&);

// Data Collection
Record* collectRecordData();
Record* collectRecordData(int);

// Miscellaneous
void quit(bool&);



#endif
