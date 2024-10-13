#include "funcs.h"

// Check if a character is valid for filenames
bool isFileChar(const char ch) {
    static const string unallowedChars = "<>:\"/\\|?*";
    return unallowedChars.find(ch) == string::npos;
}

// Convert string to lowercase and trim whitespace
string formatAndTrim(string& str) {
    for (auto& ch : str) {
        ch = tolower(ch);
    }

    auto start = find_if_not(str.begin(), str.end(), ::isspace);
    auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();

    return string(start, end);
}

// Validate and convert user input based on type
template<typename T>
T userInput(string& input, const T& param1, const T& param2) {
    const bool same1 = is_same<T, int>::value;
    const bool same2 = is_same<T, double>::value;
    const bool same3 = is_same<T, float>::value;
    const bool same4 = is_same<T, bool>::value;

    input = formatAndTrim(input);

    if (same1) {
        T numConvert;

        for (const auto ch : input) {
            if (!isdigit(ch)) {
                throw invalid_argument("You entered a non-integer value!");
            }
        }

        numConvert = stoi(input);

        if (numConvert < param1 || numConvert > param2) {
            throw out_of_range("You entered a number outside of the range ( "
                + to_string(param1) + ", " + to_string(param2) + " )");
        }

        return numConvert;

    }
    else if (same2) {
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

        numConvert = stod(input);

        if (numConvert < param1 || numConvert > param2) {
            throw out_of_range("You entered a number outside of the range ( "
                + to_string(param1) + ", " + to_string(param2) + " )");
        }
        else if (length > 16) {
            throw out_of_range("You entered a decimal number with more than 16 significant figures!");
        }

        return numConvert;

    }
    else if (same3) {
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

        numConvert = stof(input);

        if (numConvert < param1 || numConvert > param2) {
            throw out_of_range("You entered a number outside of the range ( "
                + to_string(param1) + ", " + to_string(param2) + " )");
        }
        else if (length > 7) {
            throw out_of_range("You entered a decimal number with more than 7 significant figures!");
        }

        return numConvert;

    }
    else if (same4) {
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
}

// Validate user input based on restrictions
string userInput(string& input, const string& param1, const string& param2, const bool spaces) {
    const char temp = 'o';

    for (auto ch : input) {
        if (ch == ' ' && spaces) {
            ch = temp;
        }

        if (param1 == "alpha" && param2 == "numeric" && !(isdigit(ch) || isalpha(ch))) {
            if (ch == ' ') {
                throw invalid_argument("There can be no spaces in the word!");
            }
            if (spaces) {
                throw invalid_argument("This is not an alpha-numeric list!");
            }
            throw invalid_argument("This is not an alpha-numeric value!");
        }
        else if (param1 == "alpha" && param2 == "null" && !isalpha(ch)) {
            if (ch == ' ') {
                throw invalid_argument("There can be no spaces in the word!");
            }
            if (spaces) {
                throw invalid_argument("You entered a non-alphabetic sentence!");
            }
            throw invalid_argument("You entered a non-alphabetic word!");
        }
        else if (param1 == "file" && param2 == "null" && !isFileChar(ch)) {
            throw invalid_argument("You entered an improper filename!");
        }
    }

    return input;
}

