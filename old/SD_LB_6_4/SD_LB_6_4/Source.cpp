#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, m, M[100][100], i, j;
	unsigned long int summ = 0;
	cin >> n >> m;
	cout << "Матриця:" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			M[i][j] = rand() % 151 - 50;
			cout << M[i][j] << "\t";
			if (M[i][j] > 1) {
				summ += M[i][j] * M[i][j];
			}
		}
		cout << endl << endl;
	}
	cout << endl;
	if (summ) {
		cout << "Сума квадратів елементів, більших за 1: " << summ;
	}
	else {
		cout << "Не було елементів, більших за 1!";
	}
	cout << endl;
	system("pause");
	return 0;
}