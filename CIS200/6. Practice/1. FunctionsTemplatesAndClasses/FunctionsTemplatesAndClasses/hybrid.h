#pragma once
#include "Animal.h"
/*
class Hybrid : public Animal {
public:
	Hybrid(const Animal& animal1, const Animal& animal2) {
		this->feetNumber = animal1.getFeetNumber() + animal2.getFeetNumber();
		this->weight = (animal1.getWeight() + animal2.getWeight()) / 2;
		this->typeOfAnimal = hybridizeType(animal1.getTypeOfAnimal(), animal2.getTypeOfAnimal());
	}
	
	string hybridizeType(const string& type1, const string& type2) {
		int SIZE;
		int TOTALSIZE = static_cast<int>(type1.size());
		if (TOTALSIZE % 2 == 0) {
			SIZE = TOTALSIZE / 2;
		}
		else {
			SIZE = (TOTALSIZE - 1) / 2;
		}
		string WORD1;
		for (int i = 0; i < SIZE; i++) {
			WORD1 += type1[i];
		}
		TOTALSIZE = static_cast<int>(type2.size());
		if (TOTALSIZE % 2 == 0) {
			SIZE = TOTALSIZE / 2;
		}
		else {
			SIZE = (TOTALSIZE - 1) / 2;
		}
		string WORD2;
		for (int i = SIZE; i < TOTALSIZE; i++) {
			WORD2 += type2[i];
		}

		string type3 = WORD1 + WORD2;
		return type3;
	}

	Animal* operator+(const Animal& other) const override {
		return new Hybrid(*this, other);
	}
	void makeSound() override;
	
};
*/
