#pragma once
#include <iostream>
using namespace std;

class Animal {
protected:
	double weight;
	int feetNumber;
	string typeOfAnimal;

public:

	Animal(double const weight = 0, int const feetNumber = 0, string const typeOfAnimal = "Placeholder") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}
	double getWeight() const{ return this->weight; }
	int getFeetNumber() const{ return this->feetNumber; }
	void printWeight() {
		cout << "I am a " << typeOfAnimal << " that weighs " << weight << "lbs." << endl;
	}
	virtual void makeSound() = 0;
	virtual void setWeight(double&) = 0;
	virtual void setFeetNumber(int&) = 0;
};