#pragma once
#include "Animal.h"

class Giraffe : public Animal {
public:
	Giraffe(double const weight = 3000, int const feetNumber = 4, string const typeOfAnimal = "Giraffe") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}

	void makeSound() override;

};