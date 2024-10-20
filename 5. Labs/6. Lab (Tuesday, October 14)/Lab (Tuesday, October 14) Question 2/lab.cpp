#include "task.h"
int main() {
	bool testing = true;
	float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] =
	{ { {1.1, 1.2}, {1.3, 1.4}, {1.5, 1.6}, {1.7, 1.8}, {1.9, 2.0}, {2.1, 2.2}, {2.1, 2.2}, {2.3, 2.4}, {2.5, 2.6},{2.7, 2.8}, {2.9, 3.0}, {3.1, 3.2} },
	{ {3.1, 3.2}, {3.3, 3.4}, {3.5, 3.6}, {3.7, 3.8}, {3.9, 4.0}, {4.1, 4.2},{2.1, 2.2}, {2.3, 2.4}, {2.5, 2.6}, {2.7, 2.8}, {2.9, 3.0}, {3.1, 3.2} } };
		
	if (!testing) {
		while (true) {
			int month = getUserMonthInput();
			printMonthlySales(month, storeMonthlySales);
			cout << "Would you like to enter a new set of values? (y/n) : ";
			string input = validateStringInput();
			if (input == "y") {
				collectArrayData(storeMonthlySales);
			}
		}
	}
	while(testing){
		string input;
		string result;
		int month;
		cout << "Which test would you like to run? : ";
		getline(cin, input);

		int num = stoi(input);

		switch (num) {
		case 1:
			cout << "TEST 1" << endl;
			month = getUserMonthInput();
			cout << "Expected Output : " << 1 << endl;
			cout << "Actual Output : " << month << endl;
			cout << endl;
			break;
		case 2:
			cout << "TEST 2" << endl;
			month = getUserMonthInput();
			cout << "Expected Output : " << 5 << endl;
			cout << "Actual Output : " << month << endl;
			cout << endl;
			break;
		case 3:
			cout << "TEST 3" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Please enter a month by number or name : " << endl;
			cout << "Not a valid month please try again : " << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output" << endl;
			cout << "------------------------------------------------" << endl;
			getUserMonthInput();
			cout << endl;
			break;
		case 4:
			cout << "TEST 4" << endl;
			collectArrayData(storeMonthlySales);
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 1.1 1.11 1.12 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 2.1 2.11 2.12" << endl;
			cout << "3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 3.1 3.11 3.12 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 4.1 4.11 4.12" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output" << endl;
			cout << "------------------------------------------------" << endl;
			printArray(storeMonthlySales);
			cout << endl;
			break;
		case 5:
			cout << "TEST 5" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Enter number in Store 1 Month 1 and dept 1 : " << endl;
			cout << "That is not a float try again : " << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output" << endl;
			cout << "------------------------------------------------" << endl;
			collectArrayData(storeMonthlySales);
			cout << endl;
			break;
		case 6:
			cout << "TEST 6" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Enter number in Store 1 Month 1 and dept 1 : " << endl;
			cout << "That is out of range try again : " << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output" << endl;
			cout << "------------------------------------------------" << endl;
			collectArrayData(storeMonthlySales);
			cout << endl;
			break;
		case 7:
			cout << "TEST 7" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Please enter a month by number or name : 1" << endl;
			cout << left << setw(15) << "Dept 1" << setw(15) << "Dept 2" << "Store Total" << endl;
			cout << left << setw(15) << "Store 1" << setw(15) << "1.1" << setw(15) << "1.2" << "2.3" << endl;
			cout << left << setw(15) << "Store 2" << setw(15) << "3.1" << setw(15) << "3.2" << "6.3" << endl;
			cout << left << setw(15) << "Dept Total" << setw(15) << "4.2" << setw(15) << "4.4" << "17.2" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output" << endl;
			cout << "------------------------------------------------" << endl;
			month = getUserMonthInput();
			printMonthlySales(month, storeMonthlySales);
			cout << endl;
			break;
		case 8:
			cout << "TEST 8" << endl;
			result = validateStringInput();
			cout << "Expected Output : " << "y" << endl;
			cout << "Actual Output : " << result << endl;
			cout << endl;
			break;
		case 9:
			cout << "TEST 9" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Expected Output" << endl;
			cout << "Invalid input please enter a y/n answer : " << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Actual Output ";
			validateStringInput();
			cout << endl;
			break;
		default:
			testing = false;
			break;
		}

	}

	return 0;
}