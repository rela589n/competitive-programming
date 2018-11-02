#include <iostream>
#include "arrays.h"

int main() {
	int len;

	cout << "Enter the length of array: ";
	cin >> len;

	int *arr = formArray(len);
	printArray(arr, len);

	int num;
	cout << "\nMultiple of what number? ";
	cin >> num;

	cout << "Sum of multiple to " << num << " in this array: ";
	cout << arraySumOfMultiple(arr, len, num) << endl;

	cout << "\nQuantity of multiple to " << num << " in this array: ";
	cout << arrayNumberOfMultiple(arr, len, num) << endl;

	system("pause");
	return 0;
}