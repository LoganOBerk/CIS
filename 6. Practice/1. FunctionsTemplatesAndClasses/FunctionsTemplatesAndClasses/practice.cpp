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
			cout << "Please enter a valid animal name ";
			cout << "(";
			for (int i = 0; i < names.size(); i++) {
				cout << names[i];
				if (i < names.size() - 1) {
					cout << ", ";
				}
			}
			cout << ")";
			cout << ": ";
		}
	}
	return input;
}

int main() {
	vector<string> names = { "dog", "cat", "cow", "giraffe", "owl", "skunk"};
	

	cout << "Would you like to make a hybrid?" << endl;
	cout << "Enter first animal: ";
	string animal1;
		animal1 = getCorrectUserInput(animal1, names);
	cout << "Enter second animal: ";
	string animal2;
		animal2 = getCorrectUserInput(animal2, names);
	
	map<string, Animal*> animal;
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == animal1 || names[i] == animal2) {
			if (names[0] == names[i]) animal[names[0]] = new Dog;
			if (names[1] == names[i]) animal[names[1]] = new Cat;
			if (names[2] == names[i]) animal[names[2]] = new Cow;
			if (names[3] == names[i]) animal[names[3]] = new Giraffe;
			if (names[4] == names[i]) animal[names[4]] = new Owl;
			if (names[5] == names[i]) animal[names[5]] = new Skunk;
		}
	}
	
		
	Animal* hybrid = *animal[animal1] + *animal[animal2];
	
	hybrid->makeSound();
	hybrid->printWeight();

	delete hybrid;
	delete animal[animal1];
	delete animal[animal2];
	return 0;
}