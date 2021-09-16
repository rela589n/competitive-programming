#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ld n;
ld p;
ld s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> s;

	ld now = n + n * p / 100.;

	cout << (ll)(s / now);

	return 0;
}
