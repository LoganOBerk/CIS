#include "userInput_utils.h"

//Regex namespace to avoid naming conflicts
namespace RegexPatterns {
    const regex scientificNotation(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)$)");
    const regex floatingPoint(R"(^[+-]?(\d*\.\d+|\d+(\.\d*)?|\d+)([eE][+-]?\d+)?$)");
    const regex integral(R"(^[+-]?\d+$)");
}

//Char consts
const char DEFAULT_DELIMITER = ',';

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


//Helper funcs to initalInputHandling
static string formatAndTrim(string&, const bool&, const char&);
static string delimitedInput(string&, const char&);


//Check if a character is valid for filenames
bool isFileChar(const char ch) {
    static const string unallowedChars = "<>:\"/\\|?*";
    return unallowedChars.find(ch) == string::npos;
}

bool isAlpha(const char ch) {
    int asciiValue = static_cast<int>(ch);
    return (asciiValue >= 65 && asciiValue <= 90) || (asciiValue >= 97 && asciiValue <= 122);
}

bool isDigit(const char ch) {
    int asciiValue = static_cast<int>(ch);
    return (ch >= 48 && ch <= 57);
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


//Removes trailing zeros from sig fig calculation and removes the decimal if there is one when calculating
int findSigFigLength(const string& input, const bool& isScientific, int& decimal) {
    int numZeros = 0;
    int significantLength;

    string leadingNums;
    if (isScientific) {
        leadingNums = input.substr(0, input.find('e'));
        significantLength = static_cast<int>(leadingNums.size());
        for (int i = significantLength - 1; i > 0; i--) {
            if (leadingNums[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < significantLength; i++) {
            if (leadingNums[i] == '0' || leadingNums[i] == '.') {
                numZeros++;
                if (leadingNums[i] == '.') {
                    numZeros--;
                }
            }
            else {
                break;
            }
        }
        significantLength -= decimal + numZeros;
        return significantLength;
    }

    else {
        significantLength = static_cast<int>(input.size());
        for (int i = significantLength - 1; i > 0; i--) {
            if (input[i] == '0') {
                numZeros++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '0' || input[i] == '.') {
                numZeros++;
                if (input[i] == '.') {
                    numZeros--;
                }
            }
            else {
                break;
            }
        }
        significantLength -= decimal + numZeros;
        return significantLength;
    }
}


//Default input handling for all datatypes, includes delimeter which inputs can be seperated by default delimiter is ','
void initialInputHandling(string& input, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive, const char& delimiterToConvert) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer && !singleInput) {
        throw invalid_argument("WARNING ATTEMPTING TO CLEAR BUFFER AND ALLOW MULTIPLE INPUTS POTENTIAL DATA LOSS!");
    }

    input = formatAndTrim(input, caseSensitive, delimiterToConvert);

    if (input == "\0") {
        throw invalid_argument("Input cannot be empty.");
    }
    if (isClearBuffer) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
}


// Convert string to lowercase and trim whitespace, and replace valid delimiters with spaces (helper to initialInputHandling)
static string formatAndTrim(string& input, const bool& caseSensitive, const char& delimiterToConvert) {
    if (!caseSensitive) {
        for (auto& ch : input) {
            ch = tolower(ch);
        }
    }
    input = delimitedInput(input, delimiterToConvert);

    return input;
}


//Identifies a valid delimeter that will be converted to spaces and multiple occurances will be removed (helper to formatAndTrim)
//Automatically handles spaces no matter what
static string delimitedInput(string& input, const char& delimiterToConvert) {
    string replacement;
    int i = 0;
    int inputSize = static_cast<int>(input.size());
    while (input[i] == ' ' || input[i] == delimiterToConvert || input[i] == '\t' || input[inputSize - 1] == ' ' || input[inputSize - 1] == delimiterToConvert || input[inputSize - 1] == '\t') {
        if (input[i] == ' ' || input[i] == delimiterToConvert || input[i] == '\t') {
            i++;
        }
        if (input[inputSize - 1] == ' ' || input[inputSize - 1] == delimiterToConvert || input[inputSize - 1] == '\t') {
            inputSize--;
        }
        if (i > inputSize) {
            break;
        }
    }

    for (i; i < inputSize; i++) {
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


