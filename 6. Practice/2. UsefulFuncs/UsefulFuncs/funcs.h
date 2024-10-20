#ifndef FUNCS_H
#define FUNCS_H

//TODO create function for length determination

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>
#include <regex>
#include <sstream>
#include <limits>


using namespace std;
namespace { 
    const regex scientificNotation(R"(^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)$)");
    const regex floatingPoint(R"(^[+-]?(\d*\.\d+|\d+(\.\d*)?|\d+)([eE][+-]?\d+)?$)");
    const regex integral(R"([+-]?\d+(\.\d+)?([eE][+-]?\d+)?)");

}

//string consts
const string IS_ALPHA = "alpha";
const string IS_NUMERIC = "numeric";
const string IS_FILE = "file";
const string IS_CHARACTER = "character";
const string IS_NULL = "null";

//numeric consts
const int      MAX_INT = numeric_limits<int>::max();
const int      MIN_INT = numeric_limits<int>::min();
const long     MAX_LONG = numeric_limits<long>::max();
const long     MIN_LONG = numeric_limits<long>::min();
const unsigned MAX_UNSIGNED = numeric_limits<unsigned>::max();
const unsigned MIN_UNSIGNED = numeric_limits<unsigned>::min();
const float    MAX_FLOAT = numeric_limits<float>::max();
const float    MIN_FLOAT = numeric_limits<float>::min();
const double   MAX_DOUBLE = numeric_limits<double>::max();
const double   MIN_DOUBLE = numeric_limits<double>::min();

//boolean consts
const bool   ONE_VALUE = true;
const bool   MULTI_VALUE = false;
const bool   CLEAR_BUFFER = true;
const bool   DONT_CLEAR_BUFFER = false;
const bool   CASE_SENSITIVE = true;
const bool   NOT_CASE_SENSITIVE = false;

//Helper functions
bool isFileChar(const char);
string formatAndTrim(string&);
void initialInputHandling(string&, const bool&, const bool&, const bool&);
bool validateSegments(const string&, const regex&);
int findSigFigLength(const string&, const bool&, int&);

//validates floats
template<typename T>
typename enable_if<is_same<T, float>::value, T>::type
validatedFloatingPoint(string& input, const T& param1, const T& param2, int& decimal, int& length) {
    const int sigFig = numeric_limits<T>::digits10;
    T numConvert = 0;
    try {
        numConvert = stof(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a float much too large or small!");
    }

    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
            + to_string(param1) + ", " + to_string(param2) + " )");
    }
    else if (length > sigFig) {
        throw out_of_range("You entered a number with more than " + to_string(sigFig) + " significant figures!");
    }
    return numConvert;
}

//validates doubles
template<typename T>
typename enable_if<is_same<T, double>::value, T>::type
validatedFloatingPoint(string& input, const T& param1, const T& param2, int& decimal, int& length) {
    const int sigFig = numeric_limits<T>::digits10;
    T numConvert = 0;
    try {
        numConvert = stod(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a double much too large or small!");
    }

    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
            + to_string(param1) + ", " + to_string(param2) + " )");
    }
    else if (length > sigFig) {
        throw out_of_range("You entered a number with more than " + to_string(sigFig) + " significant figures!");
    }
    return numConvert;
}


//Default template if no type is matched
template<typename T, typename Enable = void>
inline typename enable_if<!is_integral<T>::value, T>::type
userInput(string&, const T&, const T&, const bool&, const bool&, const bool&) {
    static_assert(is_same<T, void>::value, "Invalid type for userInput");
}


//Specialization for int
template<typename T>
inline typename enable_if<is_integral<T>::value, T>::type
userInput(string& input, const T& param1, const T& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive);
    if (!singleInput) {
        throw invalid_argument("ARGUMENT: singleInput MUST BE FALSE FOR NUMBERS!");
    }
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR NUMBERS!");
    }
    T numConvert;
    bool isScientific = validateSegments(input, scientificNotation);
    bool allIntegers = validateSegments(input, integral);
    bool hasSpaces = (input.find(' ') != string::npos);
       

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (hasSpaces && allIntegers) {
                throw invalid_argument("You entered more than one input.");
            }
            else if (!isScientific) {
                throw invalid_argument("You entered a non-integer value!");
            }
        }
      
    }
    
    numConvert = static_cast<T>(stold(input));
    
    if (stold(input) > numeric_limits<T>::max() || stold(input) < numeric_limits<T>::min()) {
        throw out_of_range("You entered an integer much too large or small!");
    }

    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
            + to_string(param1) + ", " + to_string(param2) + " )");
    }

    return numConvert;
}


