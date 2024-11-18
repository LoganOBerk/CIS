/************************
* Programer Name: Logan Berk
*
* Purpose: To create and demonstate the functionality of a custom myString class
*
* Create Date: 10/29/2024
*
* Modified Date: 11/18/2024
*************************/

#include "myString.h"

using namespace std;

int main() {
    // Initialize variables and files
    Status myStatus = Status::success;
    ofstream outFile("output.txt");
    ofstream logFile("log.txt");

    // Log header
    logFile << left << setw(25) << "Method Called"
        << setw(25) << "Original Value"
        << setw(25) << "Parameters"
        << setw(25) << "Modified Value"
        << "Status" << endl;

    // Create myString objects
    myString* str1 = new myString(myStatus, "Hello");
    myString* str2 = new myString(myStatus, " World ");

    string originalValue, resultingValue;

    // replWholeString
    originalValue = str1->getString();
    str1 = str1->replWholeString(*str2);
    resultingValue = str1->getString();
    str1->logAction(logFile, "replWholeString", originalValue, " World ", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // compareString
    str1 = str1->setString("apple");
    str2 = str2->setString("apricot");
    originalValue = str1->getString();
    resultingValue = to_string(str1->compareString(*str2));
    str1->logAction(logFile, "compareString", originalValue, "apricot", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // replPartString
    str1 = str1->setString("Hello");
    str2 = str2->setString("Hi");
    originalValue = str1->getString();
    str1 = str1->replPartString(*str2, 1, 4);
    resultingValue = str1->getString();
    str1->logAction(logFile, "replPartString", originalValue, "Hi, 1, 4", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // partString
    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1 = str1->partString(1, 3);
    resultingValue = str1->getString();
    str1->logAction(logFile, "partString", originalValue, "1, 3", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // initString
    originalValue = str1->getString();
    str1->initString();
    resultingValue = str1->getString();
    str1->logAction(logFile, "initString", originalValue, "", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // addEnd
    str1 = str1->setString("Hello");
    str2 = str2->setString(" World ");
    string param = str2->getString();
    originalValue = str1->getString();
    str1->addEnd(*str2);
    resultingValue = str1->getString();
    str1->logAction(logFile, "addEnd", originalValue, param, resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // addStart
    str1 = str1->setString("Hello");
    originalValue = str1->getString();
    str1->addStart(*str2);
    resultingValue = str1->getString();
    str1->logAction(logFile, "addStart", originalValue, param, resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // getString
    originalValue = str1->getString();
    resultingValue = str1->getString();
    str1->logAction(logFile, "getString", originalValue, "", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // numericString
    resultingValue = to_string(str1->numericString());
    str1->logAction(logFile, "numericString", originalValue, "", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // alphabeticString
    resultingValue = to_string(str1->alphabeticString());
    str1->logAction(logFile, "alphabeticString", originalValue, "", resultingValue, myStatus);
    str1->writeResultsToFile(resultingValue, outFile);
    cout << resultingValue << endl;

    // Print file contents
    str1->printFileContents("output.txt");
    cout << endl;
    str1->printFileContents("log.txt");

    // Cleanup
    delete str1;
    delete str2;

    outFile.close();
    logFile.close();

    cout << endl;
    return 0;
}
