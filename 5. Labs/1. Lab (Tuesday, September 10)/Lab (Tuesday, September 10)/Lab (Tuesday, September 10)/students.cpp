#include "students.h"
void Student::getterPassByRefrence(string& major, int& hours) const{
	major = this->major;
	hours = this->hours;
	cout << "You just got student class values " + major + ", " + to_string(hours) + " by refrence!" << endl;
} //Question b(iii)

string Student::printMe() {																							//Question b(v)
	string sentance = "I'm a " + major + " major and have completed " + to_string(hours) + " credit hours.";		//
	return sentance;																								//
}

string Student::validateStringInput() { //Question f																								 
	string input;
	while (true) {
		cin >> input;
		if (!input.empty() && input.back() == ',') {
			input.pop_back();
		}
		if (input == ",") {

		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid input : ";
		}else{ 
			break; 
		}
	}
	return input;																													
}																																	
																																
void Student::saveStudentData(vector<Student>& studentClass, string& fileName, const int& loadTime) { //Question f								
	ofstream file(fileName + ".txt");																							
	if (!file) {																													
		cout << "Unable to open file!" << endl;																						
	}																																
	else {																															
		for (int i = 0; i < 3; i++) {																								
			file << studentClass[i].printMe() << endl;																				
		}																															
		cout << "Saving student data..." << endl;																					
		this_thread::sleep_for(chrono::seconds(loadTime));																			
		cout << endl;																												
	}																																
	file.close(); //Question e																										
}																																	
																																	
void Student::readStudentData(string& fileName, const int& loadTime) { //Question f														
	ifstream file(fileName + ".txt");																								
	if (!file) {																													
		cout << "Unable to read file!" << endl;																						
	}else																																																														//
	cout << "Reading File..." << endl;																								
	string line;																													
	while (getline(file, line)) {																									
		cout << line << endl;																										
		this_thread::sleep_for(chrono::seconds(loadTime));																			
	}																																
	file.close();																													
																																	
}																																	
																																	
																																
int Student::validateIntInput() { //Question f																									
	float input;			
	cin >> input;
	int roundedInput = static_cast<int>(round(input));
	while (cin.fail() || roundedInput <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "Please enter a list of valid inputs (any integer greater than 0) seperated by spaces continuing from mistake: ";
	}																																
	return roundedInput;																													
}

Student::~Student() { //Question b(vi)
	this_thread::sleep_for(chrono::seconds(1));								
	cout << "\nDestructor called for " << major << " major.\n" << endl;		
}