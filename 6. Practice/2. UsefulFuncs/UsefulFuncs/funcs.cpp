#include "funcs.h"

//Regex namespace to avoid naming conflicts
namespace RegexPatterns {
    const regex scientificNotation(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)$)");
    const regex floatingPoint(R"(^[+-]?(\d*\.\d+|\d+(\.\d*)?|\d+)([eE][+-]?\d+)?$)");
    const regex integral(R"([+-]?\d+(\.\d+)?([eE][+-]?\d+)?)");

}

//String consts
const string IS_ALPHA = "alpha";
const string IS_NUMERIC = "numeric";
const string IS_FILE = "file";
const string IS_CHARACTER = "character";
const string IS_NULL = "null";

//Numeric consts
const int      MAX_INT = numeric_limits<int>::max();
const int      MIN_INT = numeric_limits<int>::lowest();
const long     MAX_LONG = numeric_limits<long>::max();
const long     MIN_LONG = numeric_limits<long>::lowest();
const unsigned MAX_UNSIGNED = numeric_limits<unsigned>::max();
const unsigned MIN_UNSIGNED = numeric_limits<unsigned>::lowest();
const float    MAX_FLOAT = numeric_limits<float>::max();
const float    MIN_FLOAT = numeric_limits<float>::lowest();
const double   MAX_DOUBLE = numeric_limits<double>::max();
const double   MIN_DOUBLE = numeric_limits<double>::lowest();


//Boolean consts
const bool   ONE_VALUE = true;
const bool   MULTI_VALUE = false;
const bool   CLEAR_BUFFER = true;
const bool   DONT_CLEAR_BUFFER = false;
const bool   CASE_SENSITIVE = true;
const bool   NOT_CASE_SENSITIVE = false;


//Check if a character is valid for filenames
bool isFileChar(const char ch) {
    static const string unallowedChars = "<>:\"/\\|?*";
    return unallowedChars.find(ch) == string::npos;
}

//Compare each input segment with istringstream to identify if they match specific regex pattern
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

//Insure programmer does not input incorrect booleans with certain data
void checkForValidBools(const bool& singleInput, const bool& caseSensitive) {
    if (!singleInput) {
        throw invalid_argument("ARGUMENT: singleInput MUST BE FALSE FOR NUMBERS!");
    }
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR NUMBERS!");
    }
}

//Identifies a valid delimeter that will be converted to spaces and multiple occurances will be removed (helper to formatAndTrim)
static string delimitedInput(string& input, const char delimiterToConvert) {
    string replacement;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == delimiterToConvert) {
            input[i] = ' ';
        }
        if (input[i] != ' ') {
            replacement += input[i];
        }
        if (input[i] == ' ' && input[i + 1] != ' ' && input[i + 1] != delimiterToConvert) {
            replacement += ' ';
        }
    }
    return replacement;
}


// Convert string to lowercase and trim whitespace, and replace valid delimiters with spaces (helper to initialInputHandling)
static string formatAndTrim(string& input, const bool& caseSensitive) {
    if (input.empty()) {
        return input;
    }
    if (!caseSensitive) {
        for (auto& ch : input){
            ch = tolower(ch);
        }
    }

    input = delimitedInput(input, ',');
    
    auto start = find_if_not(input.begin(), input.end(), ::isspace);
    auto end = find_if_not(input.rbegin(), input.rend(), ::isspace).base();

    return string(start, end);
}


//Default input handling for all datatypes
void initialInputHandling(string& input, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer && !singleInput) {
        throw invalid_argument("WARNING ATTEMPTING TO CLEAR BUFFER AND ALLOW MULTIPLE INPUTS POTENTIAL DATA LOSS!");
    }
    input = formatAndTrim(input, caseSensitive);
    if (isClearBuffer) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
   
    }
}


//Removes trailing zeros from sig fig calculation and removes the decimal if there is one when calculating
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

//Takes an input identifies words and allows accessing words in sentances by word number
string pullWord(string& input, int wordNumber) {
    wordNumber--;
    if (wordNumber < 0) {
        throw out_of_range("You cannot access less than 1 word!");
    }
    vector<string> words;
    int numWords = 0;
    for (int i = 0; i < input.size(); i++) {
        if (numWords == 0) {
            words.push_back(input.substr(0, input.find(' ')));
            numWords++;
        }
        if (input[i] == ' ') {
            words.push_back(input.substr(i + 1, input.substr(i + 1).find(' ')));
            numWords++;
        }
        if (i == input.size() - 1) {
            words.push_back(input.substr(input.rfind(' ') + 1, input.size() - 1));
            break;
        }
    }
    if (wordNumber >= numWords) {
        throw out_of_range("Trying to access word number " + to_string(wordNumber + 1) + " when there are only " + to_string(numWords) + " words!");
    }
    return words[wordNumber];
}