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

template<typename T>
T userInput(string&, const T&, const T&);
string userInput(string&, const string&, const string&, const bool);

//helper functions
bool isFileChar(const char);
string formatAndTrim(string&);




#endif FUNCS_H
