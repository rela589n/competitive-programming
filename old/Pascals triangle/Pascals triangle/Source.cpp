#include <iostream>

using namespace std;

int main() {
	unsigned long int n, m, k = 0, num[1000][1000], i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		num[i][0] = 1;
	for (i = 1; i < m; i++) {
		num[0][i] = 1;
	}
	for (i = 1; i < n; i++){
		for (j = 1; j < m; j++) {
			num[i][j] = num[i - 1][j] + num[i][j - 1];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}