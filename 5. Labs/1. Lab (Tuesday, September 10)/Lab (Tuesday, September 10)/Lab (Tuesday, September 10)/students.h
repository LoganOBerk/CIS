#ifndef STUDENTS_H
#define STUDENTS_H
#include<string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;


class Student {		//Question a
					//
	string major;	//
	int hours;		//


public:

	Student(const string major = "Undeclaired", const int hours = -19) {		//Question b(i)
		this->major = major;													//
		this->hours = hours;													//
	
	}

	string getMajor() { return major; } //Question b(ii)
	int getHours() { return hours; }   //Question b(ii)
	void passByRefrence(const string&, const int&); //Question b(iii)
	void setValues(const string& major, const int& hours) { this->major = major; this->hours = hours; } //Question b(iv)
	string printMe();  //Question b(v)
	~Student(); //Question b(vi)

	
	string validateStringInput();						//Extra Input validation and function logic, Question f
	int validateIntInput();								//
	void readStudentData(string&);						//
	void saveStudentData(vector<Student>&, string&);	//
	





};

#endif STUDENTS_H