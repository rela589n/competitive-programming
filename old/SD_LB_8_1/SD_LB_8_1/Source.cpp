#include <iostream>
#include <ctime>

int** form_array(int rows, int cols);
void delete_array(int **arr, int rows);

void print_array(int** arr, int rows, int cols);
void print_array(int* arr, int size);

void quant_of_negative_and_max_in_cols(int **arr, int rows, int cols, int* quant_of_negative, int* max);
using namespace std;



int main() {
	srand(time(NULL));
	int rows, cols, i, j;

	/////////////////// first array
	cout << "enter number of rows and cols: ";
	cin >> rows >> cols;

	int **A = form_array(rows, cols);
	print_array(A, rows, cols);

	int *quantity_of_negative = new int[cols];
	int *max = new int[cols];

	quant_of_negative_and_max_in_cols(A, rows, cols, quantity_of_negative, max);

	cout << "quantity of negative numbers in cols in matrix A:\n\n";
	print_array(quantity_of_negative, cols);

	cout << "\n\nmax in each col:\n\n";
	print_array(max, cols);

	////////////////////// second array
	int rowsB, colsB;
	cout << "enter number of rows and cols 2-nd matrix: ";
	cin >> rowsB >> colsB;

	int** B = form_array(rowsB, colsB);
	print_array(B, rowsB, colsB);

	int *quantity_of_negativeB = new int[colsB];
	int *maxB = new int[colsB];

	quant_of_negative_and_max_in_cols(B, rowsB, colsB, quantity_of_negativeB, maxB);

	cout << "quantity of negative numbers in cols in matrix B:\n\n";
	print_array(quantity_of_negativeB, colsB);
	
	cout << "\n\nmax in each col int matrix B:\n\n";
	print_array(maxB, colsB);


	/////////////////// delete arrays
	delete[] max;
	delete[] maxB;
	delete[] quantity_of_negative;
	delete[] quantity_of_negativeB;
	delete_array(A, rows);
	delete_array(B, rowsB);
	system("pause");
	return 0;
}

void quant_of_negative_and_max_in_cols(int **arr, int rows, int cols, int* quant_of_negative, int* max) {
	for (int j = 0; j < cols; j++) {
		quant_of_negative[j] = 0;
		max[j] = arr[0][j];
		for (int i = 0; i < rows; i++) {
			if (arr[i][j] > max[j])
				max[j] = arr[i][j];
			if (arr[i][j] < 0)
				quant_of_negative[j]++;
		}
	}
}

int** form_array(int rows, int cols) {
	int **arr = new int*[rows], i, j;
	for (i = 0; i < rows; i++) {
		arr[i] = new int[cols];
		for (j = 0; j < cols; j++)
			arr[i][j] = rand() % 101 - 50;
	}
	return arr;
}

void delete_array(int **arr, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}

void print_array(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << '\t';
		cout << "\n\n";
	}
}
void print_array(int *arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}