#include "funcs.h"

int main() {
	string input;
	getline(cin, input);
	
	try {
		cout << userInput(input, IS_ALPHA, IS_NUMERIC, MULTI_VALUE, DONT_CLEAR_BUFFER, CASE_SENSITIVE) << endl;
		cout << pullWord(input, 8);
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}

	return 0;
}