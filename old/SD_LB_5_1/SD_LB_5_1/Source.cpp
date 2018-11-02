#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	long double composition, a, b, h, x, y, power, yStart, yEnd;
	int change;
	cout << "������ ������� ���������: ";
	cin >> a >> b;
	cout << "������ ���� ���������: ";
	cin >> h;
	cout << "������ ������� ��� ����������  ������������ �������: ";
	cin >> yStart >> yEnd;
enter: cout << "���� ������ ������ ���������?\n" << "1 - for, \t 2 - while,\t 3 - do..while" << endl << endl<<"������ ��� ����: ";
	cin >> change;
	cout.setf(ios::fixed);
	cout.precision(4);
	cout << "  X\t\t" << "  Y" << endl;
	power = 0;
	x = a;
	composition = 1;
	switch (change) {
	case 1:
		for (; x <= b + h / 2.; x += h) {
			y = x * exp(x) * sin(2 * x);
			cout << x << "\t\t" << y << endl;
			if ((y >= yStart) && (y <= yEnd)) {
				composition *= y;
				power++;
			}
		}
		break;
	case 2:
		while (x <= b + h/9.) {
			y = x * exp(x) * sin(2 * x);
			cout << x << "\t\t" << y << endl;
			if ((y >= yStart) && (y <= yEnd)) {
				composition *= y;
				power++;
			}
			x += h;
		}
		break;
	case 3:
		do {
			y = x * exp(x) * sin(2 * x);
			cout << x << "\t\t" << y << endl;
			if ((y >= yStart) && (y <= yEnd)) {
				composition *= y;
				power++;
			}
			x += h;
		} while (x <= b + h / 2.);
		break;
	default:
		system("cls");
		cout << "����������� ������� ����� ������ �����, �������� ���" << endl;
		goto enter;
	}
	
	if (power > 0) {
		cout << "\n������ �����������: " << pow(abs(composition), 1. / power) << endl;
	}
	else {
		cout << "�� ����������� ������� ������� � ��������� �������" << endl;
	}

	system("pause");
	return 0;
}