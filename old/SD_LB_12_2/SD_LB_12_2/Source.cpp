//Source.cpp
#include <iostream>
#include "arrays.h"

int main() {
	int r, c;

	cout << "Enter the number of rows: ";
	cin >> r;
	cout << "Enter the number of cols: ";
	cin >> c;

	int **arr = formArray(r, c);
	printArray(arr, r, c);
	cout << endl;

	int* sumOfPositive = arraySumOfPositive(arr, r, c);
	cout << "array with sum of positive:\n";
	printArray(sumOfPositive, r);

	int* numOfPositive = arrayNumOfPositive(arr, r, c);
	cout << "\narray with number of positive:\n";
	printArray(numOfPositive, r);

	delArr(arr, r);
	delArr(sumOfPositive);
	delArr(numOfPositive);
	system("pause");
	return 0;
}