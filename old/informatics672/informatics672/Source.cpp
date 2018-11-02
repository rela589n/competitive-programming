#include <iostream>

using namespace std;

int main() {
	long int n, k, L[10000], r = 1, l = 100, level, summ = 0;
	cin >> n >> k;

	for (long int i = 0; i < n; i++) {
		cin >> L[i];
		if (l < L[i])
			l = L[i];
		summ += L[i];
	}
	if (summ >= k) {
		//cout << "l = " << l << endl;
		long int center;
		while (l - r > 0) {
			long int level = 0;
			center = (l + r) / 2;
			cout << "\tleft = " << l << endl;
			cout << "\tright = " << r << endl;
			cout << "\tcenter = " << center << endl;
			for (long int i = 0; i < n; i++) {
				level += L[i] / center;
				cout << "\t\tlevel = " << level << endl;
			}
			if (level >= k) {
				r = center + 1;
			}
			else if(level < k) {
				l = center - 1;
			}
		}
		cout << "l = "<<l << endl;
		cout << "r = "<<r << endl;
		if (r != center) r--;
		cout << r << endl;
	}
	else {
		cout << 0 << endl;
	}
	system("pause");
	return 0;
}