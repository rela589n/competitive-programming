#include <iostream>

using namespace std;

int main() {
	long int attempt[1001][1001];
	unsigned short int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> attempt[i][j];
		}
	}
	bool flag = 0;
	for (int i = 2; i <= n; i++) {
		if (attempt[i][1] == 0) flag = 1;
		if (flag)
			attempt[i][1] = 0;
	}
	flag = 0;
	for (int j = 2; j <= m; j++) {
		if (attempt[1][j] == 0) flag = 1;
		if (flag)
			attempt[1][j] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (attempt[i][j] > 0) {
				attempt[i][j] = attempt[i - 1][j] + attempt[i][j - 1];
			}
		}
	}
	if (attempt[n][m] > 0)
		cout << attempt[n][m];
	else
		cout << "Impossible";
	return 0;
}