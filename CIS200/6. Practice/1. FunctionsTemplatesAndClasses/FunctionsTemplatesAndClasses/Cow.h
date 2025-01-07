#pragma once
#include "Animal.h"

class Cow : public Animal {
public:
	Cow(double const weight = 250.0, int const feetNumber = 4, string const typeOfAnimal = "Cow") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}

	void makeSound() override;

};