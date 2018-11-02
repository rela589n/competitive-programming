#include <iostream>

using namespace std;

int main() {
	double H, i, s;
	cin >> H >> i >> s;

	i += s / 60.;
	H += i / 60.;

	double res = H * 360 / 12.;
	res = (res <= 360) ? res : fmod(res, 360);

	cout.setf(ios::fixed);
	cout.precision(4);
	cout << res;

	system("pause");
	return 0;
}