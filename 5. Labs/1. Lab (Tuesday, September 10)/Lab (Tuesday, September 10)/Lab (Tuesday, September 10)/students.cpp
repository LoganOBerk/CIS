#include "students.h"

void Student::passByRefrence(string& major, int& hours) {}

string Student::printMe() {
	string sentance = "I'm a " + major + " major and have completed " + to_string(hours) + " credit hours.";
	return sentance;
}

string Student::validateFileName() {
	string fileName;
	while (!(cin >> fileName)) {
		cout << "Please enter a valid file name! "; 
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return fileName;
}

Student::~Student() {
	cout << "\nDestructor called for " << major << " major.\n" << endl;
}