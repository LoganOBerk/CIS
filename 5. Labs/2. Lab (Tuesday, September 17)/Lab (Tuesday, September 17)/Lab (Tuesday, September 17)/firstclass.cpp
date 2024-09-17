#include "firstclass.h"

FirstClass::FirstClass(string color = "Purple", int count = -17) {
	cout << "Class created with color " + color << endl;
}

FirstClass::~FirstClass() {
	cout << "Class destroyed with color " + color + " and number " + to_string(count) << endl;
}