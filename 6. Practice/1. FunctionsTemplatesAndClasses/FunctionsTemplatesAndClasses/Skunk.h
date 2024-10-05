#pragma once
#include "Animal.h"

class Skunk : public Animal {
public:
	Skunk(double const weight = 939.0, int const feetNumber = 4, string const typeOfAnimal = "Skunk") {
		this->weight = weight;
		this->feetNumber = feetNumber;
		this->typeOfAnimal = typeOfAnimal;
	}

	void makeSound() override;

};