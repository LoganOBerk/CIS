#include <iostream>

using namespace std;

int main() {

	//UNIX
	//$ -l is an option to show long list
	//$ -g is an option to show group name
	//$ chmod a +rw
	//a means for all users chmod changes access permissions
	//+ adds perm - removes perm
	//o is for others 
	//g for group
	//u is for owner perms
	//
	//Links
	//a link is a pointer to another file
	//	hard link
	//		indistingushable from file 
	//		$ ln draft\home\alex\letter
	//	soft link
	//		distinguishable from source file
	//		draft is the name of the link
	//		$ ln -s draft\home\alex\letter
	//	can span across file systems, can connect directories
	//	not all versions of unix support it
	//
	// will give list of all people who are using system
	// $ finger
	//		TTY - name of terminal
	//		Idle - idle time
	//		When - login time
	//		Where - user's location
	// 
	// w command to show who and what all logged-in users are doing
	// JCPU job cpu
	// PCPU process que cpu
	// 
	//$Mail username
	//ctrl+D to signify end of message
	//$Mail checks mail
	//  > refers to current message
	//	& is the prompt of mail command
	//	N means new message
	//	Number of lines/number of characters
	//to read mail press enter on current one
	//	&d will delete
	//	&2 number of mail you want to access
	//	&q quits and doesnt delete
	//mail outside is $Mail emailaddress
	//	&echo Hi
	//	displays hi
	// 
	// $cp copy
	// $cp source target
	// 
	// $mv change name, or move the file
	// $mv existing new
	// 
	// $lpr print a file
	// $lpr report, print to default printer
	// $lpr -Phpli report, print on printer names Phpli

	// $cat report, display content of report
	// $grep used to find a string in a file
	// $grep 'credit' memo, looks for the string credit in file memo
	// $sort displays contents of a file in order by line
	// $head displays first 10 lines of file
	// $head -n, n being how many lines you want
	// $tail gives last 10 
	// $uniq is to display a file by skipping adjacent duplicate lines
	// $diff file1 file2
	// 4d3 4th line in first file 3rd line in 2nd file
	// < yellow, < line from first file, > line from second file
	// $whereis, is used to find the location of a command which may not be found in your current setting 
	// $which, find location of a version of a command which is being used in your current setting
	// $compress -v
	// v an option means verbose
	// replaces old file with the new compressed one
	// $uncompress
	// 
	//SOFTWARE DEVELOPMENT
	//	system life cycle components
	//		problem defn
	//		buisness reqs
	//		analysis and design
	//		build and test
	//		implementation
	//		maintenance
	//
	//




	return 0;
}