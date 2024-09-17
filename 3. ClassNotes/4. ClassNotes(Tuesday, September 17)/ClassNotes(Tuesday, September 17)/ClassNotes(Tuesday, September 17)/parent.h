#pragma once
#include <string>

using namespace std;

class GenStudent {
private:
	string name;
	string ID;
public:
	void SetAll(string nm, string id);
	void PrintAll();
};