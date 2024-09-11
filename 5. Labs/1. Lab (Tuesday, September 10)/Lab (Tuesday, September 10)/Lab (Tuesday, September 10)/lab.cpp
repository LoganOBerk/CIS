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
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test Constructor Initialization                                        " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	Student student("CSC AI ");          //Question a
	cout << student.printMe() << endl;  //Question b
	cout << endl;


	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test fileName Input		                                            " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	string fileName;
	cout << "Please enter a filename for output write: ";											//Question c
	cin >> fileName;																				//
	cout << "Your student data file will be named " + fileName + ".txt" << endl;								//
	cin.ignore(numeric_limits<streamsize>::max(), '\n');											//
	cout << endl;


	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test Major Input                                                       " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	vector<Student> studentClass; //Question d 
	studentClass.reserve(3);      //
	string major;
	cout << "Please enter 3 majors seperated by spaces(any extra will be discarded) ";						//Question d(vii)
	for (int i = 0; i < 3; i++) {																			//
		major = student.validateStringInput();																//
		studentClass.emplace_back(major);																	//
	}																										//
	cin.ignore(numeric_limits<streamsize>::max(), '\n');													//
	cout << "The majors you entered were : " + studentClass[0].getMajor() +									//
		", " + studentClass[1].getMajor() + ", " + studentClass[2].getMajor() << endl;						//																					
	cout << endl;																							//
																											//
																											//
	cout << "-----------------------------------------------------------------------" << endl;				//
	cout << "Test Credit Hours Input                                                " << endl;				//	
	cout << "-----------------------------------------------------------------------" << endl;				//
	int hours;																								//
	cout << "Please enter 3 credit hours seperated by spaces (any extra will be discarded)";				//
	for (auto& studentInfo : studentClass) {																//
		hours = student.validateIntInput();																	//
		studentInfo.setValues(studentInfo.getMajor(), hours);												//
	}																										//
	cout << "The credit hours you entered were : " + to_string(studentClass[0].getHours()) +				//
		", " + to_string(studentClass[1].getHours()) + ", " + to_string(studentClass[2].getHours()) << endl;//
	cout << endl;																							//																			
	

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test File Writing                                                      " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	student.saveStudentData(studentClass, fileName, 2);  //Question(viii)
	student.readStudentData(fileName, 1);				  //Outputing file data
	cout << endl;

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Calling Destructors                                                    " << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	return 0;
}