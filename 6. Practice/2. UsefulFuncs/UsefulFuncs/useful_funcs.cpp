#include "useful_funcs.h"

//Takes an input identifies values and allows accessing values in sentances by word number
string pullValue(string& input, int valNum) {
    int inputSize = static_cast<int>(input.size());
    int amountOfValues;
    string initialValue;
    string finalValue;
    if (--valNum < 0) {
        throw out_of_range("You cannot access less than 1 value!");
    }

    amountOfValues = countVals(input);


    initialValue = input.substr(0, input.find(' '));
    finalValue = input.substr(input.rfind(' ') + 1, inputSize - 1);

    vector<string> values;
    values.push_back(initialValue);
    for (int i = initialValue.size(); i < inputSize; i++) {
        if (input[i] == ' ') {
            values.push_back(input.substr(i + 1, input.substr(i + 1).find(' ')));
        }
    }
    if (amountOfValues > 1) {
        values.push_back(finalValue);
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