#pragma once

#include <iostream>
#include <fstream>
#include <random>

using namespace std;


struct Node {
	int data;
	Node* prev;
	Node* next;
	Node* prevEvenOdd;
	Node* nextEvenOdd;

	Node() : data(-1), prev(nullptr), next(nullptr), prevEvenOdd(nullptr), nextEvenOdd(nullptr){}
};
void initFile(fstream&, int*, int);
void printFileContents(fstream&);
void fileValidation(fstream&);
void logError(fstream&);
void printList(char&);
void addInt(int&);
void deleteInt(int&);
