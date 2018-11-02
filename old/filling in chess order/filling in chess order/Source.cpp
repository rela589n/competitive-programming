#include <iostream>

using namespace std;

int main() {
	long int n, m, k = 1;
	cin >> n >> m;
	cout.fill(' ');
	for (long int i = 0; i < n; i++) {
		for (long int j = 0; j < m; j++) {
			cout.width(4);
			if ((i + j) % 2 != 0) {
				cout << 0;
			}
			else {
				cout << k++;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}