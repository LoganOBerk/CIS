#include "myString.h"

using namespace std;

int main() {
	Status myStatus;
	myString* str1 = new myString(myStatus, "Hello");
	myString* str2 = new myString(myStatus, " World ");
	myString* str3 = new myString(myStatus, " Universe ");
		str1 = str1->replWholeString(*str2);
		str1->printStringScreen();

		str1 = str1->setString("apple");
		str2 = str2->setString("apricot");
		cout << str1->compareString(*str2);
		cout << endl;

		str1 = str1->setString("Hello");
		str2 = str2->setString("Hi");
		str1 = str1->replPartString(*str2, 1, 4);
		str1->printStringScreen();

		str1 = str1->setString("Hello");
		str1 = str1->partString(1, 5);
		str1->printStringScreen();

		str1->initString();
		str1->printStringScreen();

		str1 = str1->setString("Hello");
		str2 = str2->setString(" World ");
		str1->addEnd(*str2);
		str1->printStringScreen();

		str1 = str1->setString("Hello");
		str1->addStart(*str2);
		str1->printStringScreen();

		str1 = str1->setString("Hello");
		cout << str1->getString() << endl;

		cout << str1->numericString() << endl;
		cout << str1->alphabeticString() << endl;



	return 0;
}