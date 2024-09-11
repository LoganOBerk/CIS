#pragma once
#include<string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Student {

	string major;
	int hours;


public:
	Student(const string major = "Undeclaired", const int hours = -19) {
		this->major = major;
		this->hours = hours;
	
	}

	string getMajor() { return major; }
	int getHours() { return hours; }
	void passByRefrence(const string&, const int&);
	void setValues(const string& major, const int& hours) { this->major = major; this->hours = hours; }
	string printMe();
	string validateStringInput();
	int validateIntInput();
	void readStudentData(string&);
	void saveStudentData(vector<Student>&, string&);
	~Student();




};