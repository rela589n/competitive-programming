#include <iostream>
#include <ctime>

const int ARR_COLS = 30;
const int ARR_ROWS = 30;

void form_array(int arr[][ARR_COLS], int rows, int cols);

void print_array(int arr[][ARR_COLS], int rows, int cols);
void print_array(int arr[], int cols);

void quant_of_negative_and_max_in_cols(int arr[][ARR_COLS], int rows, int cols, int quant_of_negative[], int max[]);
using namespace std;

int main() {
	srand(time(NULL));
	int rows, cols, i, j;
	
	char change;

	do{
	int quantity_of_negative[ARR_COLS], max[ARR_COLS];
	int A[ARR_ROWS][ARR_COLS];
	cout << "enter number of rows and cols: ";
	cin >> rows >> cols;

	form_array(A, rows, cols);
	print_array(A, rows, cols);

	quant_of_negative_and_max_in_cols(A, rows, cols, quantity_of_negative, max);

	cout << "quantity of negative numbers in cols in matrix A:\n\n";
	print_array(quantity_of_negative, cols);

	cout << "\n\nmax in each col:\n\n";
	print_array(max, cols);

	cout << "Do you want to work with another array? (y/n): ";
	cin >> change;

	} while (change == 'y' || change == 'Y');


	system("pause");
	return 0;
}

void quant_of_negative_and_max_in_cols(int arr[][ARR_COLS], int rows, int cols, int quant_of_negative[], int max[]) {
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

void form_array(int arr[][ARR_COLS], int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++)
			arr[i][j] = rand() % 101 - 50;
	}
}

void print_array(int arr[][ARR_COLS], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << '\t';
		cout << "\n\n";
	}
}
void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}