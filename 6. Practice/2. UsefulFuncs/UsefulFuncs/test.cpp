#include "funcs.h"

int main() {
	string input;
	bool invalid = true;
	while (invalid) {
		getline(cin, input);
		try {
			cout << userInput(input, MIN_INT, MAX_INT, ONE_VALUE, DONT_CLEAR_BUFFER, NOT_CASE_SENSITIVE) << endl;
			invalid = false;
		}
		catch (const invalid_argument& e) {
			cerr << e.what() << endl;
			invalid = true;
		}
		catch (const out_of_range& e) {
			cerr << e.what() << endl;
			invalid = true;
		}

	}
	return 0;
}