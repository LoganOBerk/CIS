#include "funcs.h"


using namespace std;



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
    vector<int> previousInputs;
    cout << "Please enter data for at least 15 client records" << endl;
    while (searchingForData) {
        previousInputs.push_back(currentClient->accountNumber);

        bool alreadyWritten;
        do {
            alreadyWritten = false;
            cout << "Inputting data for client record " << ++clientRecordNum << endl;
            cout << "Please enter an account number (1-100): ";
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

            for (auto in : previousInputs) {
                if (in == currentClient->accountNumber) {
                    cout << "You already wrote to this account!" << endl;
                    clientRecordNum--;
                    alreadyWritten = true;
                }
            }
        } while (alreadyWritten);

        string inputLastName;
        cout << "Please enter a last name: ";
        getline(cin, inputLastName);
        int lengthOfInput = static_cast<int>(inputLastName.length());
        if (lengthOfInput > 15) lengthOfInput = 15;
        for (int i = 0; i < lengthOfInput; i++) {
            currentClient->lastName[i] = inputLastName[i];
        }
        currentClient->lastName[lengthOfInput] = '\0';

        string inputFirstName;
        cout << "Please enter a first name: ";
        getline(cin, inputFirstName);
        lengthOfInput = static_cast<int>(inputFirstName.length());
        if (lengthOfInput > 10) lengthOfInput = 10;
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
                cerr << "Not a valid balance, try again: ";
                invalid = true;
            }
        }

        file.seekp((currentClient->accountNumber - 1) * CLIENTSIZE);
        file.write(reinterpret_cast<const char*>(currentClient), CLIENTSIZE);

        if (clientRecordNum >= 15) {
            cout << "Would you like to continue recording data? (y/n): ";
            char input;
            while (!(cin >> input) || (input != 'y' && input != 'n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter 'y' or 'n': ";
            }
            searchingForData = (input == 'y');
        }
        if (clientRecordNum == 100) {
            searchingForData = false;
        }
    }
    delete currentClient;
}

void readData(fstream& file) {
    bool searching = true;
    do {
        int input;
        cout << "Please enter an account number to search for (1-100) or 0 to quit: ";
        do {
            while (!(cin >> input) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number: ";
            }
            if (input < 1 || input > 100) {
                if (input == 0) {
                    searching = false;
                    break;
                }
                cout << "Please enter an account number between 1 and 100: ";
            }
        } while (input < 1 || input > 100);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        if (searching) {
            clientData currentClient;
            file.seekg((input - 1) * CLIENTSIZE);
            if (file.read(reinterpret_cast<char*>(&currentClient), CLIENTSIZE)) {
                cout << "Account Number: " << currentClient.accountNumber << endl;
                cout << "Last Name: " << currentClient.lastName << endl;
                cout << "First Name: " << currentClient.firstName << endl;
                cout << "Balance: " << currentClient.balance << endl;
            }
            else {
                cout << "No data found for account number " << input << endl;
            }
        }
    } while (searching);
}

void printAllData(fstream& file) {
    clientData currentClient;

   
    file.seekg(0, ios::beg);

   
    cout << left << setw(15) << "Account Number"
        << setw(20) << "Last Name"
        << setw(15) << "First Name"
        << setw(10) << "Balance" << endl;
    cout << string(60, '-') << endl;  

    while (file.read(reinterpret_cast<char*>(&currentClient), CLIENTSIZE)) {
        if (currentClient.accountNumber != 0) { 
            cout << left << setw(15) << currentClient.accountNumber
                << setw(20) << currentClient.lastName
                << setw(15) << currentClient.firstName
                << setw(10) << fixed << setprecision(2) << currentClient.balance
                << endl;
        }
    }

    
    file.clear();  
    file.seekg(0, ios::beg);
}

void updateData(fstream& file) {
        clientData* currentClient = new clientData;

        bool searchingForData = true;

        while (searchingForData) {
            cout << "Please enter an account number to override (1-100) type 0 to quit: ";
            
                do {
                    while (!(cin >> currentClient->accountNumber) || cin.peek() != '\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a valid number: ";
                    }
                    if (currentClient->accountNumber < 1 || currentClient->accountNumber > 100) {
                        if (currentClient->accountNumber == 0) {
                            searchingForData = false;
                            break;
                        }
                        cout << "Please enter an account number between 1 and 100: ";
                    }
                } while (currentClient->accountNumber < 1 || currentClient->accountNumber > 100);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

      
            if (searchingForData) {
                string inputLastName;
                cout << "Please enter a last name: ";
                getline(cin, inputLastName);
                int lengthOfInput = static_cast<int>(inputLastName.length());
                if (lengthOfInput > 15) lengthOfInput = 15;
                for (int i = 0; i < lengthOfInput; i++) {
                    currentClient->lastName[i] = inputLastName[i];
                }
                currentClient->lastName[lengthOfInput] = '\0';

                string inputFirstName;
                cout << "Please enter a first name: ";
                getline(cin, inputFirstName);
                lengthOfInput = static_cast<int>(inputFirstName.length());
                if (lengthOfInput > 10) lengthOfInput = 10;
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
                        cerr << "Not a valid balance, try again: ";
                        invalid = true;
                    }
                }

                file.seekp((currentClient->accountNumber - 1) * CLIENTSIZE);
                file.write(reinterpret_cast<const char*>(currentClient), CLIENTSIZE);
            }
        }
        delete currentClient;
}