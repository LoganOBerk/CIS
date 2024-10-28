#include "useful_funcs.h"

//Takes an input identifies values and allows accessing values in sentances by word number
string pullValue(string& input, int valNum) {
    valNum--;
    if (valNum < 0) {
        throw out_of_range("You cannot access less than 1 value!");
    }
    vector<string> values;
    int numVals = 0;
    for (int i = 0; i < input.size(); i++) {
        if (numVals == 0) {
            values.push_back(input.substr(0, input.find(' ')));
            numVals++;
        }
        if (input[i] == ' ') {
            values.push_back(input.substr(i + 1, input.substr(i + 1).find(' ')));
            numVals++;
        }
        if (i == input.size() - 1) {
            values.push_back(input.substr(input.rfind(' ') + 1, input.size() - 1));
            break;
        }
    }
    if (valNum >= numVals) {
        throw out_of_range("Trying to access value number " + to_string(valNum + 1) + " when there are only " + to_string(numVals) + " values!");
    }
    return values[valNum];
}

int numVals(string& input) {
    int numVals = 0;
    for (int i = 0; i < input.size(); i++) {
        if (numVals == 0) {
            numVals++;
        }
        if (input[i] == ' ') {
            numVals++;
        }
        if (i == input.size() - 1) {
            break;
        }
    }
    return numVals + 1;
}