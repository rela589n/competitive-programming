#include <iostream>
#include <cmath>
using namespace std;
double mySin(double number, double eps = 0.0000000000001);

int main() {
	double a;
	cin >> a;
	cout.setf(ios::fixed);
	cout.precision(15);
	cout << "my sin:\t" << mySin(a) << endl;
	cout << "sin:\t" << sin(a) << endl;
	system("pause");
	return 0;
}

double mySin(double number, double eps) {
	double a, x = number, s, n = 2;
	const double PI = 3.1415926535897932384626;
	if (x >= 2 * PI)
		x -= 2 * PI * (long int)(x / (2 * PI));
	a = s = x;
	do {
		a = -a * x* x / (n*(n + 1));
		s += a;
		n += 2;
	} while (fabs(a) > eps);
	return s;
}