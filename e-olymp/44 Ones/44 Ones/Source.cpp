#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define forI(n) For(i = 0; i < n; ++i)
#define forJ(m) For(j = 0; j < m; ++j)
#define forK(l) For(k = 0; k < l; ++k)

#define Forelse(loop) forelse(Int loop)
#define forelse(loop) _flag_forelse = false; for (loop, _flag_forelse=true)
#define empty bool __flag_forelse_copy = _flag_forelse; _flag_forelse = true;  if(!__flag_forelse_copy)

#define readI(var) Int var; cin >> var;
#define readF(var) double var; cin >> var;
#define readD(var) dbl var; cin >> var;

#define unless(condition)if(!condition)

#define $ auto
#define mkarr(size, type) new Int[size];
#define _matrix(rows, cols, type) vector<vector<type>>(rows, vector<type>(cols))
#define matrix(rows, cols) _matrix(rows, cols, Int)

#define _line(size, type) vector<type> (size)
#define line(size) _line(size, ll)
#define use(space) using namespace space

#define print_vector(vec, delim) forI(vec.size()) { cout << vec[i] << delim; }

use(std);


Int n, counter;

bool isPowerOf2(Int num) {
	return (num & (num - 1)) == 0 && num != 0;
}

bool isPrime(Int num) {
	For(i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

bool checkCoefs(vector<ll>& trace, vector<ll>& sequence, ll offset) {
	ll result = 0;
	for (ll i = 0; i < trace.size(); ++i) {

		result += trace[i] * sequence[i + offset];
	}

	return result == sequence[trace.size() + offset];
}

void findCoefsRecursive(vector<ll>& trace, vector<ll>& sequence, ll elementIndex, ll depth, ll& coefMin, ll& coefMax) {
	if (depth >= elementIndex) {
		for (ll offset = 0; offset < sequence.size() - trace.size(); ++offset) {
			if (!checkCoefs(trace, sequence, offset)) {
				return;
			}
		}

		print_vector(trace, " ");
		cout << endl << endl;
		return;
	}

	for (ll i = coefMin; i < coefMax; ++i) {
		trace[depth] = i;
		findCoefsRecursive(trace, sequence, elementIndex, depth + 1, coefMin, coefMax);
	}
}

/// find probable formula for given sequence
void findCoefs(vector<ll>& sequence, ll elemIndex, ll coefMin = -10, ll coefMax = 10) {
	vector<ll> trace = vector<ll>(elemIndex);
	findCoefsRecursive(trace, sequence, elemIndex, 0, coefMin, coefMax);
	cout << "finished" << endl;
}

void solve(ll n) {
	$ dyn = line(n + 3);
	dyn[1] = 1;
	dyn[2] = 2;
	dyn[3] = 3;

	For(i = 4; i <= n; ++i) {
		dyn[i] = dyn[i - 1] + 1;

		For(j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				ll k = dyn[i / j] + dyn[j];
				
				if (k < dyn[i]) {
					dyn[i] = k;
				}
			}
		}
	}

	cout << dyn[n];
	dyn.clear();
}

int main() {
	cin >> n;

	solve(n);
	

	// 4 + 3
	//cout << solve(n) << endl;

	// (1 + 1) * (1 + 1)
	// (2 * 2) * (2 * 2)
	// (1 + 1) * (1 + 1) * (1 + 1)
	//system("pause");
	return 0;
}

