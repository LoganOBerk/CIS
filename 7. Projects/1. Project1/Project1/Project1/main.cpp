#include "myString.h"

using namespace std;

int main() {
	Status myStatus;
	myString* interface = new myString(myStatus, "Hello I am a String");
	//myString notMine(myStatus, " world");
	myString* setANewString = interface->setString("hello");
	myString* makeASubstr = interface->partString(1, 5);
	myString* replPartString = interface->replPartString(*setANewString, 7, 12);
	replPartString->printStringScreen();
	//mine->addEnd(notMine);
	//mine->printStringScreen();
	if (myStatus == Status::invalidParamValue) {
		cout << "Invalid Parameter!" << endl;
	}
	if (myStatus == Status::memoryAllocationFailure) {
		cout << "Memory Allocation Failure!" << endl;
	}

	return 0;
}