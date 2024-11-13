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

void initFile(fstream&);
void placeInFile(Record&, fstream&);
void sortInLinkedList(Node*, Node*&);
bool doesRecordExist(int, Node*&, Node*&);
void getValidRecordNumber(Record*&);
int getValidRecordNumber();
void getValidTool(Record*&);
void getValidQuantity(Record*&);
void getValidCost(Record*&);
Record* collectRecordData();
void placeInLinkedList(Node*, Node*& );
void addRecord(Node*& , Node*& , fstream& );
void updateRecord(Node*& , Node*& , fstream& );
void deleteRecord(Node*& , Node*& , fstream& );
void displayRecord(Node* list1, Node* list2, fstream& );
void displayTools(Node* , Node* , fstream& );
void quit(bool&);



#endif
