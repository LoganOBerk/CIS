#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
#include <string>

using namespace std;

class FirstClass {
private:
	string color;
	int count;

public:
	FirstClass(string color = "Purple", int count = -17) {
		this->color = color;
		this->count = count;
		cout << "Class created with color " << color << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
	}
	~FirstClass();

	string getColor() { return color; }
	void setColor(string& color) { this->color = color;}
	int getCount() { return count; }
	void setCount(int& count) { this->count = count; }

	FirstClass(FirstClass&); //Copy Constructor
	void operator=(FirstClass&); //Overloading equals
};
#endif FIRSTCLASS_H