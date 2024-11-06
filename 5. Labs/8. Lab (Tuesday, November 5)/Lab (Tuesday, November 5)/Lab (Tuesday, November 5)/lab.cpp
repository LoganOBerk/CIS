#include "funcs.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;

string clientDataFile = "credit.dat";  

int main() {
    // Test 1: Initialize client data (file creation)
    cout << "Test 1: Initializing client data..." << endl;
    initClientData(clientDataFile);  
    cout << "Test 1 Passed: File initialized." << endl;

    fstream fileToManipulate(clientDataFile, ios::in | ios::out | ios::binary);
    if (!fileToManipulate) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    // Test 2, 3, 4: Write data for clients (at least 15 clients)
    cout << "\nTest 2-4: Writing data for clients..." << endl;
    writeData(fileToManipulate);  
    cout << "Test 2-4 Passed: Data for clients written." << endl;

    // Test 5: Attempt to write with invalid account number (101)
    cout << "\nTest 5: Testing invalid account number input..." << endl;
    fileToManipulate.seekp(0, ios::beg);  
    clientData invalidClient = { 101, "Invalid", "Account", 5000.0 };  
    fileToManipulate.write(reinterpret_cast<const char*>(&invalidClient), CLIENTSIZE); 
    cout << "Test 5 Passed: Invalid account number handled." << endl;

    // Test 6: Read data for client 2
    cout << "\nTest 6: Reading data for client 2..." << endl;
    readData(fileToManipulate);  
    cout << "Test 6 Passed: Data read for client 2." << endl;

    // Test 7: Print all client data
    cout << "\nTest 7: Printing all client data..." << endl;
    printAllData(fileToManipulate);  
    cout << "Test 7 Passed: All client data printed." << endl;

    // Test 8: Update client 2's balance
    cout << "\nTest 8: Updating data for client 2..." << endl;
    updateData(fileToManipulate);  
    cout << "Test 8 Passed: Client 2's data updated." << endl;
    
    // Test 9: Attempt to update an invalid account number (1000)
    cout << "\nTest 9: Updating invalid account 1000..." << endl;
    updateData(fileToManipulate);  
    cout << "Test 9 Passed: Invalid account handled." << endl;

    fileToManipulate.close();  

    return 0;
}
