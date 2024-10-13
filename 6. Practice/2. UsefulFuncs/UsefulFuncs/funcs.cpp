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

// Validate user input based on restrictions
string userInput(string& input, const string& param1, const string& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    input = formatAndTrim(input);
    if (isClearBuffer && canHaveSpaces) {
        throw invalid_argument("It is not typical to have spaces and need to clear the buffer.");
    }
    if (isClearBuffer) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (auto ch : input) {
        if (ch == ' ' && !canHaveSpaces) {
            throw invalid_argument("There can be no spaces in the word!");
        }
        if (param1 == "alpha" && param2 == "numeric" && !(isdigit(ch) || isalpha(ch))) {
            if (canHaveSpaces) {
                throw invalid_argument("This is not an alpha-numeric list!");
            } 
            throw invalid_argument("This is not an alpha-numeric value!");
        }
        else if (param1 == "alpha" && param2 == "null" && !isalpha(ch)) {
            if (canHaveSpaces) {
                throw invalid_argument("You entered a non-alphabetic sentence!");
            }
            throw invalid_argument("You entered a non-alphabetic word!");
        }
        else if (param1 == "file" && param2 == "null" && !isFileChar(ch)) {
            throw invalid_argument("You entered an improper filename!");
        }
        
    }

    return input;
}
