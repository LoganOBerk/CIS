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


