/*********************
* Programmer Name :
* 
* Purpose : 
* 
* Create Date :
* 
* Modified Date :
* ********************/

#include <iostream>

using namespace std;

int main() {

	/*
	int x[] = { 3, 7, 11, 17, 23 };
	int *xPtr = &x[2];
	cout << "Array content prior to pointer manipulation\n";
	//cout << x[1] << ' ' << x[2] << x[3] << ' ' << xPtr << " : " << *xPtr << endl;
	//cout << *xPtr-- << endl;   //gives 11 from derefrenced pointer the decrement doesnt occur
	//cout << (*xPtr)-- << endl; //gives 11 from derefrenced pointer the decrement doesnt occur
	//cout << *(xPtr)-- << endl; //gives 11 from derefrenced pointer the decrement doesnt occur
	//cout << *(xPtr--) << endl; //gives 11 from derefrenced pointer the decrement doesnt occur
	//cout << *(--xPtr) << endl; //gives 7  from derefrenced memory address which was moved to the left by 1
	//cout << *--xPtr << endl;   //gives 7  from derefrenced memory address which was moved to the left by 1
	//cout << (*--)xPtr << endl; //nothing cant derefrence an opperation

	cout << endl << "Array content after ptr manipulation" << endl;
	cout << x[1] << ' ' << x[2] << ' ' << x[3] << ' ' << xPtr << " : " << endl;
	*/

	class B {
	private:
		int x;

	protected:
		float y;

	public:
		B() {
			int x = 0;
			float y = 0.0;
		}

		B(int a, float b) {
			int x = a;
			float y = b;
		}

		B(const B& w) {
			this->x = w.x;
			this->y = w.y;
		}

		B operator = (B& c) {
			this->x = c.x;
			this->y = c.y;
			return *this;
		};

		int getInt() {
			return x;
		}
		float getFloat() {
			return y;
		}
	};

	return 0;

};