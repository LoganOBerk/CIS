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
	Student student("CSC AI ");          //Question a
	cout << student.printMe() << endl;  //Question b

	string fileName;
	cout << "Please enter a filename for output write: ";											//Question c
	cin >> fileName;																				//
	cin.ignore(numeric_limits<streamsize>::max(), '\n');											//
	cout << "-----------------------------------------------------------------------" << endl;		//
	
	vector<Student> studentClass; //Question d 
	studentClass.reserve(3);      //
	string major;
	cout << "Please enter 3 majors seperated by spaces(any extra will be discarded) ";					//Question d(vii)
	for (int i = 0; i < 3; i++) {																		//
		major = student.validateStringInput();															//
		studentClass.emplace_back(major);																//
	}																									//
	cin.ignore(numeric_limits<streamsize>::max(), '\n');												//
																										//
																										//
	int hours;																							//
	cout << "Please enter 3 credit hours seperated by spaces (any extra will be discarded)";			//
	for (auto &studentInfo : studentClass ) {															//
		hours = student.validateIntInput();																//
		studentInfo.setValues(studentInfo.getMajor(), hours);											//
	}																									//
																										//
	cout << "---------------------------------------------------------" << endl;

	student.saveStudentData(studentClass, fileName);  //Question(viii)
	student.readStudentData(fileName);				  //Outputing file data


	return 0;
}