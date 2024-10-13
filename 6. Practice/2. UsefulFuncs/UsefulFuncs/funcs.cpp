#include <string>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <map>

using namespace std;


bool isFileChar(char ch) {
	const string unallowedChars = "<>:\"/\\|?*";
	return unallowedChars.find(ch) == string::npos;
}

string formatAndTrim(string& str) {
	for (auto& ch : str) {
		ch = tolower(ch);
	}
	auto start = find_if_not(str.begin(), str.end(), ::isspace);
	auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();
	return string(start, end);
}
template<typename T>
T userInput(string& input) {

}
template<typename T>
T userInput(string& input, T param1) {

}
template<typename T>
T userInput(string& input, T param1, T param2) {
	input = formatAndTrim(input);
	if (is_same< T, int>::value) {
		T numConvert;
		for (auto ch : input) {
			if (!isdigit(ch)) {
				throw invalid_argument("You entered a non-integer value!");
			}
		}
		numConvert = stoi(input);
		if (numConvert < param1 || numConvert > param2) {
			throw out_of_range("You entered a number outside of the range ( " + to_string(param1) +  ", " + to_string(param2) + " )");
		}
		return numConvert;
	} else if (is_same< T, double >::value) {
		T numConvert;

		int decimal = 0;
		int length = 0;
		for (auto ch : input) {
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
			throw out_of_range("You entered a number outside of the range ( " + to_string(param1) + ", " + to_string(param2) + " )");
		}
		else if (length > 16) {
			throw out_of_range("You entered a number with more than 16 significant figures!");
		}
		return numConvert;
	} else if (is_same< T, float >::value) {
		T numConvert;

		int decimal = 0;
		int length = 0;
		for (auto ch : input) {
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
			throw out_of_range("You entered a number outside of the range ( " + to_string(param1) + ", " + to_string(param2) + " )");
		}
		else if (length > 7) {
			throw out_of_range("You entered a number with more than 7 significant figures!");
		}
		return numConvert;
	
	} else if (is_same< T, bool >::value) {
		if (param1 != param2) {
			return false;
		}
		else if (input == "true" || input == "1") {
			return true;
		}
		else if (input == "false" || input == "0") {
			return false;
		}
		else{
			throw invalid_argument("Not a true/false value!");
		}
		
		
		
	//TODO FIX THIS	
	
	} else if (is_same< T, string >::value) {
		string p1 = static_cast<string>(param1);
		string p2 = static_cast<string>(param2);
		for (auto ch : input) {
			if (p1 == "alpha" && p2 == "numeric") {
				if (!isdigit(ch) && !isalpha(ch)) {
					throw invalid_argument("This is not an alpha-numeric value!");
				}
			}
			else if (p1 == "alpha") {
				if (!isalpha(ch)) {
					throw invalid_argument("You entered a non-alphebetic word!");
				}
			}
			else if (p1 == "file") {
				if (!isFileChar(ch)) {
					throw invalid_argument("You entered an improper filename!");
				}
			}
		}
		return input;
	}
	
	
	

	
	

	
}

int main() {
	string input;
	try {
		getline(cin, input);
		cout << userInput<bool>(input, true, true) << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
		
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
	return 0;
}