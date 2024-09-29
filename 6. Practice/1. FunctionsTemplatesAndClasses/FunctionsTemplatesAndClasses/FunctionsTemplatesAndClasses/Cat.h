#pragma once
#include "Animal.h"

class Cat : public Animal {
private:
	bool isCompanion;
	bool isDomesticated;
public:
	Cat(double const weight = 20.0, int const feetNumber = 4, string const typeOfAnimal = "Cat") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}
	void makeSound() override {
		cout << "Meow" << endl;
	}
	void setFeetNumber(int& feetNumber) override {
		this->feetNumber = feetNumber;
	}
	void setWeight(double& weight) override {
		this->weight = weight;
	}
};