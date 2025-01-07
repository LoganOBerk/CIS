#pragma once
#include <string>

using namespace std;

//inherited class
class GraduatedStudnt : public GenStudent { //can have multiple parents public GenStudent, public Person. Searches starting left to right to find the function
private:
	string degree;
	float GPA;
	string gradDate;
public:
	void printAll();

	//has to access parent constructor first
	//only want to do constructor inheritance with multiple constructors
	GraduatedStudnt() : GenStudent() {

	}

	void setDegree(string);
	void setGPA(float);
	void setGradDate(string);
	void displayInfo();
};