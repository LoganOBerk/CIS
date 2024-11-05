#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern const int CLIENTSIZE;

struct clientData;

void initClientData(string&);
void writeData(fstream&);



#endif //FUNCS_H

