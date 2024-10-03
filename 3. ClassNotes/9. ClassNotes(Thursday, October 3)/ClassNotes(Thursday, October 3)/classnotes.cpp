#include <iostream>

using namespace std;

int main() {

	//UNIX
	//Unique OS
	//Operating system: control program of a computer
	//Functionality: allocate computer resource
	//	Central Processing unit
	//	Memory
	//	Peripheral
	//
	//Three variations of Unix are popular
	// BSD
	// System V
	// Linux
	//
	//Machine independent (written by C)
	//Open source without cost
	//Powerful scripting lanuages
	//Multi-tasking
	//	time slicing is used to do portions of running things 
	//	will portion a fraction of a second to multiple different opperations
	//Multi-user
	//Widely accepted
	//
	//UNIX STRUCTURE
	//hardware
	//kernel
	//shell
	//	compilers
	//	mail and messages
	//	etc
	//
	//System kernel
	//	Heart of Unix system responsible for controlling computer resources and scheduling user jobs
	//Shell
	//	command prompt interface between user and OS
	//Interpreter
	//	A higher level language which uses system calls directly (compared to C)
	//	Famous shell scripting languages Borne, C, Korn
	//
	//Utilities
	//	Commands - several hundred utility programs (sort and man)
	//Applications
	//	Anything running on computer
	//
	//Prompts: When a computer is ready to listen to directions it shows a prompt
	//Commands: Directions given to computer
	//
	//Logging in (nothing happens in password just hit enter)
	//	login: Logan
	//	Password:
	//
	//	Welcome to UNIX!
	//
	//	$
	//
	//Change password(it must be at least six characters long, must contain at least 2 letters and one number)
	//	$ passwd
	//	Changing password for Logan
	//	Old password:
	//	New password:
	//	Re-enter new password:
	//
	//Logging out
	//	type logout
	//
	//Getting information
	//The "man" command used to retrieve descriptions of all Unix Commands
	//
	//$ man -k sort 
	//	gives name of command and description related to sort
	//Output: A list of utility commands that you can use to sort a list of words
	//	Name of command
	//	Section of manual
	//	A brief description
	//
	//Hierarchical file structure
	//	Unix file system is hierarchial, like a family tree
	//	One difference between family tree and Unix file structure
	// 
	// 
	//Root directory
	//	highest level top directory in UNIX expressed by /
	//	filepath will be expressed with /'s
	//
	//Pathnames
	// refers to the location of a file in Unix
	// pathnames/file_name
	// cd .. will go back one cd.. /(name) will go forward to file
	//
	//Find current working directory
	//	$pwd
	//
	//Relative pathname refers to file with respect to current working directory
	//
	//Shorthand for home directory : ~username
	//
	//Create a directory
	//	$mkdir
	//	$ls is a command to list all files/directories in current
	//		-F is option to show directories with an appended /
	//	$ls file_name will show all after
	//
	//Changing to another directory
	//	$cd to make another directory current
	//File names
	//	as many as 255 chars
	//	no two files in the same directory share the same name
	//	invisible file name
	//	file name starts with a period like .login
	//
	//To see ordinary files and directories without invisible files
	//	$ls - l
	//	-l displays in a long list
	//	-a is the option to display everything
	//	-al will display everything in a long list including invisible files
	//
	//  dr represents directory
	//	- represents file
	//	. represents invisible filename
	//Filename extention is part of filename following an embedded period
	//	compute.c
	//	compute.o
	//	compute   same as exe file
	//
	//*Access permissions of files
	//	Unix allows to specify access
	//		-Owner : you
	//		-Group : people in owner group
	//				-g option that displays group name
	//		-Others : everyone else
	//	Access rights
	//		-Read perms
	//		-Write perms
	//		-Execute perms
	// 
	// -rwxrw-r--
	//	- file, rwx owner perms, rw- group perms, r-- everyone else perms
	return 0;
}