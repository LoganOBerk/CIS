#include "myString.h"

myString::myString(Status& extStatus, std::string stringToConvert) : status(extStatus), seqChars(nullptr), length(0) {
    if (extStatus == Status::memoryAllocationFailure) {
        std::cout << "MEMORY ALLOCATION FAILURE" << std::endl;
        status = Status::success;
        return;
    }
    if (extStatus == Status::invalidParamValue) {
        std::cout << "INVALID PARAMETER" << std::endl;
        status = Status::success;
        return;
    }
    length = static_cast<int>(stringToConvert.size());
    seqChars = new char[length + 1];
    if (seqChars == nullptr) {
        extStatus = Status::memoryAllocationFailure;
        return;
    }
    for (int i = 0; i < length; i++) {
        seqChars[i] = stringToConvert[i];
    }
    seqChars[length] = '\0';
}

myString::myString(Status& extStatus, const myString& objToCopy) : status(extStatus), seqChars(nullptr), length(objToCopy.length) {
    seqChars = new char[length + 1];
    if (seqChars == nullptr) {
        extStatus = Status::memoryAllocationFailure;
        return;
    }
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
}

void myString::addStart(myString& inputStringObj) {
    int newLength = length + inputStringObj.size();
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return;
    }
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
}

void myString::addEnd(myString& inputStringObj) {
    int newLength = length + inputStringObj.size();
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return;
    }
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
}

myString* myString::partString(int startPos, int length) {
    if (startPos < 1 || startPos > this->length || length > this->length - startPos + 1 || seqChars == nullptr) {
        status = Status::invalidParamValue;
        return new myString(status, "");
    }
    startPos--;
    char* newArr = new char[length + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return nullptr;
    }
    for (int i = 0; i < length; i++) {
        newArr[i] = seqChars[startPos + i];
    }
    newArr[length] = '\0';
    return new myString(status, newArr);
}

myString* myString::replPartString(myString objToAdd, int startPos, int length) {
    if (startPos < 1 || startPos > this->length || length > this->length - startPos) {
        status = Status::invalidParamValue;
        return new myString(status, "");
    }
    startPos--;
    int newLength = this->length - length + objToAdd.length;
    char* newCharArray = new char[newLength + 1];
    if (newCharArray == nullptr) {
        status = Status::memoryAllocationFailure;
        return nullptr;
    }
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
}

myString* myString::replWholeString(myString objToReplace) {
    int newLength = objToReplace.length;
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return nullptr;
    }
    for (int i = 0; i < objToReplace.length; i++) {
        newArr[i] = objToReplace.seqChars[i];
    }
    newArr[newLength] = '\0';
    delete[] seqChars;
    seqChars = newArr;
    length = newLength;
    return this;
}

int myString::compareString(myString stringToCompare) {
    int sameChars = 0;
    if (length > stringToCompare.length) {
        for (int i = 0; i < stringToCompare.length; i++) {
            if (seqChars[i] == stringToCompare.seqChars[i]) {
                sameChars++;
            }
        }
        return sameChars + 1;
    }
    if (length < stringToCompare.length) {
        for (int i = 0; i < length; i++) {
            if (seqChars[i] == stringToCompare.seqChars[i]) {
                sameChars++;
            }
        }
        return -sameChars - 1;
    }
    return sameChars;
}

void myString::initString() {
    length = 0;
    delete[] seqChars;
    seqChars = nullptr;
    status = Status::success;
}

myString* myString::setString(std::string stringToConvert) {
    return new myString(status, stringToConvert);
}

std::string myString::getString() const {
    return seqChars ? std::string(seqChars) : "";
}

void myString::printStringScreen() {
    if (seqChars) {
        for (int i = 0; i < length; i++) {
            std::cout << seqChars[i];
        }
        std::cout << std::endl;
    }
}

bool myString::numericString() {
    int allowedChars = 0;
    bool hasNums = false;
    for (int i = 0; i < length; i++) {
        if (seqChars[i] >= '0' && seqChars[i] <= '9') {
            allowedChars++;
            hasNums = true;
        }
        if (seqChars[i] == ' ' || seqChars[i] == '\t' || seqChars[i] == '.' || seqChars[i] == '+' || seqChars[i] == '-') {
            allowedChars++;
        }
    }
    return (allowedChars == length) && hasNums;
}

bool myString::alphabeticString() {
    int allowedChars = 0;
    for (int i = 0; i < length; i++) {
        if ((seqChars[i] >= 'A' && seqChars[i] <= 'Z') || (seqChars[i] >= 'a' && seqChars[i] <= 'z')) {
            allowedChars++;
        }
        if (seqChars[i] == ' ' || seqChars[i] == '\t') {
            allowedChars++;
        }
    }
    return allowedChars == length;
}
