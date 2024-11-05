#include <iostream>
#include <fstream>
#include "myString.h"

using namespace std;

int main() {
    Status myStatus = Status::success;

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
    str1->logAction(logFile, "replWholeString", originalValue, " World ", str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("apple");
    str2 = str2->setString("apricot");
    originalValue = str1->getString();
    string comparisonResult = to_string(str1->compareString(*str2));
    str1->logAction(logFile, "compareString", originalValue, "apricot", comparisonResult, "Success");
    str1->writeResultsToFile(comparisonResult, outFile);
    cout << comparisonResult << endl;

    str1 = str1->setString("Hello");
    str2 = str2->setString("Hi");
    originalValue = str1->getString();
    str1 = str1->replPartString(*str2, 1, 4);
    str1->logAction(logFile, "replPartString", originalValue, "Hi, 1, 4", str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1 = str1->partString(1, 3);
    str1->logAction(logFile, "partString", originalValue, "1, 3", str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    str1->initString();
    originalValue = str1->getString();
    str1->logAction(logFile, "initString", originalValue, "", str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    str2 = str2->setString(" World ");
    originalValue = str1->getString();
    str1->addEnd(*str2);
    str1->logAction(logFile, "addEnd", originalValue, str2->getString(), str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1->addStart(*str2);
    str1->logAction(logFile, "addStart", originalValue, str2->getString(), str1->getString(), "Success");
    str1->writeResultsToFile(str1->getString(), outFile);
    str1->printStringScreen();

    string strValue = str1->getString();
    originalValue = str1->getString();
    str1->logAction(logFile, "getString", originalValue, "", strValue, "Success");
    str1->writeResultsToFile(strValue, outFile);
    cout << strValue << endl;

    string numericResult = to_string(str1->numericString());
    str1->logAction(logFile, "numericString", originalValue, "", numericResult, "Success");
    str1->writeResultsToFile(numericResult, outFile);
    cout << numericResult << endl;

    string alphabeticResult = to_string(str1->alphabeticString());
    str1->logAction(logFile, "alphabeticString", originalValue, "", alphabeticResult, "Success");
    str1->writeResultsToFile(alphabeticResult, outFile);
    cout << alphabeticResult << endl;

    delete str1;
    delete str2;

    outFile.close();
    logFile.close();
    cout << endl;

    // Print file contents
    str1->printFileContents("output.txt");
    cout << endl;
    str1->printFileContents("log.txt");

    return 0;
}
