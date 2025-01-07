#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int factorial(int x) {
	if (x < 0) {
		return -1;
	}
	if (x <= 1) {
		return 1;
	}
	
	return x * factorial(x - 1);
}

int main() {

	int input;

	cout << "Enter a number to take the factorial of: ";
	while (!(cin >> input)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a number to take the factorial of: ";
	}

	cout << factorial(input);

	return 0;
}