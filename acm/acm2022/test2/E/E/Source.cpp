#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;

ll n;
ll h[100000 + 2];

int r_start[100000 + 2];
int r_end[100000 + 2];

int routes = 0;

inline void push(int l, int r) {
	r_start[routes] = l;
	r_end[routes] = r;
	++routes;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	for (int i = 0; i < n - 2; ++i) {
		if (h[i] < h[i + 1]) {
			for (int j = i + 2; j < n; ++j) {
				if (h[j - 1] > h[j]) {
					push(i, j);
					break;
				}
			}
		}
	}


	int smallest_len = INF;

	int sm_l, sm_r;
	

	for (int i = 0; i < routes; ++i) {
		int len = r_end[i] - r_start[i];

		if (len < smallest_len) {
			smallest_len = len;
			sm_l = r_start[i];
			sm_r = r_end[i];
		}
	}

	if (smallest_len == INF) {
		cout << 0 << endl;
	}
	else {
		cout << (sm_l + 1) << " " << (sm_r + 1) << endl;
	}


	return 0;
}
/*

7
18
10
15
20
20
10
3

3
9
8
5
*/
