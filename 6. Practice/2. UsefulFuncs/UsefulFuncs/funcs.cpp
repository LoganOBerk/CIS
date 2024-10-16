#include "funcs.h"

// Check if a character is valid for filenames
bool isFileChar(const char ch) {
    static const string unallowedChars = "<>:\"/\\|?*";
    return unallowedChars.find(ch) == string::npos;
}
string removeCharAtIndex(string& str, const char chToRemove) {
    string replacement;
    for (int i = 0; i < str.size(); i++) {
        while (str[i] == chToRemove) {
            if (str[i + 1] == ' ') {
                i++;
            }
            else if(chToRemove == ',') {
                str[i] = ' ';
            }
            
        }
        replacement += str[i];
    }
    return replacement;
}
// Convert string to lowercase and trim whitespace, and remove trailingcommas
string formatAndTrim(string& str) {
    if (str.empty()) {
        return str;
    }
    for (auto& ch : str) {
        ch = tolower(ch);
    }
    str = removeCharAtIndex(str, ',');
    
    auto start = find_if_not(str.begin(), str.end(), ::isspace);
    auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();

    return string(start, end);
}

//Initial input checking
void initialInputHandling(string& input, const bool& notSingleWord, const bool& isClearBuffer) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer && notSingleWord) {
        throw invalid_argument("Clearing the buffer while allowing spaces is inconsistent.");
    }
    input = formatAndTrim(input);
    if (isClearBuffer) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}