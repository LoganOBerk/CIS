#include "funcs.h"

int main() {
	string input;
	
	getline(cin, input);
			try {
				cout << userInput(input, 1.1f, 100.1f, true, false);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;

			}
			catch (out_of_range& e) {
				cout << e.what() << endl;

			}
	
	return 0;
}