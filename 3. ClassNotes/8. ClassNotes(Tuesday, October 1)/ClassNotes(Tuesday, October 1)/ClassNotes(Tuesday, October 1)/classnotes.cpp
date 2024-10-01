#include <iostream>
#include <string>

//used for tests 
#include <cassert>
using namespace std;


float Quotient(int numer, int denom) {
	if (denom == 0) 
		throw "Error";
	return (float) numer / denom;
	
}

int main() {

	//Exception handling
	//Exception Management 
	//define error condition
	//enclose code containing possible error(try)
	//alert the system if error occurs(throw)
	//handle error if it is thrown(catch)
	
	//throw signals an exception occured
	// throw Datatype;

	//assert statements
	int x = 5;
	assert(x == 5);
	
	
	//can try and catch for allocation failure when using new keword by checking for NULL
	int numer = 0;
	int denom = 5;
	bool assert;
	assert = (numer == denom);
	if (!assert) {
		cout << "FAIL" << endl;
	}

	
	try {
		Quotient(numer, denom);
		catch (string message) {

		}
		catch (...) {

		}
	}
	
	try {

		//identifies datatype of error
		throw "An error has occured";
	}
	catch (string message) {
		//executes the same datatype as throw
		cout << message << endl;
		return 1;
	}
	catch (...) { //default catch
		cout << "Error occured in function; unknown type" << endl;
	}


	//throws will exit function and look for a catch of same type can be used in functions
	//throw without datatypes are used for classes and inheritance rethrows same error by default


	//destructor of class is called after try so it will be unknown to catch
	//some standard exceptions can be used such as overflow_error e, e.what() to call the type

	return 0;
}