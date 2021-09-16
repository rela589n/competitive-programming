#include<bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll n;
ll m;
vector<ll> arN = vector<ll>((int)1e6, 0);
vector<ll> arM = vector<ll>((int)1e6, 0);

inline double Q_rsqrt(double number, double eps = 0.005) {
	if (number < 0)
		return -1;
	double l = 0, r = number;
	while (r - l > eps) {
		long double center = (r + l) / 2.;
		if (center * center < number) {
			l = center;
		}
		else if (center * center > number) {
			r = center;
		}
		else {
			l = r = center;
		}
	}
	return l + eps;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arN[i];
	}

	for (int j = 0; j < m; ++j) {
		cin >> arM[j];
	}

	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum += (ll)(Q_rsqrt(abs(arN[i] - arM[j])));
		}
	}

	cout << sum << endl;


	return 0;
}
/*
1 2 1 2 3
*/