#include "DoublyLinkedList.h"
#include <fstream>
#include <ctime>
#include <cstdlib>

// Initialize file with random values
void initializeFileRandom(const string& filename, int count) {
    ofstream outFile(filename);
    if (!outFile) throw runtime_error("Failed to open file.");
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        outFile << (rand() % 100 + 1) << endl;
    }
    outFile.close();
}

void initializeFile(const string& filename, int count) {
    ofstream outFile(filename);
    if (!outFile) throw runtime_error("Failed to open file.");
    for (int i = 0; i < count; ++i) {
        outFile << 10 + i*5 << endl;
    }
    outFile.close();
}

int main() {
    const string filename = "integer.dat";
    const string errorLog = "errorlog.txt";

    initializeFile(filename, 5);

    DoublyLinkedList list;
    ifstream inFile(filename);
    ofstream logFile(errorLog);
    int value;

    while (inFile >> value) {
        try {
            if (value <= 0) throw invalid_argument("Value must be positive.");
            list.add(value);
        } catch (const exception& e) {
            logFile << "Error with value " << value << ": " << e.what() << endl;
        }
    }

    cout << "Main List (Ascending): ";
    list.print('M', 'A');

    cout << "Main List (Descending): ";
    list.print('M', 'D');

    cout << "Even Sub-list (Ascending): ";
    list.print('E', 'A');

    cout << "Even Sub-list (Descending): ";
    list.print('E', 'D');

    cout << "Odd Sub-list (Ascending): ";
    list.print('O', 'A');

    cout << "Odd Sub-list (Descending): ";
    list.print('O', 'D');

    cout << "Adding 55 to the list:" << endl;
    list.add(55);
    list.print('M', 'A');

    cout << "Deleting 55 from the list:" << endl;
    list.deleteValue(55);
    list.print('M', 'A');

    return 0;
}
