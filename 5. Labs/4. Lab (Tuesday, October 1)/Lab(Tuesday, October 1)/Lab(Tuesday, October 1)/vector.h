#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;

class Vector{
private:
	int size; 
	int* entries; 
public:
	Vector() {} // default constructor
	Vector(int s) {
		this->size = s;
		this->entries = new int[size];
		for (int i = 0; i < size; i++) {
			entries[i] = 0;
		}
	} 
	Vector(const Vector& other) {
		this->entries = new int[other.size];
		this->size = other.size;
		for (int i = 0; i < size; i++) {
			this->entries[i] = other.entries[i];
		}
		
	}
	~Vector() {
		delete[] entries;
	} 

	void print() {
		cout << "{";
		for (int i = 0; i < size; i++) {
			if (size == 0) {
				cout << " ";
			}
				cout << entries[i];
				cout << " ";
		}
		cout << "}" << endl;
	} 
	void set(int val, int pos) {
		if (pos >= 0 && pos < size) {
				entries[pos] = val;
		}
		else {
				cout << "ERROR Invalid Position!" << endl;
		}

	} 

};
#endif