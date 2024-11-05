#include "funcs.h"

string clientDataFile = "credit.dat";

int main() {
	initClientData(clientDataFile);
	
	fstream fileToMaipulate(clientDataFile);
	
	writeData(fileToMaipulate);

	string line;
	while (getline(fileToMaipulate, line)) {
		cout << line << endl;
	}
	fileToMaipulate.close();

	return 0;
}