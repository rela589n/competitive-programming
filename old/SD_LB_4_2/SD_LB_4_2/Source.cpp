#include <iostream>
#include <math.h>
#include <windows.h>

const double PI = 3.1415926535897932384626;

using namespace std;

int main() {
	char change;

	SetConsoleOutputCP(1251);

	cout << "�� �� ������ ���������??" << endl;
	cout << "a - �������� � ����� ����������� ��������,\n b - ����� ������� �������,\n c - �ᒺ� �������,\n d - ����� �����" << endl;
	cout << "������ ��� ����: ";
	cin >> change;

	cout.setf(ios::fixed);
	cout.precision(3);


	float top, side, bot, square, height, radius, volume;
	switch (change) {
	case 'a':
		cout << "������ ������ ����������� �������� � ���������� �������:\n ������ -> ����� -> �����: ";
		cin >> top >> side >> bot;
		square = sqrt(side*side - (bot - top) / 2.) * (top + bot) / 2;
		cout << "����� �������� ���� " << square << endl;
		break;
	case 'b':
		cout << "������ ������ �� ����� ������ �������: ";
		cin >> height >> radius;
		square = 2 * PI * radius  * (height + radius);
		cout << "����� �������: " << square << endl;
		break;
	case 'c':
		cout << "������ ������ �� ����� ������ �������: ";
		cin >> height >> radius;
		volume = PI * radius  * height * radius;
		cout << "��\'�� �������: " << volume << endl;
		break;
	case 'd':
		cout << "������ ����� �����: ";
		cin >> radius;
		cout << "����� �����: " << PI * radius * radius <<endl;
		break;
	default:
		cout << "��������� ���" << endl;
	}

	system("pause");

	return 0;
}
