#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;


ll s;
ll n;
ll h[100000 + 2];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	cin >> n;

	ll w1 = 0, w2 = 0;

	for (int i = 0; i < n; ++i) {
		cin >> h[i];

		if (w1 + h[i] > s) {
			w2 += h[i];
		}
		else {
			w1 += h[i];
		}
	}

	cout << w1 << " " << w2 << endl;

	return 0;
}
