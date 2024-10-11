#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

const int NUM_DEPTS = 2;
const int NUM_STORES = 2;
const int NUM_MONTHS = 12;

void printMonthlySales(int&, float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]);
int getUserMonthInput();
string validateStringInput();
void collectArrayData(float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]);
void printArray(float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]);

#endif TASK_H