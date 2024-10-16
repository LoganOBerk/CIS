#include "funcs.h"

int main() {
	string input;
	
	getline(cin, input);
	validateUserInput(input, 1, 100, true, false);
	
	return 0;
}