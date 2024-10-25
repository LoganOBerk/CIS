#include "useful_funcs.h"

//Takes an input identifies words and allows accessing words in sentances by word number
string pullWord(string& input, int wordNumber) {
    wordNumber--;
    if (wordNumber < 0) {
        throw out_of_range("You cannot access less than 1 word!");
    }
    vector<string> words;
    int numWords = 0;
    for (int i = 0; i < input.size(); i++) {
        if (numWords == 0) {
            words.push_back(input.substr(0, input.find(' ')));
            numWords++;
        }
        if (input[i] == ' ') {
            words.push_back(input.substr(i + 1, input.substr(i + 1).find(' ')));
            numWords++;
        }
        if (i == input.size() - 1) {
            words.push_back(input.substr(input.rfind(' ') + 1, input.size() - 1));
            break;
        }
    }
    if (wordNumber >= numWords) {
        throw out_of_range("Trying to access word number " + to_string(wordNumber + 1) + " when there are only " + to_string(numWords) + " words!");
    }
    return words[wordNumber];
}