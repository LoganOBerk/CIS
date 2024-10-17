#include "funcs.h"

int main() {
	string input;
	
	getline(cin, input);
	try {
		cout << userInput(input, MIN_INT, MAX_INT, ONE_VALUE, DONT_CLEAR_BUFFER);
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

	return 0;
}