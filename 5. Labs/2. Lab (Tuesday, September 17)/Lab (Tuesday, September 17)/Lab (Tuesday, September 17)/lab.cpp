#include "firstclass.h"
#include "secondclass.h"
#include "thirdclass.h"

void test(ThirdClass& obj) {
	ThirdClass third;
	third.printMe();
	obj.printMe();
	cout << "================================================================================" << endl;
	cout << "Object goes out of scope therefore calls destructors" << endl;
	cout << "================================================================================" << endl;
}

int main() {
	cout << "================================================================================" << endl;
	cout << "Creating a FirstClass Object with no initialization values" << endl;
	cout << "================================================================================" << endl;
	FirstClass first;
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a SecondClass Object with no initialization values" << endl;
	cout << "================================================================================" << endl;
	SecondClass second;
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a ThirdClass Object with no initialization values" << endl;
	cout << "================================================================================" << endl;
	ThirdClass third;
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a FirstClass Object with initialization values" << endl;
	cout << "================================================================================" << endl;
	FirstClass firstC("Yellow", 5);
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a SecondClass Object with initialization values" << endl;
	cout << "================================================================================" << endl;
	SecondClass secondC(4, 3);
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a ThirdClass Object with initialization values" << endl;
	cout << "================================================================================" << endl;
	ThirdClass thirdC(8);
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a ThirdClass Object(thing1) with no initialization values" << endl;
	cout << "================================================================================" << endl;
	ThirdClass thing1;
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Creating a ThirdClass Object(thing2) with no initialization values" << endl;
	cout << "================================================================================" << endl;
	ThirdClass thing2;
	cout << endl;

	cout << "================================================================================" << endl;
	cout << "Calling SecondClass object printMe function" << endl;
	cout << "================================================================================" << endl;
	second.printMe();
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Calling ThirdClass object printMe function" << endl;
	cout << "================================================================================" << endl;
	third.printMe();
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Calling test function" << endl;
	cout << "================================================================================" << endl;
	test(thing2);
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Calling ThirdClass object(thing1) printMe function" << endl;
	cout << "================================================================================" << endl;
	thing1.printMe();
	cout << endl;
	cout << "================================================================================" << endl;
	cout << "Calling ThirdClass object(thing2) printMe function" << endl;
	cout << "================================================================================" << endl;
	thing2.printMe();
	cout << endl;

	cout << "================================================================================" << endl;
	cout << "Testing copy constructor" << endl;
	cout << "================================================================================" << endl;
	cout << "Copy made of our FirstClass non instantiated Object" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	FirstClass thing3(first);

	cout << "================================================================================" << endl;
	cout << "Calling Destructors" << endl;
	cout << "================================================================================" << endl;

	return 0;
};