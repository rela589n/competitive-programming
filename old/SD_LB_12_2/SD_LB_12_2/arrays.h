#pragma once

#include <ctime>

using namespace std;

int** formArray(int rows, int cols);

void delArr(int **arr, int rows);
void delArr(int *arr);

void printArray(int **arr, int rows, int cols);
void printArray(int *arr, int size);

int* arraySumOfPositive(int** arr, int rows, int cols);
int* arrayNumOfPositive(int** arr, int rows, int cols);


int** formArray(int rows, int cols) {
	srand(time(NULL));
	int **arr = new int*[rows], i, j;

	for (i = 0; i < rows; i++) {
		arr[i] = new int[cols];
		for (j = 0; j < cols; j++) {
			//cout << "Enter arr[" << i << "][" << j << "]: "
			//cin >> arr[i][j];
			arr[i][j] = rand() % 101 - 50;
		}
	}
	return arr;
}

void delArr(int **arr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void delArr(int *arr) {
	delete[] arr;
}

void printArray(int **arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}


int* arraySumOfPositive(int** arr, int rows, int cols) {
	int *arrSum = new int[rows];

	for (int i = 0; i < rows; ++i) {
		int sum = 0;

		for (int j = 0; j < cols; ++j) {
			if (arr[i][j] > 0) {
				sum += arr[i][j];
			}
		}

		arrSum[i] = sum;
	}

	return arrSum;
}

int* arrayNumOfPositive(int** arr, int rows, int cols) {
	int *arrQuant = new int[rows];

	for (int i = 0; i < rows; ++i) {
		int num = 0;

		for (int j = 0; j < cols; ++j) {
			if (arr[i][j] > 0) {
				++num;
			}
		}

		arrQuant[i] = num;
	}

	return arrQuant;
}