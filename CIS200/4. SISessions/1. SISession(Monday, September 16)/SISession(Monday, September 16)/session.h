#ifndef CAR
#define CAR

#include <string>
#include <iostream>

using namespace std;

class Car {
private:
	string color;
	string make;
	string model;
	int year;
	int doors;
public:
	void setColor(string);
	string getColor();
	void setMake(string);
	string getMake();
	void setModel(string);
	string getModel();
	void setYear(int);
	int getYear();
	void setDoors(int);
	int getDoors();
};
#endif CAR
