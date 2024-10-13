#include "task.h"
float collectFloatInput() {
	string input;
	bool isfloat = false;
	while (!isfloat) {
		getline(cin, input);
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		try {
			if (stof(input) > 1e+6) {
				throw out_of_range("That is out of range try again : ");
			}
			isfloat = true;
		}
		catch (const invalid_argument&) {
			isfloat = false;
			cout << "That is not a float try again : ";

		}
		catch (const out_of_range& e) {
			isfloat = false;
			cout << e.what();
		}
		catch (...) {
			isfloat = false;
			cout << "That is not a float try again : ";
		}

	}
	return stof(input);
}

void printMonthlySales(int& month, float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]) {
	for (int i = 0; i < NUM_STORES + 2; i++) {
		cout << left << setw(14);
		if (i == 0) {
			cout <<  "      ";
		}
		else if (i == NUM_STORES + 1) {
			cout << "Dept Total";
		}
		else {
			cout << "Store " + to_string(i);
		}
		for (int j = 0; j < NUM_DEPTS; j++) {
			cout << setw(16);
			if (i == 0) {
			cout << "Dept " + to_string(j + 1);
			}
			else if (i == NUM_STORES + 1) {
				cout << "col value sum";
			}
			else {
				cout << arr[i - 1][month - 1][j];
			}
		}
		if (i == 0) {
			cout << "Store Total";
		}
		else if (i == NUM_STORES + 1) {
			cout << "total overall sales";
		}else{
			cout << "sum of row value";
		}
		cout << endl;
	}
}

int getUserMonthInput() {
	int month;
	string input;
	cout << "Please enter a month by number or name : ";
	while (true) {
		getline(cin, input);
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		for (auto ch : input) {
			ch = tolower(ch);
		}
		if (input == "1" || input == "january") {
			month = 1;
			break;
		}
		else if (input == "2" || input == "february") {
			month = 2;
			break;
		}
		else if (input == "3" || input == "march") {
			month = 3;
			break;
		}
		else if (input == "4" || input == "april") {
			month = 4;
			break;
		}
		else if (input == "5" || input == "may") {
			month = 5;
			break;
		}
		else if (input == "6" || input == "june") {
			month = 6;
			break;
		}
		else if (input == "7" || input == "july") {
			month = 7;
			break;
		}
		else if (input == "8" || input == "august") {
			month = 8;
			break;
		}
		else if (input == "9" || input == "september") {
			month = 9;
			break;
		}
		else if (input == "10" || input == "october") {
			month = 10;
			break;
		}
		else if (input == "11" || input == "november") {
			month = 11;
			break;
		}
		else if (input == "12" || input == "december") {
			month = 12;
			break;
		}
		else {
			cout << "Not a valid month please try again : ";
		}
	}
	return month;
}

string validateStringInput() {
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
		}
	}
	return input;
}

void collectArrayData(float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]) {
	for (int i = 0; i < NUM_STORES; i++) {
		for (int j = 0; j < NUM_MONTHS; j++) {
			for (int k = 0; k < NUM_DEPTS; k++) {
				cout << "Enter number in Store " << i + 1 << " Month " << j + 1 << " and dept " << k + 1 << " : ";
				arr[i][j][k] = collectFloatInput();
			}
		}
	}
}

void printArray(float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]) {
	for (int i = 0; i < NUM_STORES; i++) {
		for (int j = 0; j < NUM_MONTHS; j++) {
			for (int k = 0; k < NUM_DEPTS; k++){
				cout << arr[i][j][k] << " ";
		}
	}
		cout << endl;
}
}

