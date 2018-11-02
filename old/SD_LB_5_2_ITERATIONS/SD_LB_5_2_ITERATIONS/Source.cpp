#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double s, eps, a;
	cout << "Enter epselon: ";
	cin >> eps;
	unsigned long int n = 1;
	a = s = pow(-1, n - 1) * sin(n) / (n*n);
	while (fabs(a) >= eps) {
		n++;
		a = pow(-1, n - 1) * sin(n) / (n*n);
		s += a;
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	cout << "s = " << s << endl;
	system("pause");
	return 0;
}