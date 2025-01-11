#pragma once
#include "Animal.h"

class Owl : public Animal {
public:
	Owl(double const weight = 15.0, int const feetNumber = 2, string const typeOfAnimal = "Owl") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}

	void makeSound() override;

};