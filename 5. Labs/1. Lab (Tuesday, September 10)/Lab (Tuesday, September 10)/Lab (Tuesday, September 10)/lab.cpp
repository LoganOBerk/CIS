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

int main() {
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test Constructor Initialization                                        " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	Student student("CSC AI "); //Question a    
	cout << student.printMe() << endl; //Question b 
	cout << endl;


	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test fileName Input		                                            " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	string fileName;
	cout << "Please enter a filename you would like to use(if multiple words use a \"_\" to seperate them): "; //Question c											
	cin >> fileName;
	cout << "Your student data file will be named " + fileName + ".txt" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;


	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test Major Input                                                       " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	vector<Student> studentClass; //Question d 
	studentClass.reserve(3);
	string major;
		cout << "Please enter 3 majors seperated by spaces or commas(any extra will be discarded, if multiple words use a \"_\" to seperate them): "; //Question d(vii)
		for (int i = 0; i < 3; i++) {
			major = student.validateStringInput();
			studentClass.emplace_back(major);
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "The majors you entered were : " + studentClass[0].getMajor() +
			", " + studentClass[1].getMajor() + ", " + studentClass[2].getMajor() << endl;
		cout << endl;
																											
																											
	cout << "-----------------------------------------------------------------------" << endl;				
	cout << "Test Credit Hours Input                                                " << endl;					
	cout << "-----------------------------------------------------------------------" << endl;				
	int hours;																								
	cout << "Please enter 3 credit hours seperated by spaces or commas(any extra will be discarded, decimals will be rounded): "; //Question d				
	for (auto& studentInfo : studentClass) {
		hours = student.validateIntInput();
		cin.ignore();
		studentInfo.setValues(studentInfo.getMajor(), hours);												
	}																										
	cout << "The credit hours you entered were : " + to_string(studentClass[0].getHours()) +				
		", " + to_string(studentClass[1].getHours()) + ", " + to_string(studentClass[2].getHours()) << endl;
	cout << endl;																																										
	

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test File Writing                                                      " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	student.saveStudentData(studentClass, fileName, 2);  //Question(viii)
	student.readStudentData(fileName, 1);				  //Outputing file data
	cout << endl;


	Student testStudent("SomeValue", 0);
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Test Extra func (pass by refrence getter)                              " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	string x;
	int y;
	cout << "Our input values are some \"x\" and some \"y\"." << endl;
	testStudent.getterPassByRefrence(x, y);

	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Calling Destructors                                                    " << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	return 0;
}