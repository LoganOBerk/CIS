/************************
* Programer Name: Logan Berk
*
* Purpose: illistrate understanding of algorithmic thinking and assert function
*
* Create Date: 10/1/2024
*
* Modified Date: 10/1/2024
*************************/

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

using namespace std;

double squareRoot(double x) {
	if (x == 0) {
		return 0;
	}
	assert(x >= 0);
	double TOL = 0.0001;
	double xNot = x / 2;
	double xOne;
	while (true) {
		xOne = (xNot + x / xNot) / 2;
		if (fabs(xNot - xOne) < TOL) {
			break;
		}
		xNot = xOne;
	}

	return xOne;
}



string getUserStringInput() {
	string input;
	getline(cin, input);
	string result;
	for (auto ch : input) {
		if (ch != ' ' && ch != ',') {
			result += ch;
		}
	}
	return result;
}

float getUserFloatInput() {
	float x;
	while (!(cin >> x) || cin.peek() != '\n') {
			cout << "Invalid Input try again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	return x;
}

int main() {
	string input;
	while (true) {
		if (input != "y") {
			cout << "Enter a number to take the square root of: ";
		}
		else {
			cout << "Enter another number to take the square root of: ";
		}

			float x = getUserFloatInput();
			cout << "The square root of " << x << " is approximately " << fixed << setprecision(4) << squareRoot(x) << defaultfloat << endl;

		input = "y";
		do {
			if (input != "y" && input != "n") {
				cout << endl;
				cout << "Enter a Valid y/n answer: ";
			}
			else {
				cout << "Would you like to enter another number? (y/n): ";
			}
			input = getUserStringInput();
			cout << endl;

		} while (input != "y" && input != "n");
		if (input == "n") {
			cout << "Goodbye" << endl;
			break;
		}
	}

	return 0;
}