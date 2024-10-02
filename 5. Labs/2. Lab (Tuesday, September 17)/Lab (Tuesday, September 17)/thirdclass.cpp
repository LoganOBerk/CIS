#include "thirdclass.h"

void ThirdClass::printMe(){
	cout << getColor() << " object with " << getLength() << "X" << getWidth()
		<< "X" << height << " (volume = " << getLength() * getWidth() * height << ")" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	}

ThirdClass::~ThirdClass(){
	cout << "Class destroyed with color " << getColor() << ", length " << getLength() <<
		", width " << getWidth() << ", and height " << height << endl;
	cout << endl;
}