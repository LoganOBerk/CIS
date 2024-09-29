#pragma once
#include "Animal.h"

class Dog : public Animal {
private :
	bool isCompanion;
	bool isDomesticated;
public:
	Dog(double const weight = 90.0, int const feetNumber = 4, string const typeOfAnimal = "Dog") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this ->typeOfAnimal = typeOfAnimal;
	}
	void makeSound() override{
		cout << "Woof" << endl;
	}
	void setFeetNumber(int &feetNumber) override{
		this->feetNumber = feetNumber;
	}
	void setWeight(double &weight) override {
		this->weight = weight;
	}
};