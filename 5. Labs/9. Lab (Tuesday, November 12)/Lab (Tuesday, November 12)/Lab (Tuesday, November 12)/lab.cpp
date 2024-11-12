#include "funcs.h"

int main() {
	Record* record;
	getValidTool(record);
	cout << record->toolname;

	return 0;
}