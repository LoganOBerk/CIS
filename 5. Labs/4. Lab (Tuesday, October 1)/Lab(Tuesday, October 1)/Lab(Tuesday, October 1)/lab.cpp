#include <iostream>
#include "vector.h"
#include <cassert>

using namespace std;

int main(){
	bool testingInt = true;
	bool testingFloat = true;
	bool testingDouble = true;
	// REQUIRED CODE – will need some modification to be template compatible.

	if (testingInt) {
		cout << "TESTING INT" << endl;
		cout << "-------------------------------------------------------------" << endl;
		Vector<int> a, b(4), c(3);
		a.print(); // outputs {}
		b.print(); // outputs { 0 0 0 0 }
		c.set(0, -1); // output error message

		c.set(1, 0);
		c.set(2, 1);
		c.set(3, 2);
		c.set(4, 3); // outputs error message

		c.print(); // outputs { 1 2 3 }
		Vector<int> d(c);
		d.print(); // outputs { 1 2 3 }
		d.set(0, 1);
		d.print(); // outputs { 1 0 3 }
		c.print(); // outputs { 1 2 3 } proves deep copy
		cout << "-------------------------------------------------------------" << endl;
	}

	// ADDITIONAL TEST CASES
	//DOUBLE
	if (testingDouble) {
		cout << "TESTING DOUBLE" << endl;
		cout << "-------------------------------------------------------------" << endl;
		Vector<double> d, e(4), f(3);
		d.print(); // outputs {}
		e.print(); // outputs { 0 0 0 0 }
		f.set(0, -1); // output error message

		f.set(1.123456789, 0);
		f.set(2.123456789, 1);
		f.set(3.123456789, 2);
		f.set(4.123456789, 3); // outputs error message

		f.print(); // outputs { 1.123456789 2.123456789 3.123456789 }
		Vector<double> g(f);
		g.print(); // outputs { 1.123456789 2.123456789 3.123456789 }
		g.set(0, 1);
		g.print(); // outputs { 1.123456789 0 3.123456789 }
		f.print(); // outputs { 1.123456789 2.123456789 3.123456789 } proves deep copy
		cout << "-------------------------------------------------------------" << endl;
	}

	//FLOAT
	if (testingFloat) {
		cout << "TESTING FLOAT" << endl;
		cout << "-------------------------------------------------------------" << endl;
		Vector<float> h, i(4), j(3);
		h.print(); // outputs {}
		i.print(); // outputs { 0 0 0 0 }
		j.set(0, -1); // output error message

		j.set(1.123456f, 0);
		j.set(2.123456f, 1);
		j.set(3.123456f, 2);
		j.set(4.123456f, 3); // outputs error message

		j.print(); // outputs { 1.123456 2.123456 3.123456 }
		Vector<float> k(j);
		k.print(); // outputs { 1.123456 2.123456 3.123456 }
		k.set(0, 1);
		k.print(); // outputs { 1.123456 0 3.123456 }
		j.print(); // outputs { 1.123456 2 3.123456 } proves deep copy
		cout << "-------------------------------------------------------------" << endl;
	}

		return 0;
}
