#include <iostream>
#include <cmath>
#include <windows.h>
#include <ctime>

double distance(double x1, double  y1, double x2, double y2);
double square(double a, double b, double c);
double half_perimetr(double a, double b, double c);
double triangle_height(double side, double square);
double bisector(double to_what_side, double side2, double side3);
double triangle_circle_radius(double a, double b, double c, bool described = 0);

using namespace std;


int main() {
	SetConsoleOutputCP(1251);
	double x1, y1, x2, y2, x3, y3;
	int change;
start:		cout << "Введіть координати x & y дли кожної точки трикутника: ";
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			double
				a = distance(x2, y2, x3, y3),
				b = distance(x1, y1, x3, y3),
				c = distance(x1, y1, x2, y2);

			if (a + b <= c || b + c <= a || a + c <= b) {
				cout << "Трикутник з заданми координатами не існує!!\n";
				goto start;
			}


additional:	cout << "Що ви хочете знайти в трикутнику?:\n";
	cout << "1 - площа;\n2 - висота;\n3 - бісектриса;\n4 - радіус кола\n";
	cin >> change;

	

	char sides[3][7] = { "a (BC)", "b (AC)", "c (AB)" };

	switch (change) {
	case 2:{
	case 1:		
		double s = square(a, b, c);
		if (change == 1) {
			cout << "Площа трикутника: " << s << endl;
		}
		else {
			cout << "До якої сторони потрібно обчислти висту?\n";
			cout << "1 - " << sides[0] << ";\n2 - " << sides[1] << ";\n3 - " << sides[2] << endl;
			cin >> change;
			double h = (change == 1) ? triangle_height(a, s) :
						(change == 2) ? triangle_height(b, s) :
						 (change == 3) ? triangle_height(c, s) :
						  -1;
			if (h != -1)
				cout << "Висота до сторони " << sides[change - 1] << ": " << h << endl;
			else {
				cout << "Помилка вибору" << endl;
			}
		}
		break;
	}
		   // -3 3 3 3 0 0
	case 3:{
		cout << "До якої сторони ви хочете обчислити бісектрису?\n";
		cout << "1 - " << sides[0] << ";\n2 - " << sides[1] << ";\n3 - " << sides[2] << endl;
		cin >> change;
		double w = (change == 1) ? bisector(a, b, c) :
					(change == 2) ? bisector(b, a, c) :
					 (change == 3) ? bisector(c, a, b) :
					  -1;
		if (w != -1)
			cout << "Бісектриса до сторони " << sides[change - 1] << ": " << w << endl;
		else {
			cout << "Помилка вибору" << endl;
		}
		break;
	}
	case 4:{
		cout << "Радіус описаного (1), чи вписаного (2) кола ви хочете обчислити? ";
		cin >> change;
		double r = (change == 1) ? triangle_circle_radius(a, b, c, 1) :
					(change == 2) ? triangle_circle_radius(a, b, c) :
					 -1;
		if (r != -1)
			cout << "Радіус: " << r << endl;
		else {
			cout << "Помилка вибору" << endl;
		}
		break;
	}
	default:
		cout << "Помилка введення!" << endl;
	}
	cout << "Хочете ще щось знайти для цього ж трикутника?\t(1 - так, 0 - ні): ";
	cin >> change;
	if(change == 1)
		goto additional;
	else{
		cout << "Хочете обчислити щось для нового трикутника?\t(1 - так, 0 - ні): ";
		cin >> change;
		if (change == 1)
			goto start;
	}
	system("pause");
	return 0;
}

double distance(double x1, double  y1, double x2, double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double square(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
double half_perimetr(double a, double b, double c){
	return (a + b + c) / 2.;
}

double triangle_height(double side, double square) {
	return 2 * square / side;
}

double bisector(double to_what_side, double side2, double side3) {
	double p = (to_what_side + side2 + side3) / 2.;
	return 2 / (side2 + side3) * sqrt(side2 * side3 * p * (p - to_what_side));
}

double triangle_circle_radius(double a, double b, double c, bool described) {
	double p = (a + b + c) / 2, s = sqrt(p*(p - a)*(p - b)*(p - c));
	if (described)
		return a * b * c / (4 * s);
	return s / p;
}