#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;


int c = '#';
int f = '.';

ll s;
ll n, m;

int h[1000 + 2][1000 + 2];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	cin.get();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char tmp;
			cin >> tmp;
			h[i][j] = tmp;
		}
	}

	ll t = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (h[i][j] == c) {
				continue;
			}

			if (i - 1 >= 0 && h[i - 1][j] == f) {
				++t;
			}

			if (j - 1 >= 0 && h[i][j - 1] == f) {
				++t;
			}
		}
	}

	cout << t << endl;

	return 0;
}

/*
3 2
..
..
..

3 4
..#.
#..#
..#.
*/