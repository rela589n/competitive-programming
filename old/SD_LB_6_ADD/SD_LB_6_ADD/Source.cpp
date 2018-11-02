#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	float matrix[100][100];
	int m, n, i, j, iCurr, jCurr;
	cout << "������ �-��� ����� � �������� ������ : ";
	cin >> n >> m;
	cout << "������ �������:\r\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << "������ a[" << i  << "][" << j << "] : ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	cout << "�� ���� ������� ������� �������� ������ �� ��'��� �������� �������?\n ������ ������ �� ��������: ";
	cin >> iCurr >> jCurr;
	if (!(iCurr >= 0 && iCurr < n && jCurr >= 0 && jCurr < m)) {
		iCurr = jCurr = 0;
		cout << "������� ������������ ����, �� ������ �� ������������ (0 0)" << endl;
	}
	cout << "����������� �������: " << endl;
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