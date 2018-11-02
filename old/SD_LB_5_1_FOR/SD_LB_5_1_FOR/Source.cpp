#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	long double composition, a, b, h, x, y, power, yStart, yEnd;
	cout << "������ ������� ���������: ";
	cin >> a >> b;
	cout << "������ ���� ���������: ";
	cin >> h;
	cout << "������ ������� ��� ����������  ������������ �������: ";
	cin >> yStart >> yEnd;

	cout.setf(ios::fixed);
	cout.precision(4);
	cout << "  X\t\t" << "  Y" << endl;
	for (x = a, composition = 1, power = 0; x <= b; x += h) {
		y = x * exp(x) * sin(2 * x);
		cout << x << "\t\t" << y << endl;
		if ((y >= yStart) && (y <= yEnd)) {
			composition *= y;
			power++;
		}
	}
	if (power > 0) {
		cout << "\n������ �����������: " << pow(abs(composition), 1. / power) << endl;
	}
	else {
		cout << "�� ����������� ����� ������� ������� �� ������ �������" << endl;
	}

	system("pause");
	return 0;
}