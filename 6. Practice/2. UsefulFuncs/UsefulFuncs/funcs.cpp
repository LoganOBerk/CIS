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
void initialInputHandling(string& input, const bool& singleInput, const bool& isClearBuffer) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer && !singleInput) {
        throw invalid_argument("WARNING ATTEMPTING TO CLEAR BUFFER AND ALLOW MULTIPLE INPUTS POTENTIAL DATA LOSS!");
    }
    input = formatAndTrim(input);
    if (isClearBuffer) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


bool validateSegments(const string& input, const regex& pattern) {
    istringstream iss(input);
    string segment;

    while (iss >> segment) {  
        if (!regex_match(segment, pattern)) {
            return false;  
        }
    }

    return true;  
}

//removes trailing zeros from sig fig calculation and removes the decimal if there is one when calculating
int findSigFigLength(const string& input, const bool& isScientific, int& decimal) {
    int numZeros = 0;
    if (isScientific) {
        string nums = input.substr(0, input.find('e'));
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        return static_cast<int>(input.find('e')) - decimal - numZeros;
    }
    else {
        for (int i = input.size() - 1; i > 0; i--) {
            if (input[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        return static_cast<int>(input.size()) - decimal - numZeros;
    }
}