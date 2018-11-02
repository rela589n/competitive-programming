#include <iostream>

using namespace std;

int main() {
	long int n, m, k = 0;
	cin >> n >> m;
	cout.fill(' ');
	for (long int i = 0; i < n; i++) {
		for (long int j = 1; j <= m; j++, k++) {
			cout.width(3);
			if (i % 2 == 0) {
				cout << k;
			}
			else {
				cout << k + m - 2*j + 1;
			}
		}
		cout << endl;
	}
	return 0;
}