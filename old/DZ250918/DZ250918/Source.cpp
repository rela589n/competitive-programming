#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	char change;
	cout << "������ ��� ��� ������ ������ ��������� ����� � ��������: " << endl;
	cout << "a - ���������, b - ����, c - �������, d - �����������. " << endl;
	cin >> change;

	cout.setf(ios::fixed);
	cout.precision(3);

	switch (change) {
		case 'a': {
			float a, b, c, p;
			cout << "������ ������� ����������" << endl;
			cin >> a >> b >> c;

			if(a + b > c && a + c > b && b + c > a) {
				p = (a + b + c) / 2.;
				cout << "����� = " << sqrt(p*(p - a)*(p - b)*(p - c)) << endl;
				cout << "�������� = " << a + b + c << endl;
			}
			else 
				cout << "����� ��������� �� ����" << endl;
			break;
		}
		case 'b': {
			const double PI = 3.1415926535897932384626;
			double r;
			
			cout << "������ ����� �����: ";
			cin >> r;

			cout << "����� = " << PI * r * r << endl << "������� ����� = " << 2 * PI*r << endl;
			break;
		}
		case 'c': {
			float a;
			cout << "������ ������� ��������: ";
			cin >> a;

			cout << "����� = " << a * a << endl << "�������� = " << 4 * a << endl;
			break;
		}
		case 'd': {
			float a, b;
			cout << "������ ������� ������������: ";
			cin >> a >> b;

			cout << "����� = " << a * b << endl << "�������� = " << 2 * (a + b) << endl;
			break;
		}
		default:
			cout << "����������� ����" << endl;

	}

	system("pause");
	return 0;
}