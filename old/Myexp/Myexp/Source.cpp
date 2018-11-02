#include <iostream>
#include <cmath>

using namespace std;
double myexp(double num, double eps = 0.000000001);

int main() {
	double num;
	cin >> num;
	cout.precision(12);
	cout << "exp(num):\t" << exp(num) << endl;
	cout << "myexp(num):\t" << myexp(num) << endl;
	system("pause");
	return 0;
}

double myexp(double num, double eps) {
	double e = 1, a = 1, s = 1;
	unsigned int n = 0;
	do
		s += a *= num / (++n);
	while (fabs(a) > eps);
	return s;
}