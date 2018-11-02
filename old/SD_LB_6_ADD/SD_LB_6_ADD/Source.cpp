#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	float matrix[100][100];
	int m, n, i, j, iCurr, jCurr;
	cout << "¬вед≥ть к-сть р€дк≥в ≥ стовбц≥в масиву : ";
	cin >> n >> m;
	cout << "¬вед≥ть матрицю:\r\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << "¬вед≥ть a[" << i  << "][" << j << "] : ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	cout << "Ќа €кий елемент потр≥бно розд≥лити непарн≥ та в≥д'Їмн≥ елементи матриц≥?\n ¬вед≥ть єр€дка та єстовбц€: ";
	cin >> iCurr >> jCurr;
	if (!(iCurr >= 0 && iCurr < n && jCurr >= 0 && jCurr < m)) {
		iCurr = jCurr = 0;
		cout << "ќск≥льки некорректний виб≥р, то обрано по замовчуванню (0 0)" << endl;
	}
	cout << "–езультуюча матриц€: " << endl;
	cout.precision(5);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] < 0 || fmod(matrix[i][j], 2) != 0) {
				matrix[i][j] /= matrix[iCurr][jCurr];
			}
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}