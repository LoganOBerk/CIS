#ifndef SECONDCLASS_H
#define SECONDCLASS_H
#include "firstclass.h"

using namespace std;

class SecondClass : protected FirstClass {
private:
	int length;
	int width;

public:
	SecondClass(int length = 2, int width = 7) {
		this->length = length;
		this->width = width;
		cout << "Class created with " << getColor() << " length " << length << " and width " << width << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}

	int getLength() { return length; }
	void setLength(int& length) { this->length = length; }
	int getWidth() { return width; }
	int setWidth(int& width) { this->width = width; }
	void printMe();

	~SecondClass();
};
#endif SECONDCLASS_H