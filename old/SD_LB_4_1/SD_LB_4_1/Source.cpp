#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	float a, b, c, d;
	short int change;

	cout << "����� �������" << endl;
	cout << "��� ������� �� ������ ���������?? 1 - E, 2 - A, 3 - B.\n ������ ��� ����: " << endl;
	cin >> change;

	cout.setf(ios::fixed);
	cout.precision(3);

	switch (change) {
	case 1:
		cout << "������ a, b: ";
		cin >> a >> b;
		if (log(a) != 0) {
			float E = (pow(sin(a + b * b), 3)) / log(a);
			if (E >= 0) {
				cout << "E = " << sqrt(E) <<endl;
			}
			else {
				cout << "����������� ��������" << endl;
			}
		}
		else {
			cout << "����������� ��������" << endl;
		}
		break;
	case 2:
		cout << "������ b: ";
		cin >> b;
		if(b > 0)
			cout << "A = " << (3 * cos(b*b) - 5 * b*b*b + 2 * log(b)) / (4 * exp(b + 2)) << endl;
		else
			cout << "����������� ��������" << endl;
		break;
	case 3:
		cout << "������ c, d: ";
		cin >> c >> d;
		if(cos(c) + sin(d) > 0) 
			cout << "B = " << 73 * c*c + log(cos(c) + sin(d)) << endl;
		else
			cout << "����������� ��������" << endl;
		break;
	default:
		cout << "���������� ������� ���" << endl;
	}

	float m, l, k, t, v, w;
	cout << "����� �������" << endl;

	cout << "������ m, l, k:";
	cin >> m >> l >> k;

	t = (m < 0)? k + 2 * l : k + 4 * l - 7;
	v = (t < -4) ? t * t : (t > -4) ? t - 2 : 3 * t + 4;
	w = 0.2 * t - v / 2;

	cout << "W = " << w << endl;

	system("pause");

	return 0;
}