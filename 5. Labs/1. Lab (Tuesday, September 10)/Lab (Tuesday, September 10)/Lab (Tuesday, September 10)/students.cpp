#include "students.h"
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
void Student::saveStudentData(vector<Student>& studentClass, string& fileName, const int& loadTime) {								//
	ofstream file(fileName + ".txt");																								//
	if (!file) {																													//
		cout << "Unable to open file!" << endl;																						//
	}																																//
	else {																															//
		for (int i = 0; i < 3; i++) {																								//
			file << studentClass[i].printMe() << endl;																				//
		}																															//
		cout << "Saving student data..." << endl;																					//
		this_thread::sleep_for(chrono::seconds(loadTime));																			//
		cout << endl;																												//
	}																																//
	file.close(); //Question e																										//
}																																	//
																																	//
void Student::readStudentData(string& fileName, const int& loadTime) {																//
	ifstream file(fileName + ".txt");																								//
	if (!file) {																													//
		cout << "Unable to read file!" << endl;																						//
	}else																															//																																//
	cout << "Reading File..." << endl;																								//
	string line;																													//
	while (getline(file, line)) {																									//
		cout << line << endl;																										//
		this_thread::sleep_for(chrono::seconds(loadTime));																			//
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
	this_thread::sleep_for(chrono::seconds(1));									//
	cout << "\nDestructor called for " << major << " major.\n" << endl;			//
}