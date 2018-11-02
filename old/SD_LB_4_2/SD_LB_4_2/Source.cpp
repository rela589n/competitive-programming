#include <iostream>
#include <math.h>
#include <windows.h>

const double PI = 3.1415926535897932384626;

using namespace std;

int main() {
	char change;

	SetConsoleOutputCP(1251);

	cout << "Що ви хочете обчислити??" << endl;
	cout << "a - периметр і площу рівнобедреної трапеції,\n b - площу поверхні циліндра,\n c - об’єм циліндра,\n d - площу круга" << endl;
	cout << "Зробіть ваш вибір: ";
	cin >> change;

	cout.setf(ios::fixed);
	cout.precision(3);


	float top, side, bot, square, height, radius, volume;
	switch (change) {
	case 'a':
		cout << "Введіть сторон рівнобедреної трапеції у наступному порядку:\n Верхня -> Бічна -> Нижня: ";
		cin >> top >> side >> bot;
		square = sqrt(side*side - (bot - top) / 2.) * (top + bot) / 2;
		cout << "Площа трапеції рівна " << square << endl;
		break;
	case 'b':
		cout << "Введіть висоту та радіус основи циліндра: ";
		cin >> height >> radius;
		square = 2 * PI * radius  * (height + radius);
		cout << "Площа циліндра: " << square << endl;
		break;
	case 'c':
		cout << "Введіть висоту та радіус основи циліндра: ";
		cin >> height >> radius;
		volume = PI * radius  * height * radius;
		cout << "Об\'єм циліндра: " << volume << endl;
		break;
	case 'd':
		cout << "Введіть радіус круга: ";
		cin >> radius;
		cout << "Площа круга: " << PI * radius * radius <<endl;
		break;
	default:
		cout << "Некоректні дані" << endl;
	}

	system("pause");

	return 0;
}
