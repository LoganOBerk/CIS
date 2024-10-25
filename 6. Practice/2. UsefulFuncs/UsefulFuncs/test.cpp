#include "funcs.h"
//TODO allow numbers to be handled if they contain proper commas

int main() {
	string input;
	bool invalid = true;
	while (invalid) {
		getline(cin, input);
		try {
			cout << userInput(input, IS_NULL, IS_NULL, MULTI_VALUE, DONT_CLEAR_BUFFER, CASE_SENSITIVE) << endl;
			invalid = true;
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