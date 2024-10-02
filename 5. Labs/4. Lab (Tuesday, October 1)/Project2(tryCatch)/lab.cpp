/************************
* Programer Name: Logan Berk
*
* Purpose: illistrate understanding of algorithmic thinking and try catch throw syntax
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
	if (x < 0) {
		throw domain_error("You cannot take square roots of negative numbers");
	}
	if (x > numeric_limits<double>::max()) {
		throw overflow_error("Overflow Error : Input is too large");
	}
	double TOL = 0.0001;
	double xNot = x / 2;
	double xOne;
	while (true) {
		xOne = (xNot + x / xNot) / 2;
		if (abs(xNot - xOne) < TOL) {
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


		try {
			float x = getUserFloatInput();
			cout << "The square root of " << x << " is approximately " << fixed << setprecision(4) << squareRoot(x) << defaultfloat << endl;

		}
		catch (const domain_error& e) {
			cout << e.what() << endl;
		}
		catch (const overflow_error& e) {
			cout << e.what() << endl;
		}
		catch (...) {
			cout << "Unknown Exception Thrown" << endl;
		}


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