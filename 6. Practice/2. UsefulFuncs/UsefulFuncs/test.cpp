#include "funcs.h"

int main() {
	string input;
	
	getline(cin, input);
	try {
		cout << userInput(input, MIN_FLOAT, MAX_FLOAT, ONE_VALUE, DONT_CLEAR_BUFFER) << endl;
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}

	return 0;
}