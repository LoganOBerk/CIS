#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>

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
    void logAction(std::ofstream& logFile, const std::string& methodName, const std::string& originalValue,
        const std::string& parameters, const std::string& modifiedValue,
        const std::string& statusMessage);
    void writeResultsToFile(const std::string& result, std::ofstream& outFile);
    void printFileContents(const std::string& fileName);
};
