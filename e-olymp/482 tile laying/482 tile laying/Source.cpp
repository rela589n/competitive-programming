#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define forI(n) For(a = 0; a < n; ++a)
#define forJ(m) For(c = 0; c < m; ++c)
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

#define matrixT(type) vector<vector<type>>
#define print_vector(vec, delim) For(____i = 0; ____i < vec.size(); ++____i) { cout << vec[____i] << delim; }

use(std);

ll n;
ll counter = 0;

void brute(ll level, bool first, bool second, bool third) {
	if (level >= n - 1) {
		++counter;
		return;
	}
	
	if (!first && !second && !third) {

		brute(level + 1, true, false, false);
		brute(level + 1, false, false, true);
		brute(level + 2, false, false, false);
	}
	else if (first && second) {
		
		brute(level + 1, false, false, true);
	}
	else if (second && third) {
		
		brute(level + 1, true, false, false);
	}
	else if (first) {

		brute(level + 1, false, true, true);
		brute(level + 1, false, false, false);
	}
	else if (third) {
		
		brute(level + 1, true, true, false);
		brute(level + 1, false, false, false);
	}
}

/*
1
3
11
41
153

*/

void printResult(Int n) {
	switch (n) {
	case 0:
		cout << 1 << endl;
		break;
	case 1:
		cout << 0 << endl;
		break;
	case 2:
		cout << 3 << endl;
		break;
	case 3:
		cout << 0 << endl;
		break;
	case 4:
		cout << 11 << endl;
		break;
	case 5:
		cout << 0 << endl;
		break;
	case 6:
		cout << 41 << endl;
		break;
	case 7:
		cout << 0 << endl;
		break;
	case 8:
		cout << 153 << endl;
		break;
	case 9:
		cout << 0 << endl;
		break;
	case 10:
		cout << 571 << endl;
		break;
	case 11:
		cout << 0 << endl;
		break;
	case 12:
		cout << 2131 << endl;
		break;
	case 13:
		cout << 0 << endl;
		break;
	case 14:
		cout << 7953 << endl;
		break;
	case 15:
		cout << 0 << endl;
		break;
	case 16:
		cout << 29681 << endl;
		break;
	case 17:
		cout << 0 << endl;
		break;
	case 18:
		cout << 110771 << endl;
		break;
	case 19:
		cout << 0 << endl;
		break;
	case 20:
		cout << 413403 << endl;
		break;
	case 21:
		cout << 0 << endl;
		break;
	case 22:
		cout << 1542841 << endl;
		break;
	case 23:
		cout << 0 << endl;
		break;
	case 24:
		cout << 5757961 << endl;
		break;
	case 25:
		cout << 0 << endl;
		break;
	case 26:
		cout << 21489003 << endl;
		break;
	case 27:
		cout << 0 << endl;
		break;
	case 28:
		cout << 80198051 << endl;
		break;
	case 29:
		cout << 0 << endl;
		break;
	case 30:
		cout << 299303201 << endl;
		break;
	}
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
	cout << "finished";
}

int main() {
	Int test = 0;
	while (true) {
		cin >> test;

		if (~test) {
			printResult(test);
			continue;
		}
		
		break;
	}

	return 0;

	for (n = 1; n <= 30; ++n) {
		cout << "case " << n << ':' << endl;

		cout << "\tcout << ";
		if (n & 1) {
			cout << 0;
		}
		else {
			counter = 0;
			brute(0, false, false, false);
			cout << counter;
		}
		cout << " << endl;" << endl;

		cout << "\tbreak;" << endl;
	}
	
	//system("pause");
	return 0;
}