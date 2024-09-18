#include "secondclass.h"

 void SecondClass::printMe(){
	 cout << getColor() << " object with " << length << "X" << width << "(area = " << length * width << ")" << endl;
	 cout << "--------------------------------------------------------------------------------" << endl;
	}

 SecondClass::~SecondClass(){
	 cout << "Class destroyed with " << getColor() << " length " << length << " and width " << width << endl;
	 cout << endl;
	}