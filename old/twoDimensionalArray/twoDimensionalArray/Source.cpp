#include <iostream>
#include <ctime>
#include "workWithArrays.h"
#include "arraySort.h"

using namespace std;

int main() {
	srand(time(NULL));
	int r, c;

	cout << "Enter the number of rows: ";
	cin >> r;
	cout << "Enter the number of cols: ";
	cin >> c;

	int **arr = formArray(r, c);
	printArray(arr, r, c);
	cout << endl;

	twoDimensionalArraySort(arr, r, c);

	printArray(arr, r, c);
	cout << endl;


	deleteArray(arr, r);
	system("pause");
	return 0;
}
