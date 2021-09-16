#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long

#define $ auto

using namespace std;

int main() {

	ll n, k, m;
	cin >> n >> k >> m;


	for (ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
	}

	ll countFilled = 0;

	int currentRun = 1;

	ll r = n * k;

	$ vec = vector<ll>(r);

	$ isPrinted = vector<bool>(k + 3, false);

	$ result = vector<int>(r, 0);

	$ map = vector<int>(r + 3, 0);

	for (ll i = 0; i < r; ++i) {
		cin >> vec[i];

		++map[vec[i]];

		if (map[vec[i]] == 1) {
			++countFilled;
		}

		if (countFilled == k) {

			ll countPrinted = 0;

			for (ll j = 0; j < r && countPrinted != k; ++j) {

				if (result[j] != 0 || isPrinted[vec[j]]) {
					continue;
				}

				isPrinted[vec[j]] = true;

				result[j] = currentRun;

				++countPrinted;
			}

			// assign false to all isPrinted values;
			for (ll j = 0; j < k; ++j) {
				isPrinted[j] = false;
			}

			// decrease jobs count of one run
			for (ll j = 0; j < k; ++j) {
				map[j] -= 1;
			}

			countFilled = 0;
			++currentRun;
		}
	}


	for (ll i = 0; i < r; ++i) {
		cout << result[i] << endl;
	}

	return 0;
}

/*

3 3 2
1 2
1 3
1 1 2 3 3 2 1 2 3

*/