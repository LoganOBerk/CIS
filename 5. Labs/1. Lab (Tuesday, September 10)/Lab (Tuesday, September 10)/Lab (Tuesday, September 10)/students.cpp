#include "students.h"
#include <iostream>
void Student::passByRefrence(const string& major, const int& hours){} //Question b(iii)

string Student::printMe() {																							//Question b(v)
	string sentance = "I'm a " + major + " major and have completed " + to_string(hours) + " credit hours.";		//
	return sentance;																								//
}

string Student::validateStringInput() {																								//Question f 
	string input;																													//Extra Input validation
	while (!(cin >> input)) {																										//and file logic
		cin.clear();																												//
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');																	//
		cout << "Please enter a valid input : ";																					//
	}																																//
	return input;																													//
}																																	//
																																	//
void Student::saveStudentData(vector<Student>& studentClass, string& fileName) {													//
	ofstream file(fileName + ".txt");																								//
	if (!file) {																													//
		cout << "Unable to open file!" << endl;																						//
	}																																//
	for (int i = 0; i < 3; i++) {																									//
		file << studentClass[i].printMe() << endl;																					//
	}																																//
	file.close(); //Question e																										//
}																																	//
																																	//
void Student::readStudentData(string& fileName) {																					//
	ifstream file(fileName + ".txt");																								//
	if (!file) {																													//
		cout << "Unable to read file!" << endl;																						//
	}																																//
																																	//
	string line;																													//
	while (getline(file, line)) {																									//
		cout << line << endl;																										//
	}																																//
	file.close();																													//
																																	//
}																																	//
																																	//
																																	// 
int Student::validateIntInput() {																									//
	int input;																														//
	while (!(cin >> input) || input <= 0) {																							//
		cin.clear();																												//
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');																	//
		cout << "Please enter a list of valid inputs (any integer greater than 0) seperated by spaces continuing from mistake: ";	//
	}																																//
	return input;																													//
}

Student::~Student() {															//Question b(vi)
	cout << "\nDestructor called for " << major << " major.\n" << endl;			//
}