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

void myString::addStart(myString& appendChars) {
    int newLength = length + appendChars.size();
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return;
    }
    for (int i = 0; i < appendChars.length; i++) {
        newArr[i] = appendChars.seqChars[i];
    }
    for (int j = 0; j < length; j++) {
        newArr[appendChars.length + j] = seqChars[j];
    }
    newArr[newLength] = '\0';
    delete[] seqChars;
    seqChars = newArr;
    length = newLength;
}

void myString::addEnd(myString& appendChars) {
    int newLength = length + appendChars.size();
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return;
    }
    for (int i = 0; i < length; i++) {
        newArr[i] = seqChars[i];
    }
    for (int j = 0; j < appendChars.length; j++) {
        newArr[length + j] = appendChars.seqChars[j];
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

myString* myString::replPartString(myString objToInsert, int startPos, int length) {
    if (startPos < 1 || startPos > this->length || length > this->length - startPos) {
        status = Status::invalidParamValue;
        return new myString(status, "");
    }
    startPos--;
    int newLength = this->length - length + objToInsert.length;
    char* newArr = new char[newLength + 1];
    if (newArr == nullptr) {
        status = Status::memoryAllocationFailure;
        return nullptr;
    }
    for (int i = 0; i < startPos; ++i) {
        newArr[i] = this->seqChars[i];
    }
    for (int i = 0; i < objToInsert.length; ++i) {
        newArr[startPos + i] = objToInsert.seqChars[i];
    }
    for (int i = startPos + length; i < this->length; ++i) {
        newArr[i - length + objToInsert.length] = this->seqChars[i];
    }
    newArr[newLength] = '\0';
    return new myString(status, newArr);
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
    return (allowedChars == length);
}


void myString::logAction(std::ofstream& logFile, const std::string& methodName, const std::string& originalValue,
    const std::string& parameters, const std::string& modifiedValue,
    const Status& status) {

    std::string statusMessage;
    if (status == Status::success) {
        statusMessage = "Success";
    }
    if (status == Status::memoryAllocationFailure) {
        statusMessage = "MEMORY ALLOCATION FAILURE";
    }
    if (status == Status::invalidParamValue) {
        statusMessage = "INVALID PARAMETER";
    }
   
    logFile << std::left << std::setw(25) << methodName
        << std::setw(25) << originalValue
        << std::setw(25) << parameters
        << std::setw(25) << modifiedValue
        << statusMessage << std::endl;
}

void myString::writeResultsToFile(const std::string& result, std::ofstream& outFile) {
    outFile << result << std::endl;
}

void myString::printFileContents(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        return;
    }
    std::string line;
    std::cout << "Contents of " << fileName << ":" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
