#include <iostream>
#include <string>

using namespace std;
class Student {
	string name;
	float GPA;
public:
	Student operator+(Student);// overloading operator, allowing you to create an operation for comparing two classes, no need to overload assignment operator
							  //in this case we are overloading the plus operator
	Student(string nm = "no name", float gpa = -0.01f) : name(nm), GPA(gpa){}
	static int num;
	static int studentNum(){ return num++; }//static mehthods can only access static variables static methods for classes effect all variables
	~Student(); //prototype

	Student(string = "no name", float = -0.01f);

};
int main() {
	// static variable is a global variable for its respective class
	//destructors have no return type

	/*
	Student aStdnt, bStdnt;
		bStudnt = bStdnt.operator+(aStdnt);
		*/
		return 0;
}