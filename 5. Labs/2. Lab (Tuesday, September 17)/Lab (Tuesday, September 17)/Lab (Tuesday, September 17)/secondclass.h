#pragma once
#include "firstclass.h"

using namespace std;

class SecondClass : protected FirstClass {
private:
	int length;
	int width;

public:
	SecondClass(){}
	SecondClass(int length = 2, int width = 7) {
		cout << "Class created with " + getColor() + " length " + to_string(length) + " and width " + to_string(width) << endl;
	}
	~SecondClass() {
		cout << "Class destroyed with " + getColor() + " length " + to_string(length) + " and width " + to_string(width) << endl;
	}

	int getLength() { return length;}
	void setLength(int& length) { this->length = length; }
	int getWidth() { return width; }
	int setWidth(int& width) { this->width = width; }
	void printMe() {
		cout << getColor() + " object with " + to_string(length) + "X" + to_string(width) + "(area = " + to_string(length * width) + ")" << endl;
	}
};