#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int k, n, i, j, max2 = 0, n2, max4 = 0, n4, votes[50][50];
	cin >> n >> k;
	cout << "\t\t\t�����. ������" << endl;
	for (i = 0; i < k; i++) {
		cout << "�������� "<<i + 1<<":\t";
		for (j = 0; j < n; j++) {
			votes[i][j] = rand() % 1001;
			cout << votes[i][j]<<'\t';
		}
		cout << endl << endl;
	}
	for (j = 0; j < n; j++) {
		if (max2 < votes[1][j]) {
			max2 = votes[1][j];
			n2 = j;
		}
		if (max4 < votes[3][j]){
			max4 = votes[3][j];
			n4 = j;
		}
	}
	if (max2)
		cout << "����������� ������� ������ ������� ��������� ���� � " << n2 + 1 << " ���������� �����\r\n";
	else
		cout << "������ �������� �� ������ ������� ������\r\n";
	if (max4)
		cout << "����������� ������� ������ ���������� ��������� ���� � " << n4 + 1<< " ���������� �����\r\n";
	else
		cout << "��������� �������� �� ������ ������� ������\r\n";

	cout << endl;
	system("pause");
	return 0;
}