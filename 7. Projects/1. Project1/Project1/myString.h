#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

//String library only used for testing, and labels for file contents
#include <string>

enum class Status {
    success,
    invalidParamValue,
    memoryAllocationFailure,
};

class myString {
private:
    char* seqChars;
    int length;
    Status& status;

public:
    myString(Status& extStatus, std::string);
    myString(Status& extStatus, const myString&);
    ~myString();
    int size();
    void addStart(myString&);
    void addEnd(myString&);
    myString* partString(int, int);
    myString* replPartString(myString, int, int);
    myString* replWholeString(myString);
    int compareString(myString);
    void initString();
    myString* setString(std::string);
    std::string getString() const;
    void printStringScreen();
    bool numericString();
    bool alphabeticString();
    void logAction(std::ofstream&, const std::string&, const std::string&,
        const std::string&, const std::string&,
        const Status&);
    void writeResultsToFile(const std::string&, std::ofstream&);
    void printFileContents(const std::string&);
};
