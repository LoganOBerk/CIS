#ifndef USERINPUT_UTILS_H
#define USERINPUT_UTILS_H


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
#include <regex>

using namespace std;

//Regex namespace initialization
namespace RegexPatterns {
    extern const regex scientificNotation;
    extern const regex floatingPoint;
    extern const regex integral;

}



//String consts initialization
extern const string IS_ALPHA;
extern const string IS_NUMERIC;
extern const string IS_FILE;
extern const string IS_CHARACTER;
extern const string IS_NULL;

//Numeric consts initialization
extern const int      MAX_INT;
extern const int      MIN_INT;
extern const long     MAX_LONG;
extern const long     MIN_LONG;
extern const unsigned MAX_UNSIGNED;
extern const unsigned MIN_UNSIGNED;
extern const float    MAX_FLOAT;
extern const float    MIN_FLOAT;
extern const double   MAX_DOUBLE;
extern const double   MIN_DOUBLE;


//Boolean consts initialization
extern const bool   ONE_VALUE;
extern const bool   MULTI_VALUE;
extern const bool   CLEAR_BUFFER;
extern const bool   DONT_CLEAR_BUFFER;
extern const bool   CASE_SENSITIVE;
extern const bool   NOT_CASE_SENSITIVE;


//Helper function prototypes
bool isFileChar(const char);
bool isDigit(const char);
bool isAlpha(const char);
string formatAndTrim(string&);
void initialInputHandling(string&, const bool&, const bool&, const bool&);
bool validateSegments(const string&, const regex&);
int findSigFigLength(const string&, const bool&, int&);




template<typename T>
string typeName() {
    return typeid(T).name();
}


//Insure programmer does not input incorrect booleans with certain data
template <typename T>
void checkForValidBools(const bool& singleInput, const bool& caseSensitive) {
    if (!singleInput) {
        throw invalid_argument("ARGUMENT: singleInput MUST BE TRUE FOR: " + typeName<T>() + "!");
    }
    if (caseSensitive) {
        throw invalid_argument("ARGUMENT: caseSensitive MUST BE FALSE FOR: " + typeName<T>() + "!");
    }
}



//Validates floats
template<typename T>
typename enable_if<is_same<T, float>::value, T>::type
validatedFloatingPoint(string& input, const T& param1, const T& param2, int& decimal, int& length) {
    const int sigFig = numeric_limits<T>::digits10;
    T numConvert = 0;
    try {
        numConvert = stof(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a number much too large or small!");
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


//Validates doubles
template<typename T>
typename enable_if<is_same<T, double>::value, T>::type
validatedFloatingPoint(string& input, const T& param1, const T& param2, int& decimal, int& length) {
    const int sigFig = numeric_limits<T>::digits10;
    T numConvert = 0;
    try {
        numConvert = stod(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a number much too large or small!");
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


//Validates long doubles
template<typename T>
typename enable_if<is_same<T, long double>::value, T>::type
validatedFloatingPoint(string& input, const T& param1, const T& param2, int& decimal, int& length) {
    const int sigFig = numeric_limits<T>::digits10;
    T numConvert = 0;
    try {
        numConvert = stold(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a number much too large or small!");
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
#endif