#include "firstclass.h"

 FirstClass::FirstClass(FirstClass& copy){
	 color = copy.color;
	 count = ++copy.count;
	 cout << "Class copied with color " << color << " and number " << count << endl;
	 cout << "--------------------------------------------------------------------------------" << endl;
	}

 void FirstClass::operator=(FirstClass& overload){
	 color = overload.color;
	 count = overload.count;
	}

FirstClass::~FirstClass() {
	cout << "Class destroyed with color " + color + " and number " + to_string(count) << endl;
	cout << endl;
}