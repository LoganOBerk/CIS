#include <iostream>
#include <fstream>
#include <iomanip>
#include "myString.h"

using namespace std;

void logAction(ofstream& logFile, const string& methodName, const string& originalValue,
    const string& parameters, const string& modifiedValue,
    const string& statusMessage) {
    logFile << left << setw(25) << methodName
        << setw(25) << originalValue
        << setw(25) << parameters
        << setw(25) << modifiedValue
        << statusMessage << endl;
}

void writeResultsToFile(myString* str, const string& result, ofstream& outFile) {
    outFile << result << endl;
}

void printFileContents(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Unable to open file: " << fileName << endl;
        return;
    }
    string line;
    cout << "Contents of " << fileName << ":" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    Status myStatus;

    ofstream outFile("output.txt");
    ofstream logFile("log.txt");

    logFile << left << setw(25) << "Method Called"
        << setw(25) << "Original Value"
        << setw(25) << "Parameters"
        << setw(25) << "Modified Value"
        << "Status" << endl;

    myString* str1 = new myString(myStatus, "Hello");
    myString* str2 = new myString(myStatus, " World ");

    string originalValue = str1->getString();
    str1 = str1->replWholeString(*str2);
    logAction(logFile, "replWholeString", originalValue, " World ", str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("apple");
    str2 = str2->setString("apricot");
    originalValue = str1->getString();
    string comparisonResult = to_string(str1->compareString(*str2));
    logAction(logFile, "compareString", originalValue, "apricot", comparisonResult, "Success");
    writeResultsToFile(str1, comparisonResult, outFile);
    cout << comparisonResult << endl;

    str1 = str1->setString("Hello");
    str2 = str2->setString("Hi");
    originalValue = str1->getString();
    str1 = str1->replPartString(*str2, 1, 4);
    logAction(logFile, "replPartString", originalValue, "Hi, 1, 4", str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1 = str1->partString(1, 3);
    logAction(logFile, "partString", originalValue, "1, 3", str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    str1->initString();
    originalValue = str1->getString();
    logAction(logFile, "initString", originalValue, "", str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    str2 = str2->setString(" World ");
    originalValue = str1->getString();
    str1->addEnd(*str2);
    logAction(logFile, "addEnd", originalValue, str2->getString(), str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1->addStart(*str2);
    logAction(logFile, "addStart", originalValue, str2->getString(), str1->getString(), "Success");
    writeResultsToFile(str1, str1->getString(), outFile);
    str1->printStringScreen();

    string strValue = str1->getString();
    originalValue = str1->getString();
    logAction(logFile, "getString", originalValue, "", strValue, "Success");
    writeResultsToFile(str1, strValue, outFile);
    cout << strValue << endl;

    string numericResult = to_string(str1->numericString());
    logAction(logFile, "numericString", originalValue, "", numericResult, "Success");
    writeResultsToFile(str1, numericResult, outFile);
    cout << numericResult << endl;

    string alphabeticResult = to_string(str1->alphabeticString());
    logAction(logFile, "alphabeticString", originalValue, "", alphabeticResult, "Success");
    writeResultsToFile(str1, alphabeticResult, outFile);
    cout << alphabeticResult << endl;

    delete str1;
    delete str2;

    outFile.close();
    logFile.close();
    cout << endl;

    printFileContents("output.txt");
    cout << endl;
    printFileContents("log.txt");

    return 0;
}
