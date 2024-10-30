#include "myString.h"

myString::myString(Status& extStatus, std::string stringToConvert) : status(extStatus) {
	length = static_cast<int>(stringToConvert.size());
	seqChars = new char[length + 1];
	for (int i = 0; i < length; i++) {
		seqChars[i] = stringToConvert[i];
	}
	seqChars[length] = '\0';

	if (seqChars == nullptr) {
		extStatus = Status::memoryAllocationFailure;
		return;
	}
};
myString::myString(Status& extStatus,const myString& objToCopy) : status(extStatus){
	length = objToCopy.length;
	seqChars = new char[length + 1];
	for (int i = 0; i < length; i++) {
		seqChars[i] = objToCopy.seqChars[i];
	}
	seqChars[length] = '\0';

	extStatus = objToCopy.status;

}
myString::~myString() {
	delete[] seqChars;
}

int myString::size() {
	return length;
};

void myString::addStart(myString& inputStringObj) {
	int newLength = length + inputStringObj.size();
	char* newArr = new char[newLength + 1];

	for (int i = 0; i < inputStringObj.length; i++) {
		newArr[i] = inputStringObj.seqChars[i];
	}

	for (int j = 0; j < length; j++) {
		newArr[inputStringObj.length + j] = seqChars[j];
	}

	newArr[newLength] = '\0';
	delete[] seqChars;
	seqChars = newArr;
	length = newLength;
};

void myString::addEnd(myString& inputStringObj) {
int newLength = length + inputStringObj.size();
	char* newArr = new char[newLength + 1];

	for (int i = 0; i < length; i++) {
		newArr[i] = seqChars[i];
	}

	for (int j = 0; j < inputStringObj.length; j++) {
		newArr[length + j] = inputStringObj.seqChars[j];
	}

	newArr[newLength] = '\0';
	delete[] seqChars;
	seqChars = newArr;
	length = newLength;
};

myString* myString::partString(int startPos, int length) {
	
	if (startPos < 1 || startPos > this->length || length > this->length) {
		status = Status::invalidParamValue;
		return;
	}
	startPos--;
	char* newArr = new char[length + 1];
	for (int i = 0; i < length; i++) {
		newArr[i] = seqChars[startPos + i];
	}
	newArr[length] = '\0';
	return new myString(status, newArr);
};

myString* myString::replPartString(myString objToAdd, int startPos, int length) {

	if (startPos < 1 || startPos > this->length || length > this->length - startPos - 1) {
		status = Status::invalidParamValue;
		return;
	}


	startPos--;


	int newLength = this->length - length + objToAdd.length;


	char* newCharArray = new char[newLength + 1];


	for (int i = 0; i < startPos; ++i) {
		newCharArray[i] = this->seqChars[i];
	}


	for (int i = 0; i < objToAdd.length; ++i) {
		newCharArray[startPos + i] = objToAdd.seqChars[i];
	}


	for (int i = startPos + length; i < this->length; ++i) {
		newCharArray[i - length + objToAdd.length] = this->seqChars[i];
	}


	newCharArray[newLength] = '\0';

	return new myString(status, newCharArray);
};

myString replWholeString(myString);
int compareString(myString);
void initString();

myString* myString::setString(std::string stringToConvert) {
	return new myString(status, stringToConvert);
};

std::string myString::getString(){
	return seqChars;
};

void myString::printStringScreen(){
	for (int i = 0; i < length; i++) {
		std::cout << seqChars[i];
	}
};

bool myString::numericString() {
	int allowedChars = 0;
	bool hasNums = false;
	for (int i = 0; i < length; i++) {
		if (seqChars[i] >= 48 && seqChars[i] <= 57) {
			allowedChars++;
			hasNums = true;
		}
		if (seqChars[i] == ' ' || seqChars[i] == '\t' || seqChars[i] == '.' || seqChars[i] == '+' || seqChars[i] == '-') {
			allowedChars++;
		}
	}
	return (allowedChars == length) && hasNums;
};
bool myString::alphabeticString() {
	int allowedChars = 0;
	for (int i = 0; i < length; i++) {
		if ((seqChars[i] >= 65 && seqChars[i] <= 90) || (seqChars[i] >= 97 && seqChars[i] <= 122)) {
			allowedChars++;
		}
		if (seqChars[i] == ' ' || seqChars[i] == '\t') {
			allowedChars++;
		}
	}
	return allowedChars == length;
};