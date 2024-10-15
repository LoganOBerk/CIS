#include "funcs.h"

// Check if a character is valid for filenames
bool isFileChar(const char ch) {
    static const string unallowedChars = "<>:\"/\\|?*";
    return unallowedChars.find(ch) == string::npos;
}

// Convert string to lowercase and trim whitespace, and remove trailingcommas
string formatAndTrim(string& str) {
    if (str.empty()) {
        return str;
    }
    for (auto& ch : str) {
        ch = tolower(ch);
    }
    while (str[str.size() - 1] == ',') {
        str.pop_back();
    }
    auto start = find_if_not(str.begin(), str.end(), ::isspace);
    auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();

    return string(start, end);
}

//Initial input checking
void initialInputHandling(string& input, const bool& canHaveSpaces, const bool& isClearBuffer) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer && canHaveSpaces) {
        throw invalid_argument("Clearing the buffer while allowing spaces is inconsistent.");
    }
    input = formatAndTrim(input);
    if (isClearBuffer) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}