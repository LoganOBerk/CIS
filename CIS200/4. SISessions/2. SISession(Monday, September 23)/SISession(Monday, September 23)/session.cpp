#include <iostream>

using namespace std;

class Square;

class Rectangle {
	int width, height;
public:
	int area() { return (width * height); }
	void convert(Square a);
	//friend class Square;
};
class Square {
	friend class Rectangle;
private:
	int side;
public:
	Square(int a) : side(a) {}
};

void Rectangle::convert(Square a) {
	width = a.side;
	height = a.side;
}




class Base {
public:
	virtual void print() { cout << "Print base\n"; }

	void show() { cout << "Show base"; }

};


class Derived : public Base {
public:
	void print() { cout << "Derived"; }
	void show() { cout << "show derived"; }
};
int main() {

	Base* bptr;
	Derived d;
	bptr = &d;


	Rectangle rect;
	Square sqr(4);
	rect.convert(sqr);
	cout << rect.area();


	return 0;
};