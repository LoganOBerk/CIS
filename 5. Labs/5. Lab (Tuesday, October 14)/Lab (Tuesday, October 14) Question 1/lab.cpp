#include "task.h"
int main() {
	int arrayIntValues[MAX_ROWS][MAX_COLUMNS] = { {4,2000},{300,5},{70000,9} };
	
	while (true) {
		printArray(arrayIntValues);
		cout << "Would you like to enter a new set of values? (y/n): ";
		string userInput = validateUserInput();
		if (userInput == "y") {
			cout << "Please enter 6 numbers after each number entry press the ENTER key." << endl;
			collectArrayData(arrayIntValues);
		}
		else {
			cout << "Goodbye!" << endl;
			break;
		}
	}
	
	return 0;
}