#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<bool> > routes(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i) {
		int len;
		cin >> len;

		for (int j = 0; j < len; ++j) {
			int k;
			cin >> k;
			routes[i][k - 1] = true;
		}
	}

	set<int> first;
	first.insert(0);

	for (int j = 0; j < m; ++j) {
		if (routes[0][j]) {
			for (int k = 1; k < n; ++k) {
				if (routes[k][j]) {
					first.insert(k);
				}
			}
		}
		
	}

	if (first.size() < n) {
		cout << "YES" << endl;

		auto iter_end = first.end();

		for (int i = 0; i < n; ++i) {
			if (first.find(i) != iter_end) {
				cout << 1 << ' ';
			}
			else {
				cout << 2 << ' ';
			}
		}

	}
	else {
		cout << "NO" << endl;
	}

	cin.get();
	cin.get();
	cin.get();
	
	return 0;
}