#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main() {

	Animal* dog = new Dog;
	Animal* cat = new Cat;
	/*
	Animal* cow = new Cow;
	*/
	dog->makeSound();
	dog->printWeight();
	cat->makeSound();
	cat->printWeight();
	/*
	cat->makeSound();
	cow->makeSound();
	*/


	return 0;
}