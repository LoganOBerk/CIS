#include <iostream>
#include "vector.h"

using namespace std;

double sqrt(double x) {
	return x;
}
int main()
{

	cout << sqrt(9) << endl;
	// REQUIRED CODE – will need some modification to be template compatible.
	Vector a, b(4), c(3);
	a.print(); // outputs {}
	b.print(); // outputs { 0 0 0 0 }
	c.set(0, -1); // output error message
	c.set(2, 1);
	c.set(4, 3); // outputs error message
	c.set(1, 0);
	c.set(3, 2);
	c.print(); // outputs { 1 2 3 }
	Vector d(c);
	d.print(); // outputs { 1 2 3 }
	d.set(0, 1);
	d.print(); // outputs { 1 0 3 }
	c.print(); // outputs { 1 2 3 } proves deep copy
	// ADDITIONAL TEST CASES
	//[Insert code for YOUR test cases here]
		return 0;
}
