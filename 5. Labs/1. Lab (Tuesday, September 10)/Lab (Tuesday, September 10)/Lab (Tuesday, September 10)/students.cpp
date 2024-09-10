#include "students.h"

void Student::passByRefrence(string& major, int& hours) {

};
string Student::printMe() {
	string sentance = "I'm a " + major + " major and have completed " + to_string(hours) + " credit hours.";
	return sentance;
}

Student::~Student() {
	cout << "\nDestructor called for " << major << " major.\n" << endl;
}