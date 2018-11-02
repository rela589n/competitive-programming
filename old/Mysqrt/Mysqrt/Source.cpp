#include <iostream>
#include <ctime>

double mySqrt(double number, double eps = 0.00000000001);
using namespace std;

int main() {
	double a;
	cin >> a;
	cout.setf(ios::fixed);
	cout.precision(10);
	cout <<"mySqrt:\t"<< mySqrt(a) << endl;
	cout << "Sqrt:\t" <<sqrt(a) << endl;
	system("pause");
	return 0;
}

double mySqrt(double number, double eps) {
	if (number < 0)
		return -1;
	double l = 0, r = number;
	while (r - l > eps) {
		long double center = (r + l) / 2.;
		if (center*center < number) {
			l = center;
		}
		else if (center * center > number) {
			r = center;
		}
		else {
			l = r = center;
		}
	}
	return l;
}
