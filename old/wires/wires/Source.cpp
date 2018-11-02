#include <iostream>

using namespace std;

bool canIbuild(long int val, long int L[10000], long int n, long int k);

int main() {
	long int n, k, L[10000], l = 1, r = 100, level;
	long long summ = 0;
	cin >> n >> k;

	for (long int i = 0; i < n; i++) {
		cin >> L[i];
		summ += L[i];
		if (r < L[i])
			r = L[i];
	}
	if (summ >= k) {
		while (r - l > 0) {
			long int center = (l + r) / 2;
			cout << "\tleft " << l << endl;
			cout << "\tright " << r << endl;
			cout << "\tcenter " << center << endl;
			cout << int(canIbuild(center, L, n, k)) << endl;
			if (canIbuild(center, L, n, k)) {
				l = center;
			}
			else {
				r = center - 1;
			}
		}
		cout << l << endl;
	}
	else {
		cout << 0 << endl;
	}

	system("pause");
	return 0;
}

bool canIbuild(long int val, long int L[10000], long int n, long int k) {
	long int level = 0;
	for (long int i = 0; i < n; i++) {
		level += L[i] / val;
	}
	return level >= k;
}