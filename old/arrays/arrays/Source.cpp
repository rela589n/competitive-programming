#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru-Ru");
	long int x, a[100];
	for (int i = 0; i < 10; i++) {
		cout << "������� a["<<i<<"]: ";
		while (!(cin >> a[i])) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "���-�� �� ����� ����� �����!\n���������� ���� a[" << i << "]: ";
		}
		cout << a[i] << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("pause");
	return 0;
}