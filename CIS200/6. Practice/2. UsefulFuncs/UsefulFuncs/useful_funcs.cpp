#include "useful_funcs.h"

//Takes an input identifies values and allows accessing values in sentances by word number
string pullValue(string& input, int valNum) {
    if (--valNum < 0) {
        throw out_of_range("You cannot access less than 1 value!");
    }

    int amountOfValues = countVals(input);
    
    vector<string> values;
    istringstream iss(input);
    string value;
    while (iss >> value) {
        values.push_back(value);
    }
    if (valNum >= amountOfValues) {
        throw out_of_range("Trying to access value number " + to_string(valNum + 1) + " when there are only " + to_string(amountOfValues) + " values!");
    }
    return values[valNum];
}

int countVals(string& input) {
    int numVals = 1;
    for (auto val : input) {
        if (val == ' ') {
            numVals++;
        }
    }
    return numVals;
}