//Specialization for float
template<>
inline float userInput<float>(string& input, const float& param1, const float& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive);
    if (!singleInput) {
        throw invalid_argument("ARGUMENT: singleInput MUST BE FALSE FOR NUMBERS!");
    }
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR NUMBERS!");
    }
    int decimal = 0;
    int length = 0;
    bool isScientific = validateSegments(input, scientificNotation);
    bool allFloatingPointNums = validateSegments(input, floatingPoint);
    bool hasSpaces = (input.find(' ') != string::npos);

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (hasSpaces && allFloatingPointNums) {
                throw invalid_argument("You entered more than one input.");
            }
            else if (ch == '.') {
                decimal++;
                if (decimal > 1) {
                    throw invalid_argument("You entered too many decimals!");
                }
            }
            else if (!isScientific) {
                throw invalid_argument("You entered a non-numerical value!");
            }

        }
    }
    length = findSigFigLength(input, isScientific, decimal);


    return validatedFloatingPoint(input, param1, param2, decimal, length);
}


//Specialization for double
template<>
inline double userInput<double>(string& input, const double& param1, const double& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive);
    if (!singleInput) {
        throw invalid_argument("ARGUMENT: singleInput MUST BE FALSE FOR NUMBERS!");
    }
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR NUMBERS!");
    }
    int decimal = 0;
    int length = 0;
    bool isScientific = validateSegments(input, scientificNotation);
    bool allFloatingPointNums = validateSegments(input, floatingPoint);
    bool hasSpaces = (input.find(' ') != string::npos);

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (hasSpaces && allFloatingPointNums) {
                throw invalid_argument("You entered more than one input.");
            }
            else if (ch == '.') {
                decimal++;
                if (decimal > 1) {
                    throw invalid_argument("You entered too many decimals!");
                }
            }
            else if (!isScientific) {
                throw invalid_argument("You entered a non-numerical value!");
            }
        }
    }
    length = findSigFigLength(input, isScientific, decimal);

    return validatedFloatingPoint(input, param1, param2, decimal, length);
}


//Specialization for string
template<>
inline string userInput<string>(string& input, const string& param1, const string& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive);

    for (auto ch : input) {
        if (ch != '\0') {
            if (ch == ' ' && singleInput) {
                throw invalid_argument("You entered more than one word!");
            }
            if (param1 == IS_ALPHA && param2 == IS_NUMERIC && !(isdigit(ch) || isalpha(ch)) && ch != ' ') {
                if (!singleInput) {
                    throw invalid_argument("This is not an alpha-numeric list!");
                }
                throw invalid_argument("This is not an alpha-numeric value!");
            }
            else if (param1 == IS_ALPHA && param2 == IS_NULL && !isalpha(ch) && ch != ' ') {
                if (!singleInput) {
                    throw invalid_argument("You entered a non-alphabetic sentence!");
                }
                throw invalid_argument("You entered a non-alphabetic word!");
            }
            else if (param1 == IS_FILE && param2 == IS_NULL && !isFileChar(ch)) {
                throw invalid_argument("You entered an improper filename!");
            }
            else if (param1 == IS_CHARACTER && param2 == IS_NULL) {
                if (input.size() != 1 || !isalpha(ch)) {
                    throw invalid_argument("This is not a character input!");
                }
            }
        }

    }

    return input;
}


//Specialization for bool
template<>
inline bool userInput<bool>(string& input, const bool& param1, const bool& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive);
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR BOOLEANS!");
    }
    if (param1 != param2) {
        return false;
    }
    else if (input == "true" || input == "1") {
        return true;
    }
    else if (input == "false" || input == "0") {
        return true;
    }
    else {
        throw invalid_argument("Not a true/false value!");
    }
}



#endif
