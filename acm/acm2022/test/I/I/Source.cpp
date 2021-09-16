#include <bits/stdc++.h>

#define ll long long

using namespace std;

// 0 - distance, 1 - start time, 2 - end time
ll* rp[2 * 100000 + 1] = { };

ll n, q;

inline bool cmp(ll* a, ll* b) {
	return *(a + 1) < *(b + 1);
}


int bisect(ll d) {
	int l = 0;
	int r = n - 1;
	bool found = false;

	while (l <= r) {
		int c = (l + r) >> 1;
		
		ll shiftedDistance = (d + rp[c][0]) * 10;

		ll t0 = rp[c][1] * 10 - 5;
		ll t1 = rp[c][2] * 10 - 5;

		if (t0 <= shiftedDistance && shiftedDistance <= t1) {
			l = r = c;
			found = true;
			break;
		}

		if (shiftedDistance > t1) {
			l = c + 1;
		}
		else if (shiftedDistance < t0) {
			r = c - 1;
		}
		else {
			throw "something went wrong";
		}
	}

	if (found) {
		return l;
	}

	return -1;
}

int bisearch(ll d) {
	int l = 0;
	int r = n - 1;

	while (l < r) {
		int c = (l + r) >> 1;

		ll shift = rp[c][0];
		ll start = rp[c][1];
		ll end = rp[c][2];

		ll dist = (d + shift);

		if (start * 10 - 5 <= dist * 10 
			&& dist * 10 <= end * 10 - 5) {
			
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;

	for (ll i = 0; i < n; ++i) {
		rp[i] = new ll[3];
		cin >> rp[i][1] >> rp[i][2] >> rp[i][0];
	}

	sort(rp, rp + n, cmp);

	for (ll i = 0; i < q; ++i) {
		ll d;
		cin >> d;

		bool stopped = false;
		ll dist;
		ll t0;
		ll t1;

		int idx = bisect(d);

		if (idx == -1) {
			cout << -1 << endl;
		}
		else {
			cout << rp[idx][0] << endl;
		}
	}

	return 0;
}
/*
2 5
1 10 1

0
1
2
3
10


4 6
1 3 2
7 13 10
18 20 13
3 4 2
0
1
2
3
5
8


2
2
10
-1
13
-1



*/