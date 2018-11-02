#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a, b, h, x, y, composition = 1;
	cout << "Введіть діапазон аргумента: ";
	cin >> a >> b;
	cout << "Введіть крок аргумента: ";
	cin >> h;
	cout << "Введіть скільки перших значень потрібно порахувати: ";
	unsigned int count, quantity;
	cin >> count;
	quantity = count;
	
	cout.setf(ios::fixed);
	cout.precision(4);
	cout << "  X\t\t" << "  Y" << endl;
	for (x = a; x <= b; x += h) {
		if ((x <= 5) || (x >= 25)) {
			cout << x << "\t\t" << "Не пренадлежит области определения" << endl;
		}
		else {
			if (x < 10) {
				y = 1 - sin(x);
			}
			else if (x < 15) {
				y = (1 + cos(x)) / 2.;
			}
			else if (x < 20) {
				y = log10(x);
			}
			else if (x < 25) {
				y = pow(1. / tan(x), 2);
			}
			cout << x << "\t\t" << y << endl;
			if (quantity > 0) {
				composition *= y;
				quantity--;
			}
		}
	}
	if (composition != 1) {
		cout << "Добуток перших " << count << " значень: " << composition << endl;
	}
	
	system("pause");
	return 0;
}