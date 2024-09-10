#pragma once
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;
class Student {

	string major;
	int hours;


public:
	Student(string major = "Undeclaired", int hours = -19) {
		this->major = major;
		this->hours = hours;
	
	}

	string getMajor() { return major; }
	int getHours() { return hours; }
	void passByRefrence(string&, int&);
	void setValues(string& major, int& hours) { this->major = major; this->hours = hours; }
	string printMe();
	string validateFileName();
	~Student();




};