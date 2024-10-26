#include "userInput_utils.h"

#ifndef USEFUL_FUNCS_H
#define USEFUL_FUNCS_H

//Usefull func prototypes
string pullWord(string&, const int);

//**userInput template function**
//Default template if no type is matched
template<typename T, typename Enable = void>
inline typename enable_if<!is_arithmetic<T>::value, T>::type
userInput(string&, const T&, const T&, const bool&, const bool&, const bool&) {
    static_assert(is_same<T, void>::value, "Invalid type for userInput!");
}

//**userInput template function**
//Specialization for integral types
template<typename T>
inline typename enable_if<is_integral<T>::value, T>::type
userInput(string& input, const T& param1, const T& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    checkForValidBools<T>(singleInput, caseSensitive);
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive, DEFAULT_DELIMITER);

    T numConvert;
    bool isScientific = validateSegments(input, RegexPatterns::scientificNotation);
    bool allIntegers = validateSegments(input, RegexPatterns::integral);
    bool hasSpaces = (input.find(' ') != string::npos || input.find('\t') != string::npos);


    if (!isScientific && !allIntegers) {  //checks if input is not scientific or not a proper integer
        throw invalid_argument("You entered a non-integer value!");
    }
    try {
        if (stold(input) > numeric_limits<T>::max() || stold(input) < numeric_limits<T>::min()) { //checks if input is outside of max range
            throw out_of_range("");
        }
        else if (stold(input) != static_cast<T>(stold(input))) { //checks if inputs conversion is an integer (primarily useful for determining scientific notation)
            throw invalid_argument("You entered a non-integer value!");
        }
        else if (hasSpaces && allIntegers && stold(input) == static_cast<T>(stold(input))) {
            throw invalid_argument("You entered more than one input!");
        }
    }
    catch (const out_of_range&) { //catches all out of range errors including potential stold out of range errors
        throw out_of_range("You entered a number much too large or small!");
    }

    numConvert = static_cast<T>(stold(input));
    if (numConvert < param1 || numConvert > param2) {
        throw out_of_range("You entered a number outside of the range ( "
            + to_string(param1) + ", " + to_string(param2) + " )");
    }

    return numConvert;
}


//**userInput template function**
//Specialization for floating point types
template<typename T>
inline typename enable_if<is_floating_point<T>::value, T>::type
userInput(string& input, const T& param1, const T& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    checkForValidBools<T>(singleInput, caseSensitive);
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive, DEFAULT_DELIMITER);

    int decimal = 0;
    int length = 0;
    bool isScientific = validateSegments(input, RegexPatterns::scientificNotation);
    bool allFloatingPointNums = validateSegments(input, RegexPatterns::floatingPoint);
    bool hasSpaces = (input.find(' ') != string::npos || input.find('\t') != string::npos);

    if (hasSpaces && allFloatingPointNums) {
        throw invalid_argument("You entered more than one input!");
    }

    for (const auto ch : input) {
        if (!isDigit(ch)) {
            if (ch == '.') {
                decimal++;
            }
            else if (!allFloatingPointNums) {
                throw invalid_argument("You entered a non-numerical value!");
            }

        }
    }

    if (decimal > 1) {
        throw invalid_argument("You entered too many decimals!");
    }

    length = findSigFigLength(input, isScientific, decimal);


    return validatedFloatingPoint<T>(input, param1, param2, decimal, length);
}


//**userInput template function**
//Specialization for string
template<>
inline string userInput<string>(string& input, const string& param1, const string& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    if (param1 == IS_CHARACTER || param1 == IS_FILE) {
        initialInputHandling(input, singleInput, isClearBuffer, caseSensitive, ' ');  //changes delimeter to space
    }
    else {
        initialInputHandling(input, singleInput, isClearBuffer, caseSensitive, DEFAULT_DELIMITER);
    }
    bool hasSpaces = (input.find(' ') != string::npos || input.find('\t') != string::npos);

    for (auto ch : input) {
        if (ch != '\0') {
            if (hasSpaces && singleInput) {
                if (param1 != IS_CHARACTER) {
                    throw invalid_argument("You entered more than one word!");
                }
                throw invalid_argument("You entered more than one character!");
            }
            if (param1 == IS_ALPHA && param2 == IS_NUMERIC && !(isDigit(ch) || isAlpha(ch)) && ch != ' ' && ch != '\t') {
                if (!singleInput) {
                    throw invalid_argument("This is not an alpha-numeric list!");
                }
                throw invalid_argument("This is not an alpha-numeric value!");
            }
            else if (param1 == IS_ALPHA && param2 == IS_NULL && !isAlpha(ch) && ch != ' ' && ch != '\t') {
                if (!singleInput) {
                    throw invalid_argument("You entered a non-alphabetic sentence!");
                }
                throw invalid_argument("You entered a non-alphabetic word!");
            }
            else if (param1 == IS_FILE && param2 == IS_NULL && !isFileChar(ch)) {
                throw invalid_argument("You entered an improper filename!");
            }
            else if (param1 == IS_CHARACTER && param2 == IS_NULL && input.size() != 1) {
                if (!singleInput) {
                    throw invalid_argument("ARGUMENT: singleInput MUST BE TRUE FOR CHARACTERS!");
                }
                throw invalid_argument("This is not a character input!");

            }
        }

    }
    return input;
}


//USERINPUT
//Specialization for bool
template<>
inline bool userInput<bool>(string& input, const bool& param1, const bool& param2, const bool& singleInput, const bool& isClearBuffer, const bool& caseSensitive) {
    checkForValidBools<bool>(singleInput, caseSensitive);
    initialInputHandling(input, singleInput, isClearBuffer, caseSensitive, DEFAULT_DELIMITER);
    if (param1 != param2) {
        return false;
    }
    else if (input == "true" || input == "1" || input == "yes" || input == "y") {
        return true;
    }
    else if (input == "false" || input == "0" || input == "no" || input == "n") {
        return false;
    }
    else {
        throw invalid_argument("Not a true/false value!");
    }
}



#endif
