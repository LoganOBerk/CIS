#include "funcs.h"

struct clientData {
	int accountNumber;
	char lastName[16];
	char firstName[11];
	float balance;
};

const int CLIENTSIZE = sizeof(clientData);

void initClientData(string& fileName) {
	ofstream creditFile(fileName, ios::out);
	clientData bankClient = { 0, "", "", 0.0 };
	for (int i = 1; i <= 101; i++) {
		creditFile.write(reinterpret_cast<const char*>(&bankClient), CLIENTSIZE);
	}
	creditFile.close();
}

void writeData(fstream& file) {
	clientData* currentClient = new clientData;

	bool searchingForData = true;
	int clientRecordNum = 0;
	cout << "Please enter data for at least 15 client Data records" << endl;
	while (searchingForData) {
		cout << "Inputing data for client record " << ++clientRecordNum << endl;

		cout << "Please enter a account number (1-100): ";
		do {
			while (!(cin >> currentClient->accountNumber) || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a valid number: ";
			}
			if (currentClient->accountNumber < 1 || currentClient->accountNumber > 100) {
				cout << "Please enter an account number between 1 and 100: ";
			}
		} while (currentClient->accountNumber < 1 || currentClient->accountNumber > 100);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');



		string inputLastName;
		cout << "Please enter a lastName: ";
		getline(cin, inputLastName);
		int lengthOfInput = static_cast<int>(inputLastName.length());
		if (lengthOfInput > 15) {
			lengthOfInput = 15;
		}
			for (int i = 0; i < lengthOfInput; i++) {
				currentClient->lastName[i] = inputLastName[i];
			}
			currentClient->lastName[lengthOfInput] = '\0';


		string inputFirstName;
		cout << "Please enter a firstName: ";
		getline(cin, inputFirstName);
		lengthOfInput = static_cast<int>(inputFirstName.length());
		if (lengthOfInput > 10) {
			lengthOfInput = 10;
		}
		for (int i = 0; i < lengthOfInput; i++) {
			currentClient->firstName[i] = inputFirstName[i];
		}
		currentClient->firstName[lengthOfInput] = '\0';

		string inputBalance;
		bool invalid = true;
		cout << "Please enter a balance: ";
		while (invalid) {
			getline(cin, inputBalance);
			try {
				currentClient->balance = stof(inputBalance);
				invalid = false;
			}
			catch (...) {
				cerr << "Not a valid balance try again: ";
				invalid = true;
			}
		}

		file.write(reinterpret_cast<const char*>(&currentClient), CLIENTSIZE);

		delete currentClient;
		if (clientRecordNum == 1) {
			break;
		}
	}
	
}