#include <iostream>
#include "largeAddition.h"

using namespace std;

int main() {
	string n1, n2;

	cout << "Enter first large number: ";
	getline(cin, n1);

	cout << "Enter second large number: ";
	getline(cin, n2);

	cout << endl << n1 << " + " << n2 << " = " << largeAdd(n1, n2) << endl;
	system("pause");
	return 0;
}
