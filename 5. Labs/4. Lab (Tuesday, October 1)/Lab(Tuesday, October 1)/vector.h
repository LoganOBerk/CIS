

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <iomanip>
#include <type_traits>

using namespace std;

template <class T>
class Vector{
private:
	int size; 
	T* entries; 
public:
	Vector<T>() {} // default constructor
	Vector<T>(T s) {
		this->size = s;
		this->entries = new T[size];
		for (int i = 0; i < size; i++) {
			entries[i] = 0;
		}
	} 
	Vector<T>(const Vector& other) {
		this->entries = new T[other.size];
		this->size = other.size;
		for (int i = 0; i < size; i++) {
			this->entries[i] = other.entries[i];
		}
		
	}
	~Vector<T>() {
		delete[] entries;
	} 

	void print() {
		cout << "{";
		for (int i = 0; i < size; i++) {
			if (size == 0) {
				cout << " ";
			}
			if (is_same<T, double>::value) {
				cout << setprecision(15) << entries[i];
			}
			else {
				cout << entries[i];
			}
				cout << " ";
		}
		cout << "}" << endl;

		cout.unsetf(ios::floatfield);
		cout.precision(6);
	} 
	void set(T val, int pos) {
		if (pos >= 0 && pos < size) {
				entries[pos] = val;
		}
		else {
				cout << "Index out of bounds" << endl;
		}

	} 

};
#endif