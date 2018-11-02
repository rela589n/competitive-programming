#pragma once

using namespace std;

int** formArray(int rows, int cols);
void deleteArray(int **arr, int rows);
void printArray(int **arr, int rows, int cols);
void printArray(int *arr, int size);

int** formArray(int rows, int cols) {
	int **arr = new int*[rows], i, j;

	for (i = 0; i < rows; i++) {
		arr[i] = new int[cols];
		for (j = 0; j < cols; j++) {
			cout << "Enter arr[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
			//arr[i][j] = rand() % 101 - 50;
		}
	}
	return arr;
}

void deleteArray(int **arr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
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
