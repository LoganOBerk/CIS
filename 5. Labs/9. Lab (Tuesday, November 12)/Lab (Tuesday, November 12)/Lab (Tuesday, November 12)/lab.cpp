#include "funcs.h"

int main() {
	bool running = true;
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	fstream file("out.dat", ios::in | ios::out | ios::binary | ios::trunc);
	fstream logFile("log.bin", ios::out | ios::binary | ios::app);
	initFile(file);
	int input;
	do {
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
			addRecord(list1, list2, file, logFile);
			break;
		case 2:
			updateRecord(list1, list2, file, logFile);
			break;
		case 3:
			deleteRecord(list1, list2, file, logFile);
			break;
		case 4:
			displayRecord(list1, list2, file, logFile);
			break;
		case 5:
			displayTools(list1, list2, file);
			break;
		case 6:
			quit(running);
			break;
		default:
			cout << "Invalid Response!" << endl;
			break;

		}
		cout << endl;
	} while (running);
	
	file.close();

	printLogFile(logFile);
	logFile.close();
	return 0;
}