#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	char change;
	cout << "Введіть для якої фігури хочете обчислити площу і периметр: " << endl;
	cout << "a - трикутник, b - круг, c - квадрат, d - прямокутник. " << endl;
	cin >> change;

	cout.setf(ios::fixed);
	cout.precision(3);

	switch (change) {
		case 'a': {
			float a, b, c, p;
			cout << "Введіть сторони трикутника" << endl;
			cin >> a >> b >> c;

			if(a + b > c && a + c > b && b + c > a) {
				p = (a + b + c) / 2.;
				cout << "Площа = " << sqrt(p*(p - a)*(p - b)*(p - c)) << endl;
				cout << "Периметр = " << a + b + c << endl;
			}
			else 
				cout << "Такий трикутник не існує" << endl;
			break;
		}
		case 'b': {
			const double PI = 3.1415926535897932384626;
			double r;
			
			cout << "Введіть радіус круга: ";
			cin >> r;

			cout << "Площа = " << PI * r * r << endl << "Довжина круга = " << 2 * PI*r << endl;
			break;
		}
		case 'c': {
			float a;
			cout << "Введіть сторону квадрата: ";
			cin >> a;

			cout << "Площа = " << a * a << endl << "Периметр = " << 4 * a << endl;
			break;
		}
		case 'd': {
			float a, b;
			cout << "Введіть сторони прямокутника: ";
			cin >> a >> b;

			cout << "Площа = " << a * b << endl << "Периметр = " << 2 * (a + b) << endl;
			break;
		}
		default:
			cout << "Некоректний вибір" << endl;

	}

	system("pause");
	return 0;
}