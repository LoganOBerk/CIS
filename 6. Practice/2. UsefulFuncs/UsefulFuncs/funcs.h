#ifndef FUNCS_H
#define FUNCS_H

#define MAX_INT
#define MIN_INT
#define MAX_FLOAT
#define MIN_FLOAT
#define MAX_DOUBLE
#define MIN_DOUBLE

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <type_traits>

using namespace std;

const string alpha = "alpha";
const string numeric = "numeric";
const string file = "file";
const string character = "character";
const string null = "null";

//Helper functions
bool isFileChar(const char);
string formatAndTrim(string&);
void initialInputHandling(string&, const bool&, const bool&);



//Default template if no type is matched
template<typename T, typename Enable = void>
T userInput(string&, const T&, const T&, const bool&, const bool&) {
    static_assert(std::is_same<T, void>::value, "Invalid type for userInput");
}


//Specialization for int
template<>
inline int userInput<int>(string& input, const int& param1, const int& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    initialInputHandling(input, canHaveSpaces, isClearBuffer);

    int numConvert;
   

    for (const auto ch : input) {
        
        if (!isdigit(ch)) {
            if (ch == ' ') {
                throw invalid_argument("You entered more than one input.");
            }
            else{
                throw invalid_argument("You entered a non-integer value!");
            }
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


//Specialization for float
template<>
inline float userInput<float>(string& input, const float& param1, const float& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    initialInputHandling(input, canHaveSpaces, isClearBuffer);

    float numConvert;
    int decimal = 0;
    int length = 0;

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (ch == ' ') {
                throw invalid_argument("You entered more than one input.");
            }
            else if (ch == '.') {
                decimal++;
                if (decimal > 1) {
                    throw invalid_argument("You entered too many decimals!");
                }
            }
            else{
                throw invalid_argument("You entered a non-numerical value!");
            }

        }
    }
    length = static_cast<int>(input.size()) - decimal;


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
    else if (length > 7) {
        throw out_of_range("You entered a decimal number with more than 7 significant figures!");
    }

    return numConvert;
}


//Specialization for double
template<>
inline double userInput<double>(string& input, const double& param1, const double& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    initialInputHandling(input, canHaveSpaces, isClearBuffer);

    double numConvert;
    int decimal = 0;
    int length = 0;

    for (const auto ch : input) {
        if (!isdigit(ch)) {
            if (ch == ' ') {
                throw invalid_argument("You entered more than one input.");
            }else if (ch == '.') {
                decimal++;
                if (decimal > 1) {
                    throw invalid_argument("You entered too many decimals!");
                }
            }
            else {
                throw invalid_argument("You entered a non-numerical value!");
            }
        }
    }
    length = static_cast<int>(input.size()) - decimal;
   

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


//Specialization for string
template<>
inline string userInput<string>(string& input, const string& param1, const string& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    initialInputHandling(input, canHaveSpaces, isClearBuffer);

    for (auto ch : input) {
        if (ch == ' ' && !canHaveSpaces) {
            throw invalid_argument("There can be no spaces in the word!");
        }
        if (param1 == "alpha" && param2 == "numeric" && !(isdigit(ch) || isalpha(ch)) && ch != ' ') {
            if (canHaveSpaces) {
                throw invalid_argument("This is not an alpha-numeric list!");
            }
            throw invalid_argument("This is not an alpha-numeric value!");
        }
        else if (param1 == "alpha" && param2 == "null" && !isalpha(ch) && ch != ' ') {
            if (canHaveSpaces) {
                throw invalid_argument("You entered a non-alphabetic sentence!");
            }
            throw invalid_argument("You entered a non-alphabetic word!");
        }
        else if (param1 == "file" && param2 == "null" && !isFileChar(ch)) {
            throw invalid_argument("You entered an improper filename!");
        }
        else if (param1 == "character" && param2 == "null") {
            if (input.size() != 1 || !isalpha(ch)) {
                throw invalid_argument("This is not a character input!");
            }
        }

    }

    return input;
}


//Specialization for bool
template<>
inline bool userInput<bool>(string& input, const bool& param1, const bool& param2, const bool& canHaveSpaces, const bool& isClearBuffer) {
    initialInputHandling(input, canHaveSpaces, isClearBuffer);

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


#endif FUNCS_H
