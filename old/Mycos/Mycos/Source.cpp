#include <iostream>
#include <cmath>
using namespace std;
double mycos(double number, double eps = 0.0000000000001);

int main() {
	double a;
	cin >> a;
	cout.setf(ios::fixed);
	cout.precision(15);
	cout << "my cos:\t" << mycos(a) << endl;
	cout << "cos:\t" << cos(a) << endl;
	system("pause");

	return 0;
}

double mycos(double number, double eps) {
	double a, x = number, s, n = 1;
	const double PI = 3.1415926535897932384626;
	if (x >= 2 * PI)
		x -= 2 * PI * (long int)(x / (2 * PI));
	a = s = 1;
	do {
		a *= -x * x / (n*(n + 1));
		s += a;
		n += 2;
	} while (fabs(a) > eps);
	return s;
}