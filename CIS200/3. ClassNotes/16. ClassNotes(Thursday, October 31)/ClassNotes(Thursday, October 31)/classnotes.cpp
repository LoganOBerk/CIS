#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Random File Access
	//	file access can be input output or both
	//	variable type ifstream, ofstream or fstream
	//	open file
void open(const string* filename, int mode, int access);

int main() {

	//determines how file is opened(using together requires | )
	//specifically opens the file for writing to
	ios::app; // append to end
	ios::ate; //opens at end of file
	ios::binary; //opens in binary (default is text)
	ios::in; //opens as input file
	ios::out; //opens as output file
	ios::_Nocreate; 
	ios::_Noreplace;
	ios::trunc;

	//ACCESS
	// 0 normal file access
	//1 read only
	//2 hidden file
	//4 system file
	//8 archive bit set
	//default is normal access
	//

	//ifstream has ios::in
	//ofstream has ios::out

	fstream myFile;

	myFile.open("myfile.txt", ios::in | ios::out);

	//Manipulate the file pointer using these commands
	//seekg() is seekget()
	//seekp() is seekput()
	//g is to read p is to write
	//	take two parameters
	//		offset byte count
	//		IOS flag
	//			beg  relative to begining of file
	//			cur  relative to current position in file
	//			end  relative to end of file
	//+ offset moves forward, - offset moves backward

	//second param needs to be the offset byte count
	myFile.seekg( 14, ios::cur); // forward 14 bytes from current location
	myFile.seekp(-9, ios::cur); //backward 9 bytes from current location
	myFile.seekg(0, ios::end); // move to end of file, after last val
	//occasionally a compiler will have issues with text files due to buffering, if so open in binary mode.
	//
	//tellg(), tellp() returns absolute position of the file pointer
	//fstream can almost read and write at the same time
	//iofile.seekg(iofile.tellg(),ios::beg()); seek to current file position can be useful when switching from writing to reading
	//
	// error detection
	// bad()
	// eof()
	// fail()
	// good()
	//
	//.write() will write from some value of sizeof(value) to file at current pointer
	//.read() will read from file and assign the byte size from it at current pointer
	//
	//
	// 
	// 
	//LISTS
	//	is a containter of items of the same type whose order is dictated by the user and whose positions are refrenced by number. The first entry in a list is at position 1
	// operations
	//	isEmpty
	//	getLength
	//	insert
	//	remove
	//	clear
	//	getEntry
	//	replace
	//TRANSFORMERS OR OBSERVERS
	//transformers change state
	//	insert
	//	remove
	//	replace
	//	clear
	//observers check state
	//	isEmpty
	//	getLength
	//	getEntry
	//
	//Lists are ordered by position as determined by the user
	//
	//Conceptually position number is part of data stored
	//But as implemented does position number need to be stored(implementation detail not part of algorithm)
	//
	//ex of function accepted values insert(aList, index, entry);


	return 0;
}