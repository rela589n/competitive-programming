//arrays.h

#pragma once

#include <ctime>
using namespace std;

bool isMultiple(int number, int multipleOfWhat);

int* formArray(int len);
void printArray(int *arr, int size);

int arrayNumberOfMultiple(int* arr, int len, int multipleOfWhat);
int arraySumOfMultiple(int* arr, int len, int multipleOfWhat);


bool isMultiple(int number, int multipleOfWhat) {
	return (number % multipleOfWhat) == 0;
}

int* formArray(int len) {
	srand(time(NULL));
	int *arr = new int[len], i, j;

	for (i = 0; i < len; i++) {
		//cout << "Enter arr[" << i << "]: ";
		//cin >> arr[i];
		arr[i] = rand() % 101 - 50;
	}
	return arr;
}

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int arrayNumberOfMultiple(int* arr, int len, int multipleOfWhat) {
	int numOfMult = 0;

	for (int i = 0; i < len; ++i) {
		if (isMultiple(arr[i], multipleOfWhat)) {
			numOfMult++;
		}
	}
	
	return numOfMult;
}

int arraySumOfMultiple(int* arr, int len, int multipleOfWhat) {
	int sumOfMult = 0;

	for (int i = 0; i < len; ++i) {
		if (isMultiple(arr[i], multipleOfWhat)) {
			sumOfMult += arr[i];
		}
	}

	return sumOfMult;
}