#ifndef THIRDCLASS_H
#define THIRDCLASS_H
#include "secondclass.h"

class ThirdClass : private SecondClass {
private:
	int height;
public:
	ThirdClass(int height = 2) { 
		this->height = height;
		cout << "Class created with color " << getColor() << ", length " << getLength() << 
			", width " << getWidth() << ", and height " << height << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}

	int getHeight() { return height; }
	void printMe();
	void setHeight(int height) { this->height = height; }

	~ThirdClass();

};
#endif THIRDCLASS_H