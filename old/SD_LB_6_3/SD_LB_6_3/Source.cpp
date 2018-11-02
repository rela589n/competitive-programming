#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, i, j, A[100][100], At[100][100], B[100][100], C[100][100];
	cin >> n;
	cout << "Матрица A: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = rand() % 11 - 5;
			cout << A[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "Матрица B: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = rand() % 101 - 50;
			cout << B[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << "Транспонированая А: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			At[i][j] = A[j][i];
			cout << At[i][j] << "\t";
		}
		cout << endl << endl;
	}
	/*
	for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m2; j++) {
				for (int k = 0; k < m1; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	*/


	cout << "Матрица C: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = (A[i][j] + 9 * B[i][j]);
			cout << C[i][j] << "\t";
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}