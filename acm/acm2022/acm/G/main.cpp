#include <bits/stdc++.h>
#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define __COMMA__ ,
#define ForParam(iter, start, size)  For(iter = start __COMMA__ __for_size = size; iter < __for_size; ++iter)
#define ForI(n) ForParam(i, 0, n)
#define ForJ(m) ForParam(j, 0, m)
#define ForK(l) ForParam(k, 0, l)

#define forelse(loop) _flag_forelse = false; for (loop, _flag_forelse=true)
#define empty bool __flag_forelse_copy = _flag_forelse; _flag_forelse = true;  if(!__flag_forelse_copy)
#define Forelse(loop) forelse(Int loop)

#define readI(var) Int var; cin >> var;
#define readF(var) double var; cin >> var;
#define readD(var) dbl var; cin >> var;

#define unless(condition)if(!condition)

#define $ auto
#define mkarr(size, type) new Int[size];
#define _matrix(rows, cols, type) vector<vector<type>>(rows, vector<type>(cols))
#define matrix(rows, cols) _matrix(rows, cols, Int)

#define _Vector(size, type) vector<type> (size)
#define Vector(size) _Vector(size, ll)

#define _read_vector(vec, start, end) ForParam(i, start, end) cin >> vec[i];
#define read_vector(vec) _read_vector(vec, 0, vec.size())
#define print_vector(vec, delim) ForI(vec.size()) { cout << vec[i] << delim; }
#define multiStr(a) #a

#define read_matrix(vec) ForI(vec.size()) { ForJ(vec[i].size()) { cin >> vec[i][j]; } }

#define use(space) using namespace space

use(std);

using namespace std;

	bool checkCoefs(vector<ll>& trace, vector<ll>& sequence, ll offset) {
		ll result = 0;
		for (ll i = 0; i < trace.size(); ++i) {

			result += trace[i] * sequence[i + offset];
		}

		return result == sequence[trace.size() + offset];
	}

	void findCoefsRecursive(vector<ll> &trace, vector<ll>& sequence, ll elementIndex, ll depth, ll & coefMin, ll& coefMax) {
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

ll n;

int main()
{
    cin >> n;



    return 0;
}
