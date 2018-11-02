#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	unsigned int m, n, i, j;
	double avarage = 0, matrix[100][100];
	ofstream res_file("result.txt", ios_base::out);
	if (res_file.is_open()) {
		cout << "������ ������� ����� � �������� ������: ";
		cin >> n >> m;
		res_file.precision(5);
		cout.precision(5);
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				matrix[i][j] = (rand() % 2001 - 1000) / 10.;
				res_file << matrix[i][j] << "\t";
			}
			res_file << endl << endl;
		}
		if (m > 1) {
			for (i = 0; i < n; i++) {
				avarage += matrix[i][1];
			}
			avarage /= n;
			res_file << "������ ����������� �������� ��������  ������� ������� ������: " << avarage;
		}
		else
			res_file << "���� 2-�� ������� ������" << endl;
		res_file.close();
		ifstream res_file("result.txt", ios_base::in);
		while (!res_file.eof()) {
			char line[400];
			res_file.getline(line, 400);
			cout << line<<endl;
		}
		res_file.close();
	}
	else
		cout << "���� �� ������" << endl;
	system("pause");
	return 0;
}