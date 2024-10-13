#include "funcs.h"

int main() {
    string input;

    try {
        getline(cin, input);
        cout << userInput(input, "alpha", "null", false) << endl;
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}
