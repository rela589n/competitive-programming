#include <iostream>

using namespace std;

int main() {
	short int n, num[101][101];
	cin >> n;
	for (short int i = 1; i <= n; i++) {
		for (short int j = 1; j <= n; j++) {
			cin >> num[i][j];
		}
	}
	short int k = 1;
	for (short int i = 1; i <= n; i++, k++) {
		for (short int j = k; j <= n; j++)
			if (num[i][j] != num[j][i]) {
				cout << "no";
				return 0;
			}
	}
	cout << "yes";
	return 0;
}