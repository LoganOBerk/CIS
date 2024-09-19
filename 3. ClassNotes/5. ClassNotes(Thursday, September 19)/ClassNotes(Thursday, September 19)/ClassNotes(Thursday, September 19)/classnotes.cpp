#include <iostream>

using namespace std;
class Square;

//used to swap name of a datatype from double to double represented as ItemType
typedef double ItemType;

//how to make a class a generic datatype, making a template
template <class ItemType>


//if writing a method
Square<ItemType>::Square() {

}
//virtual method
// virtual void setItem(const ItemTypes& theItem);
//virtual method can accept value from child method if we accept as virtual
//pure virtual is a methood that is a virtual method initialized as 0 
//virtual makes a generic method
//pure virtual says child will make this


//can declare any datatype
Square<anyDatatype> mySquare;

class Rectangle{
private: 
	int width, height;
public:
	friend Rectangle duplicate(const Rectangle& rect) {}
	//Square can access all information in Rectangle
	friend class Square;
};

int main() {

	//Friends
	//In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declaired
	//rule does not apply to friends
	//friends are functions or classes declaired with that keyword
	//a nonmember function can access the private and protected members if they are declaired as friend
	//writing an abstract class allows design to go to implementation
	// plain box, toy box, magic box
	//plain box
	//attributes 
	//holds one item
	//methods gets and sets


	//pointer
	//returns address where its pointing
	//memory address is 8 bytes
	//int is 4 bytes
	int x[10];

	//pointer is its own datatype
	int myVar, *iPtr;
	myVar = 8;
	iPtr = &myVar;
	*iPtr = -1; //changes value in memory




	
	


	return 0;
}