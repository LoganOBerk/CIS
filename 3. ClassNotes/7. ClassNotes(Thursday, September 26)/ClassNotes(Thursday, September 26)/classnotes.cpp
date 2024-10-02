#include <iostream>

using namespace std;

//Pointer errors
	//MEMORY LEAK
	// occurs when new is used and is not followed correctly with delete 
	//DANGLING POINTER
	// occurs when ppointer is created but does not point to a valid memory location
	// -fixed by assigning value nullptr after performing delete
	// COPY CONSTRUCTOR
	// a default copy constructor is automatically created without one and will copy each attribute
	// copies all values of original object into this object using memberwise(attribute) assignment
	//OVERLOADING ASSIGNMENT OPPERATOR
	// copies all values in one object to another
	//If class contains a pointer attribute or otherwise allocates memory
	// create destructor
	// create copy constructor
	// overload assignment operator
	// 
	// COPY CONSTRUCTOR CALLED
	// when a variable is being initialized from an object of the same calss
	// an object is passed by value to a function
	// 
	// 
	// DYNAMIC ARRAY ALLOCATION
void dynamic() {
	int arraySize = 100;
	double* dynamicArray = new double[arraySize]; //runtime vs standard compiletime 

	//to change arrays size create new larger array and copy old to new then delete old
	double* newArray = new double[arraySize * 1.5];
	for (int x = 0; x < arraySize; ++x) {
		newArray[x] = dynamicArray[x];   
		//pointer offset
		*(newArray + x) = *(dynamicArray + x);
	}
	delete[]dynamicArray;
	dynamicArray = newArray;
	newArray = nullptr;
	arraySize *= 1.5;
	}

//early binding , made durring compilation
//late binding , 
//RUNTIME STACK // declaired variables
//HEAP         //allocated memory
//STATIC STORAGE //global variables
//CODE STORAGE //where program is stored

//SMART POINTERS, MANAGED POINTERS
//int *x; considered a raw pointer, has to monitor to ensure delete occurs
//Object that acts like a raw pointer but with memory management features
// automatically deletes pointers and assigns null
// requires #include <memory>
// shared_ptr
// multiple instances of pointers pointing to same object
// unique_ptr
// sole owner of object
// weak_ptr	
//non owning refrence to an object owned by shared pointer
//unable to delete since it doesnt own it
//used when desired to have two objecrs refrence eachother


void rawSharedPointer() {
	//Raw
	string* myMagicPtr = new string;
	delete myMagicPtr;
	myMagicPtr = nullptr;

	//Shared
	shared_ptr<string> myMagicPtr(new string);
	//another way
	auto myMagicPtr = make_shared<string>;

	//unique ptr
	unique_ptr<string> var2(new string());
	auto var1 = make_unique<string>();
	unique_ptr<string> var3;

	//cannot assign unique ptr to another directly
	//have to use move
	auto myFancyPtr = move(myMagicPtr);
	
	//weak ptr
	auto sharedPtr1 = make_shared < string >();
	weak_ptr<string> weakPtr1 = sharedPtr1;
	//can use .lock to assign weak to shared
	shared_ptr<string> sharedPtr3 = weakPtr1.lock();
	weakPtr1.expired(); //returns true or false
	//can use a reset
	weakPtr1.reset(); //passes ownership, no arguments is same as assigning null
	int* xPtr = nullptr; // .get gets address
	//Virtual methods allows the compiler to do late binding which is necessary for polymorphism
}
Simple& Simple::operator=(const Simple& oldObj) {
	if (this != &oldObj)
	{
		delete intPtr;
		intPtr = new int;
		*intPtr = *(oldObj.intPtr);
	}
	return this;
}

void Max(Simple s) {

}
class Simple {
private: int* intPtr;
public: Simple() { intPtr = new int; }
	  ~Simple() { delete intPtr; }
	  Simple (const Simple& original) {intPtr = new int; *intPtr = *(original.intPtr); } //copy constructor
	  int* getPtr() const { return intPtr; }
};
int main() {
	Simple simple, second;
	cout << *(simple.getPtr());

	Max(simple);

	return 0;
};