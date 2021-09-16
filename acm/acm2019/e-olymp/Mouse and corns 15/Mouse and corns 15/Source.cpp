#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

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
//#define empty bool __flag_forelse_copy = _flag_forelse; _flag_forelse = true;  if(!__flag_forelse_copy)
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

bool _envTest_ = false;
void runProduction() {
	readI(n);
	readI(m);

	$ mx = matrix(n, m);
	read_matrix(mx);

	For(j = 1; j < mx[0].size(); ++j) {
		mx[mx.size() - 1][j] += mx[mx.size() - 1][j - 1];
	}

	For(i = mx.size() - 2; i >= 0; --i) {
		mx[i][0] += mx[i + 1][0];
	}

	For(i = mx.size() - 2; i >= 0; --i) {
		For(j = 1; j < mx[i].size(); ++j) {
			mx[i][j] += max(mx[i + 1][j], mx[i][j - 1]);
		}
	}

	stack<char> result;
	
	ll i = 0, j = mx[i].size() - 1;
	while (i < mx.size() - 1 || j > 0) {
		ll val = mx[i][j];
		ll bott = (i < mx.size() - 1) ? mx[i + 1][j]: -1;
		ll left = (j > 0) ? mx[i][j - 1] : -1;

		if (bott > left) {
			result.push('F');
			++i;
		}
		else {
			result.push('R');
			--j;
		}
	}

	while (!result.empty()) {	
		cout << result.top();
		result.pop();
	}

}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
2 3
3 2 4
1 5 1
	), "RFR")
};

void runTests() {
	streambuf* orig = std::cin.rdbuf();
	{
		ForI(tests.size()) {
			istringstream myinput(tests[i].first);
			cin.rdbuf(myinput.rdbuf());

			cout << tests[i].first << endl;
			runProduction();
			cout << " => " << tests[i].second << endl;
		}
	}
	cin.rdbuf(orig);
}

int main() {
	if (_envTest_) {
		runTests();
		system("pause");
		return 0;
	}

	runProduction();
	return 0;
}
