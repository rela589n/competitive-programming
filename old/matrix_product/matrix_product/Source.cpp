#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n1, m1, n2, m2, i, j, A[100][100], B[100][100], C[100][100] = { 0 };
	cout << "Введыть розмырність 1-ї матриці: ";
	cin >> n1 >> m1;
	cout << "Матриця A: " << endl << endl;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < m1; j++) {
			A[i][j] = rand() % 11 - 5;
			cout << A[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "Введыть розмырність 1-ї матриці: ";
	cin >> n2 >> m2;
	cout << "Матриця B: " << endl << endl;
	for (i = 0; i < n2; i++) {
		for (j = 0; j < m2; j++) {
			B[i][j] = rand() % 11 - 5;
			cout << B[i][j] << "\t";
		}
		cout << endl << endl;
	}

	if (m1 == n2) {
		cout << "Матриця C: " << endl << endl;
		// i - rows 1
		// j - cols 2
		// k - rows 2
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m2; j++) {
				for (int k = 0; k < m1; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		for (i = 0; i < n1; i++) {
			for (j = 0; j < m2; j++) {
				cout << C[i][j] << '\t';
			}
			cout << endl << endl;
		}
		
	}
	else {
		cout << "Неможливо помножити матриці" << endl;
	}
	
	system("pause");
	return 0;
}