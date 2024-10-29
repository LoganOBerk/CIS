#include "myString.h"
myString::myString(Status& extStatus, std::string stringToConvert) : status(extStatus), seqChars(nullptr){
	length = static_cast<int>(stringToConvert.size());
	seqChars = new char[length];
	if (seqChars = nullptr) {
		extStatus = Status::memoryAllocationFailure;
		return;
	}
	if (length > 100) {
		extStatus = Status::invalidParamValue;
		return;
	}
}
myString::myString(Status& extStatus,myString& objToCopy) : status(extStatus), seqChars(nullptr) {
	length = objToCopy.length;
	seqChars = new char[length];
	extStatus = objToCopy.status;

}
myString::~myString() {
	delete[] seqChars;
}

int myString::size() {
	return length;
}

void myString::addStart(myString inputStringObj) {
	length += inputStringObj.size();
	seqChars = new char[length + 1];
	
}
/*;
char* addEnd(myString inputStringObj) {
};
myString partString(int startPos, int length);
myString replPartString(myString, int startPos, int length);
myString replWholeString(myString);
int compareString(myString);
void initString();
*/
myString setString(std::string stringToConvert) {
	
};
/*
std::string getString();
void printStringScreen();
bool numericString();
bool alphabeticString();
*/