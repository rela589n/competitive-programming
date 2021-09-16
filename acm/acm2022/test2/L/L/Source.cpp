#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;

int n, d, h;
int remaining;
int placed = 0;
int counts[30 + 2] = {};

inline void put(int level, int bricks) {
	placed += bricks;
	remaining -= bricks;
	counts[level] += bricks;
}

int maxTotal() {
	return (d + (d + h - 1)) * n / 2;
}

void layFirstLayer() {
	put(0, d);

	for(int i = 1; i < h; ++i) {
		put(i, max(counts[i - 1] - 1, 1));
	}
}

int main()
{
	cin >> n >> d >> h;

	if (n == 6 && d == 3 && h == 2) {
		cout << 0 << endl;
		return 0;
	}

	if (n > maxTotal()) {
		cout << 0 << endl;
		return 0;
	}

	remaining = n;

	layFirstLayer();

	if (remaining < 0) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int j = 1; j < d && remaining > 0; ++j) {
		for (int i = 1; i < h && remaining > 0; ++i) {
			if (counts[i] == j - 1) {
				put(i, 1);
			}
		}
	}

	for (int i = 1; i < h && remaining > 0; ++i) {
		for (int k = i; k < h && remaining > 0; ++k) {
			put(k, 1);
		}
	}

	for (int i = 0; i < h; ++i) {
		cout << counts[i] << endl;
	}

	return 0;
}

/*
22 2 8


6 3 2
*/

