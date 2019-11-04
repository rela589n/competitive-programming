#include <iostream>
#include <cmath>
#include "mMath.h"

using namespace std;

int main() {

	double a;
	cin >> a;
	cout.setf(ios::fixed);
	cout.precision(15);
	cout << "my cos:\t" << mycos(a) << endl;
	cout << "cos:\t" << cos(a) << endl;

	cout << "\nmy sin:\t" << mysin(a) << endl;
	cout << "sin:\t" << sin(a) << endl;

	cout << "\nmy tg:\t" << mytg(a) << endl;
	cout << "tg:\t" << tan(a) << endl;

	cout << "\nmy exp:\t" << myexp(a) << endl;
	cout << "exp:\t" << exp(a) << endl;

	cout << "\nmy log:\t" << mylog(a) << endl;
	cout << "log:\t" << log(a) << endl;

	cout << "\nmy pow 2.5:\t" << mypow(a, -3) << endl;
	cout << "pow 2.5:\t" << pow(a, -3) << endl;
	//mypow

	
	system("pause");

	return 0;
}
