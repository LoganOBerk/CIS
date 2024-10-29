#include "myString.h"

using namespace std;

int main() {
	Status myStatus;
	myString* mine = new myString(myStatus, "");
	cout << mine->size();
	if (myStatus == Status::invalidParamValue) {
		cout << "Invalid Parameter string must be less than 100 chars!" << endl;
	}
	if (myStatus == Status::memoryAllocationFailure) {
		cout << "Memory Allocation Failure!" << endl;
	}

	return 0;
}