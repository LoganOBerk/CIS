/************************
* Programer Name: Logan Berk
*
* Purpose: To collect store and display data related to students.
*
* Create Date: 9/10/2024
*
* Modified Date: 9/11/2024
*************************/



#include "students.h"
#include <iostream>

int main() {
	Student student("CSC AI ");
	cout << student.printMe() << endl;

	string fileName;
	cout << "Please enter a filename for output write: ";
	cin >> fileName; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "-----------------------------------------------------------------------" << endl;
	
	vector<Student> studentClass;
	studentClass.reserve(3);
	string major;
	cout << "Please enter 3 majors seperated by spaces(any extra will be discarded) ";
	for (int i = 0; i < 3; i++) {
		major = student.validateStringInput();
		studentClass.emplace_back(major);
	}
	
	

	int hours;
	cout << "Please enter 3 credit hours seperated by spaces (any extra will be discarded)";
	for (auto &studentInfo : studentClass ) {
		hours = student.validateIntInput();
		studentInfo.setValues(studentInfo.getMajor(), hours);
	}

	cout << "---------------------------------------------------------" << endl;

	student.saveStudentData(studentClass, fileName);
	student.readStudentData(fileName);
	

	return 0;
}