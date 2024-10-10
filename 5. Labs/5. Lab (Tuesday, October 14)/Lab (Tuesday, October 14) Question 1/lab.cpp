#include "task.h"
int main() {
	bool testing = true;
	
	if (!testing) {
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
	}

    while (testing) {
        int testNum;
        cout << "What number test would you like to run? : ";
        cin >> testNum;

        int arr[MAX_ROWS][MAX_COLUMNS];
        string userInput;
        switch (testNum) {
        case 1:
            cout << "TEST 1" << endl;
            arr[0][0] = 4; arr[0][1] = 2; arr[1][0] = 3; arr[1][1] = 5; arr[2][0] = 7; arr[2][1] = 9;
            cout << "Input : { {4, 2}, {3,5}, {7,9} }" << endl;
            cout << "Expected Output : 2" << endl;
            cout << "Actual Output : " << howManyPositiveEven(arr) << endl;
            break;

        case 2:
            cout << "TEST 2" << endl;
            arr[0][0] = -2; arr[0][1] = -4; arr[1][0] = -3; arr[1][1] = 1; arr[2][0] = 0; arr[2][1] = 5;
            cout << "Input : { {-2, -4}, {-3,1}, {0,5} }" << endl;
            cout << "Expected Output : 0" << endl;
            cout << "Actual Output : " << howManyPositiveEven(arr) << endl;
            break;

        case 3:
            cout << "TEST 3" << endl;
            arr[0][0] = 2; arr[0][1] = 4; arr[1][0] = 6; arr[1][1] = 8; arr[2][0] = 10; arr[2][1] = 12;
            cout << "Input : { {2, 4}, {6,8}, {10,12} }" << endl;
            cout << "Expected Output : 6" << endl;
            cout << "Actual Output : " << howManyPositiveEven(arr) << endl;
            break;

        case 4:
            cout << "TEST 4" << endl;
            arr[0][0] = 4; arr[0][1] = 2000; arr[1][0] = 300; arr[1][1] = 5; arr[2][0] = 70000; arr[2][1] = 9;
            cout << "Input : { {4, 2000}, {300,5}, {70000,9} }" << endl;
            cout << "Expected Output : 5" << endl;
            cout << "Actual Output : " << findMaxNumDigits(arr) << endl;
            break;

        case 5:
            cout << "TEST 5" << endl;
            arr[0][0] = -100; arr[0][1] = -200; arr[1][0] = 0; arr[1][1] = 1; arr[2][0] = 9; arr[2][1] = 99;
            cout << "Input : { {-100, -200}, {0,1}, {9,99} }" << endl;
            cout << "Expected Output : 2" << endl;
            cout << "Actual Output : " << findMaxNumDigits(arr) << endl;
            break;

        case 6:
            cout << "TEST 6" << endl;
            arr[0][0] = 4; arr[0][1] = 2000; arr[1][0] = 300; arr[1][1] = 5; arr[2][0] = 70000; arr[2][1] = 9;
            cout << "Input : { {4, 2000}, {300,5}, {70000,9} }" << endl;
            cout << "Expected Output : start/  /end" << endl;
            cout << "Actual Output : ";
            cout << "start/";
            insertPadding(arr, 0, 1);
            cout << "/end" << endl;
            break;

        case 7:
            cout << "TEST 7" << endl;
            cout << "User Input (each space is a new line): y 1 1 1 1 1 1" << endl;
            cout << "Expected Output : new printed array" << endl;
            cin >> userInput;
            if (userInput == "y") {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter 6 numbers after each number entry press the ENTER key." << endl;
                collectArrayData(arr);
                cout << "Actual Output : " << endl;
                printArray(arr);
            }
            else {
                cout << "Goodbye!" << endl;
            }
            break;

        case 8:
            cout << "TEST 8" << endl;
            cout << "User Input : n" << endl;
            cout << "Expected Output : Goodbye!" << endl;
            cin >> userInput;
            cout << "Actual Output : ";
            if (userInput == "y") {
                cout << "Please enter 6 numbers after each number entry press the ENTER key." << endl;
                collectArrayData(arr);
            }
            else {
                cout << "Goodbye!" << endl;
            }
            break;

        default:
            testing = false;
            cout << "Exiting test mode." << endl;
            break;
        }
    }
	return 0;
}