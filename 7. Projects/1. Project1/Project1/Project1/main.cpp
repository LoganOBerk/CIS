#include "myString.h"

using namespace std;

int main() {
	Status myStatus;
	myString* interface = new myString(myStatus, "Hello I am a String");
	//myString notMine(myStatus, " world");
	myString* setANewString = interface->setString("hello");
	myString* makeASubstr = interface->partString(1, 5);
	myString* replPartString = interface->replPartString(*setANewString, 7, 1);
	if (myStatus == Status::invalidParamValue) {
		cout << "Invalid Parameter!" << endl;
	}
	if (myStatus == Status::memoryAllocationFailure) {
		cout << "Memory Allocation Failure!" << endl;
	}
	replPartString->printStringScreen();
	//mine->addEnd(notMine);
	//mine->printStringScreen();
	

	return 0;
}