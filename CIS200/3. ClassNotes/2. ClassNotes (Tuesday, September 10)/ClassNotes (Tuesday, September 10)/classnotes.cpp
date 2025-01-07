#include <iostream>
#include <string>

using namespace std;

//when including files we can do #include "filename.h"(.hpp is same as .h) or "filename.cpp"
//in your .h file you need to write #pragma once 
// Old way is #ifndef FILENAME_H (makes sure you have no duplicate includes)
//            #define FILENAME_H
//            body of code
//at the end  #endif

//Four principles of OOP
	//Encapsulation
	//	binding together data and the functions that manipulate them
	//Inheritance
	//	an entity can inherit attributes from another entity. It allows the programmer to create similar entities
	// without needing to redefine similar attributes over and over
	//Polymorphism
	//	means having many forms. Previously seen with overloaded functions
	//Abstraction
	//	the process of hiding all but the relevant information about a thing to make things less complex
	// and more efficient for the user. For example, we dont need to know how a clock works in order to use it
	// to tell time.  Abstraction lets you focus on what the thing does instead of how it does it.

	//Objects 
	// Represents a noun
	// Groups data(variables, called attributes) and operations to be performed on that data
	// is called a function or method

	//Terminology
	// Class: blueprint
	// Object: a house built from blueprint
	// Instance: a specific house

	// int, float, string, etc.. are finite data types
	// enum, struct, class etc.. are abstract data types

	//ADT is a means of working with high level items while hiding low-level details from user(programmer)

//creating a class
//struct will work the same as a class but it should be only done when public and doesnt require additional functions just attributes

class student {

	//intitialization and prototypes typically in .h file
	//include standard includes here
	//can also use namespace here depending on what you want 
private:
	string name;
	float GPA[10];
	int stuNum;

public:
	static int stuCnt; //static variable - member of class, not an instance a change effects for all stuCnt
	int setCnt() { stuNum = ++stuCnt; }
	int func(const int& x) { return x; }
	void setName(const string) {};
	void setGPA(float, int);
	void setGPA(float[], int);
	string getName() const {};
	float getGPA() const;


};

//functions and what they do typically in .cpp file
//include examplefile.h here 
float student::getGPA() const { return GPA[0]; }
void student::setGPA(float g[], int cnt) {
	int i;
	for (i = 0; i < cnt; i++) {
		GPA[i] = g[i];
	}
}
void student::setGPA(float g, const int pos) {
	GPA[pos] = g;
}

int func(const int& x) {
	//if you want to modify x in the body then it cannot be const
	return x;
}

//student.cpp file
//#include "student.h"
//class will be in "student.h"
//inline means save this variable for last to swap out of memory makes it faster less memory swapping
//when teacher refering to inline hes saying the method needs to be in class definition(.cpp file)
//method has one or two statements defined inline with declaration any more is not longer inline and should be moved to .h
//definitons(the meat of the function) typically go in cpp file
//
//const after parenthesis tells compiler body of method cannot modify class 

// :: is class specifier, float student::getGPA const{ return GPA; } aka what class are you getting this function from class specifiers should be in .cpp;
//.h file has your prototypes variables and .cpp is executible code and then source executes


//Namespaces, primarily used when programming in groups.  It adds another higher level of seperation.
//Example:
	//Programmer A creates class box
	//Programmer B creates class box
	//Programmer C needs to use both classes
	// ex:  box myBox;  //which programmers class does it refer to, A or B?

//Examples of how to create namespaces
namespace ProgA {
	class box {
	private:
		int height;
		int width;
		string color;
		double weight;
	public:
		int getHeight() {
			return this->height;
		}
		int getWidth() {
			return this->width;
		}
		void setWidth(int width) {
			this->width = width;
		}
		void setHeight(int height) {
			this->height = height;
		}
		string getColor() {
			return this->color;
		}
		void setColor(string color) {
			this->color = color;
		}
		double getWeight() {
			return this->weight;
		}
		void setWeight(double weight) {
			this->weight = weight;
		}
	};
}
namespace ProgB {
	class box {
	private:
		int height;
		int width;
		string color;

	public:
		int getHeight() {
			return this->height;
		}
		int getWidth() {
			return this->width;
		}
		void setWidth(int width) {
			this->width = width;
		}
		void setHeight(int height) {
			this->height = height;
		}
		string getColor() {
			return this->color;
		}
		void setColor(string color) {
			this->color = color;
		}
	};
}

using namespace ProgA;
using namespace ProgB;

int main() {


	//how to run the namespaces
	ProgB::box newBox;
	newBox.setColor("Orange");
	ProgA::box newBox1;
	newBox1.setWeight(500.5);

	cout << newBox.getColor() << endl;
	cout << newBox1.getWeight() << endl;
	
	float grades[10], grade{0};
	student myStudent;
	myStudent.setGPA(grades, 10);
	myStudent.setGPA(3.14f, 4);

	student myStudents[50];

	//an array of students
	int x = 0;
	myStudents[x].setName("Abe");







	return 0;
}