#pragma once
#include <iostream>
#include <string>

using namespace std;

class FirstClass {
private:
	string color;
	int count;

public:
	FirstClass(){}
	FirstClass(string, int);
	~FirstClass();

	string getColor() { return color; }
	void setColor(string& color) { this->color = color;}

	FirstClass(FirstClass& copy) {
		color = copy.color;
		count = copy.count++;
		cout << "Class copied with color " + color + " and number " + to_string(count) << endl;
	}

	FirstClass operator=(FirstClass& overload) {
		color = overload.color;
		count = overload.count;
	}
};