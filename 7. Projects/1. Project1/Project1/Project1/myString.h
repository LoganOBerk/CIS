#pragma once
#include<iostream>
#include <string>
#include <limits>

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
	myString(Status& extStatus, myString&);
	~myString();
	int size();
	void addStart(myString);
	char* addEnd(myString);
	myString partString(int, int);
	myString replPartString(myString, int, int);
	myString replWholeString(myString);
	int compareString(myString);
	void initString();
	myString setString(std::string);
	std::string getString();
	void printStringScreen();
	bool numericString();
	bool alphabeticString();
};