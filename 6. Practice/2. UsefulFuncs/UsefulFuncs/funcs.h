#ifndef FUNCS_H
#define FUNCS_H
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>

using namespace std;


// Helper functions
bool isFileChar(const char);
string formatAndTrim(string&);

string userInput(string&, const string&, const string&, const bool&, const bool&);

template<typename T>
T handleInt(const string& input, const T& param1, const T& param2) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    T numConvert;

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            throw invalid_argument("You entered a non-integer value!");
        }
    }

    try {
        numConvert = stoi(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered an integer much too large or small!");
    }

    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
                    + to_string(param1) + ", " + to_string(param2) + " )");
    }

    return numConvert;
}

template<typename T>
T handleFloat(const string& input, const T& param1, const T& param2) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    T numConvert;
    int decimal = 0;
    int length = 0;

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (ch == '.') {
                decimal++;
            }
            else {
                throw invalid_argument("You entered a non-numerical value!");
            }

            if (decimal > 1) {
                throw invalid_argument("You entered too many decimals!");
            }

            length = static_cast<int>(input.size()) - decimal;
        }
    }

    try{
    numConvert = stof(input);
    }
    catch (const out_of_range&) {
        throw out_of_range("You entered a float much too large or small!");
    }

    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
            + to_string(param1) + ", " + to_string(param2) + " )");
    }
    else if (length > 7) {
        throw out_of_range("You entered a decimal number with more than 7 significant figures!");
    }

    return numConvert;
}

template<typename T>
T handleDouble(const string& input, const T& param1, const T& param2) {
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    T numConvert;
    int decimal = 0;
    int length = 0;

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (ch == '.') {
                decimal++;
            }
            else {
                throw invalid_argument("You entered a non-numerical value!");
            }

            if (decimal > 1) {
                throw invalid_argument("You entered too many decimals!");
            }

            if (decimal == 1) {
                length = static_cast<int>(input.size()) - decimal;
            }
        }
    }

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
    else if (length > 16) {
        throw out_of_range("You entered a decimal number with more than 16 significant figures!");
    }

    return numConvert;
}

template<typename T>
T handleBool(const string& input, const T& param1, const T& param2) {
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

template<typename T>
T userInput(string& input, const T& param1, const T& param2, const bool& isClearBuffer) {
    const bool same1 = is_same<T, int>::value;
    const bool same2 = is_same<T, float>::value;
    const bool same3 = is_same<T, double>::value;
    const bool same4 = is_same<T, bool>::value;

    input = formatAndTrim(input);
    
    if (isClearBuffer) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (same1) {
        return handleInt(input, param1, param2);
    }
    else if (same2) {
        return handleFloat(input, param1, param2);
    }
    else if (same3) {
        return handleDouble(input, param1, param2);
    }
    else if (same4) {
        return handleBool(input, param1, param2);
    }
}

#endif // FUNCS_H
