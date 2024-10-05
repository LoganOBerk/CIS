#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"
#include "Giraffe.h"
#include "Skunk.h"
#include "Owl.h"

string toLower(const string& input) {
	string output = input;
	transform(output.begin(), output.end(), output.begin(), [](unsigned char c) {
		return tolower(c);
		});
	return output;
}

string getCorrectUserInput(string& input, vector<string>& names) {
	bool notValid = true;
	while (notValid) {
		getline(cin, input);
		input = toLower(input);
		for (auto compare : names) {
			if (input == compare) {
				notValid = false;
				break;
			}
		}
		if (notValid) {
			cout << "Please enter a valid animal name: ";
		}
	}
	return input;
}

int main() {
	vector<string> names = { "dog", "cat", "cow", "giraffe", "owl", "skunk"};
	Animal* dog = new Dog;
	Animal* cat = new Cat;
	Animal* cow = new Cow;
	Animal* giraffe = new Giraffe;
	Animal* owl = new Owl;
	Animal* skunk = new Skunk;

	dog->makeSound();
	dog->printWeight();
	cat->makeSound();
	cat->printWeight();
	cow->makeSound();
	cow->printWeight();
	giraffe->makeSound();
	giraffe->printWeight();
	
	
	cout << "Would you like to make a hybrid?" << endl;
	cout << "Enter first animal: ";
	string animal1;
		animal1 = getCorrectUserInput(animal1, names);
	cout << "Enter second animal: ";
	string animal2;
		animal2 = getCorrectUserInput(animal2, names);
	
	
	map<string, Animal*> animal;
	Animal* hybrid;
	animal[names[0]] = dog;
	animal[names[1]] = cat;
	animal[names[2]] = cow;
	animal[names[3]] = giraffe;
	animal[names[4]] = owl;
	animal[names[5]] = skunk;

	
	hybrid = *animal[animal1] + *animal[animal2];
	
	hybrid->makeSound();
	hybrid->printWeight();

	delete hybrid;
	delete cow;
	delete cat;
	delete dog;
	delete giraffe;

	return 0;
}