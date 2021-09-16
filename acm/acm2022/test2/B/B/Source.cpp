#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;

ll xSW, ySW;
ll xW, yW;
ll xNW, yNW;
ll xN, yN;
ll xNE, yNE;
ll xE, yE;
ll xSE, ySE;
ll xS, yS;

ll x, y;


ll dist(ll x1, ll y1, ll x2, ll y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> xSW >> ySW >> xNE >> yNE >> x >> y;

	xSW *= 10;
	ySW *= 10;
	xNE *= 10;
	yNE *= 10;
	x *= 10;
	y *= 10;

	xNW = xSW;
	yNW = yNE;

	xSE = xNE;
	ySE = ySW;

	xW = xSW;
	yW = (ySW + yNW) / 2;

	xN = (xNW + xNE) / 2;
	yN = yNE;

	xE = xNE;
	yE = yW;

	xS = xN;
	yS = ySW;

	ll dSW = dist(x, y, xSW, ySW);
	ll dW = dist(x, y, xW, yW);
	ll dNW = dist(x, y, xNW, yNW);
	ll dN = dist(x, y, xN, yN);
	ll dNE = dist(x, y, xNE, yNE);
	ll dE = dist(x, y, xE, yE);
	ll dSE = dist(x, y, xSE, ySE);
	ll dS = dist(x, y, xS, yS);

	ll arr[] = { dSW,dW,dNW,dN,dNE,dE,dSE,dS, };

	int minIndex = 0;
	for (int i = 0; i < 8; ++i) {
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}

	if (minIndex == 0) {
		if (x < xSW) {
			if (y < ySW) {
				cout << "SW" << endl;
			}
			else {
				cout << "W" << endl;
			}
		}
		else {
			cout << "S" << endl;
		}
	}

	if (minIndex == 1) {
		cout << "W" << endl;
	}

	if (minIndex == 2) {

		if (x < xNW) {
			if (y > yNW) {
				cout << "NW" << endl;
			}
			else {
				cout << "W" << endl;
			}
		}
		else {
			cout << "N" << endl;
		}
	}

	if (minIndex == 3) {
		cout << "N" << endl;
	}

	if (minIndex == 4) {

		if (x > xNE) {
			if (y > yNE) {
				cout << "NE" << endl;
			}
			else {
				cout << "E" << endl;
			}
		}
		else {
			cout << "N" << endl;
		}
	}


	if (minIndex == 5) {
		cout << "E" << endl;
	}

	if (minIndex == 6) {
		if (x > xSE) {
			if (y < ySE) {
				cout << "SE" << endl;
			}

			else {
				cout << "E" << endl;
			}
		}
		else {
			cout << "S" << endl;
		}
	}

	if (minIndex == 7) {
		cout << "S" << endl;
	}

	return 0;
}
