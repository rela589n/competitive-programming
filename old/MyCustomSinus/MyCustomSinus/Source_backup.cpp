#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double eps, a, x, s, n = 2;
	cin >> x;
	eps = 0.00000001;
	a = s = x;
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << "a  = " << a << endl;
	cout << "s  = " << s << endl;
	do {
		a = -a * x*x / ((2 * n - 2) *(2 * n - 1));
		s += a;
		cout << "a  = " << a << endl;
		cout << "s  = " << s << endl;
		n++;
	} while (fabs(a) > eps);

	cout << "s = \t" << s << endl;
	cout << "sin = \t" << sin(x) << endl;
	cout << "n = \t" << n + 1 << endl;
	system("pause");
	return 0;
}
