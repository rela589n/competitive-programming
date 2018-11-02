#include <iostream>
#include <ctime>
#include "arrays.h"

using namespace std;

int main() {
	int	l;
	cout << "Enter array length: ";
	cin >> l;
	
	int *arr = formArray(l);
	printArr(arr, l);

	convertArr(arr, l);
	cout << "converted array:\n";
	printArr(arr, l);

	system("pause");
	return 0;
}
