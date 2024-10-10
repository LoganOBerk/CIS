#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_ROWS = 3;
const int MAX_COLUMNS = 2;

void printArray(int arr[MAX_ROWS][MAX_COLUMNS]);
string validateUserInput();
void collectArrayData(int arr[MAX_ROWS][MAX_COLUMNS]);
int collectIntInput();
void insertPadding(int arr[MAX_ROWS][MAX_COLUMNS], int rowIndex, int colIndex);
int findMaxNumDigits(int arr[MAX_ROWS][MAX_COLUMNS]);
int howManyPositiveEven(int arr[MAX_ROWS][MAX_COLUMNS]);



#endif TASK_H
