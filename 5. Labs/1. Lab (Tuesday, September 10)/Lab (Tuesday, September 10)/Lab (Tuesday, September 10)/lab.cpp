#include "students.h"
int main() {
	Student student("CSC AI ");
	cout << student.printMe() << endl;

	string fileName;
	cout << "Please enter a filename for output write: ";
	student.validateFileName();


	return 0;
}