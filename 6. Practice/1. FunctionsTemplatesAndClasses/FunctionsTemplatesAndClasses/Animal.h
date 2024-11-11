#pragma once
#include "hybrid.h"


#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>


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
	virtual void makeSound() {};
	void printWeight();

	string getTypeOfAnimal() const { return this->typeOfAnimal; }
	double getWeight() const{ return this->weight; }
	void setWeight(double& weight) { this->weight = weight; }

	int getFeetNumber() const{ return this->feetNumber; }
	void setFeetNumber(int& feetNumber) { this->feetNumber = feetNumber; }
	

	Animal* operator+(Animal& other) {
		this->feetNumber += other.feetNumber;
		this->weight = (this->weight + other.weight)/2 ;
		int SIZE;
		int TOTALSIZE = static_cast<int>(typeOfAnimal.size());
		if (TOTALSIZE % 2 == 0) {
			SIZE = TOTALSIZE / 2;
		}
		else {
			SIZE = (TOTALSIZE - 1) / 2;
		}
		string WORD1;
		for (int i = 0; i < SIZE; i++) {
			WORD1 += typeOfAnimal[i];
		}
		TOTALSIZE = static_cast<int>(other.typeOfAnimal.size());
		if (TOTALSIZE % 2 == 0) {
			SIZE = TOTALSIZE / 2;
		}
		else {
			SIZE = (TOTALSIZE - 1) / 2;
		}
		string WORD2;
		for (int i = SIZE; i < TOTALSIZE; i++) {
			WORD2 += other.typeOfAnimal[i];
		}
		this->typeOfAnimal = WORD1 + WORD2;

		return new Animal(weight, feetNumber, typeOfAnimal);
	}
};