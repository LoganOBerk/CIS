#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>

using namespace std;

extern const int CLIENTSIZE;

struct clientData {
    int accountNumber;
    char lastName[16];
    char firstName[11];
    float balance;
};

void initClientData(string&);
void writeData(fstream&);
void readData(fstream&);
void printAllData(fstream&);
void updateData(fstream&);


#endif //FUNCS_H

