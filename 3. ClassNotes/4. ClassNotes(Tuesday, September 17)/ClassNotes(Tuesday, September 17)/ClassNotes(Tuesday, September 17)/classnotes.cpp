#include <iostream>

using namespace std;

int main() {

	//Inheritance

	//Unified Modeling Language
	//writing psuedo class
	// - private, + public, # protected

	//	class name
	// -----------------------------
	//	attributes
	// -Name:string
	// -ID:string
	// -----------------------------
	//	methods
	// +setAll(string, string):void
	// +printAll():void
	// -----------------------------
	//outline before starting project


	//inheritance specifiers : public genStudent
	//inherited as public its whatever parent class had
	//inherited as protected all data is protected
	//inherited as private all data becomes private to child, no more can inherit from

	//classes - overriding methods vs overloading methods
	//parent calls its own method
	//child calls its own method
	//parent doesnt exist to child regardless of parameter count or type
	//child can explicitly call parent method parent::method();

	//elements of a class
	//private, protected data fields
	//constructors, destructrors
	//functions
	//preprocessor directives
	//use of initializers
	//use of typedef and/or constants (should be globally declaired)
	//inheritance

	//declare attributes as private or protected for inheritance
	//declare all gets as const
	//methods cannot modify class if const
	//parameters should be passed by refrence to be faster
	//declare parameter as const when not returning values as to avoid side effects

	//if a class has a data type than its an attribute
	//if class is a data type then its a class or subclass

	return 0;
};