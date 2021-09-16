#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;

ll n;
ll h[100000 + 2];

unordered_map<ll, int> counts;
unordered_map<ll, int> processed_high_counts;
unordered_map<ll, int> processed_low_counts;

inline void addOut(ll low, ll high) {
	++processed_low_counts[low];
	++processed_high_counts[high];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	scanf("%i", &n);

	counts.reserve(n * 2 + 16);
	processed_high_counts.reserve(n + 16);
	processed_low_counts.reserve(n + 16);

	for (int i = 0; i < n; ++i) {
		scanf("%i", &h[i]);
		++counts[h[i]];
	}

	for (int i = 0; i < n; ++i) {
		ll el = h[i];

		if (processed_high_counts[el] + processed_low_counts[el] == counts[el]) {
			continue;
		}

		ll lower = el * 75 / 100;
		ll higher = el * 100 / 75;

		addOut(el, higher);
		printf("%i\n", el);
	}

	return 0;
}
/*
8
5625 5625 7500 7500 7500 7500 10000 10000
5625 5625 7500 7500

6
30
40
42
45
56
60

*/