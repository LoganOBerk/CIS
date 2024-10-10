#include "task.h"

int howManyPositiveEven(int arr[MAX_ROWS][MAX_COLUMNS]) {
	int howManyPosEven = 0;
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLUMNS; j++) {
			if (arr[i][j] % 2 == 0 && arr[i][j] > 0) {
				howManyPosEven++;
			}

		}
	}
	return howManyPosEven;
}

int findMaxNumDigits(int arr[MAX_ROWS][MAX_COLUMNS]) {
	int MAX_NUM = 0;
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLUMNS; j++) {
			if (arr[i][j] > MAX_NUM) {
				MAX_NUM = arr[i][j];
			}
		}
	}
	return to_string(MAX_NUM).length();
}

void insertPadding(int arr[MAX_ROWS][MAX_COLUMNS], int rowIndex, int colIndex) {
	int MAX_DIGITS = findMaxNumDigits(arr);
	int padding = 0;
	int digits = to_string(arr[rowIndex][colIndex]).length();
	padding = MAX_DIGITS - digits;
	for (int k = 0; k <= padding; k++) {
		cout << " ";
	}
}

int collectIntInput() {
	string input;
	while (true) {
		bool invalid = false;
		getline(cin, input);
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		for (auto ch : input) {
			if (ch < 49 || ch > 57) {
				invalid = true;
				break;
			}
		}
		if (invalid) {
			cout << "Your last input was not a valid number try again : ";
		}
		else {
			break;
		}
	}
	return stoi(input);
}

void printArray(int arr[MAX_ROWS][MAX_COLUMNS]) {
	for (int i = 0; i < MAX_ROWS; i++) {
		cout << "[";
		for (int j = 0; j < MAX_COLUMNS; j++) {
			insertPadding(arr, i, j);
			cout << arr[i][j];
		}
		cout << "]";
		cout << endl;
	}

	cout << "The amount of even numbers in the array are : " << howManyPositiveEven(arr) << endl;
}

string validateUserInput() {
	string input;
	while (true) {
		getline(cin, input);
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		for (auto ch : input) {
			ch = tolower(static_cast<unsigned char>(ch));
		}
		if (input == "y" || input == "n") {
			break;
		}
		else {
			cout << "Invalid input please enter a y/n answer : ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return input;
}

void collectArrayData(int arr[MAX_ROWS][MAX_COLUMNS]) {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLUMNS; j++) {
			cout << "Enter number in row " << i + 1 <<  " column " << j + 1 << " : ";
			arr[i][j] = collectIntInput();
		}
	}
	
	
}


