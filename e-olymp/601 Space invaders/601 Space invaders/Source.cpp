#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define ForParam(iter, size) Int __for_size = size; For(iter = 0; iter < __for_size; ++iter)
#define ForI(n) ForParam(i, n)
#define ForJ(m) ForParam(j, m)
#define ForK(l) ForParam(k, l)

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

#define _Vector(size, type) vector<type> (size)
#define Vector(size) _Vector(size, ll)
#define read_vector(vector) ForI(vector.size()) cin >> vector[i];
#define use(space) using namespace space

#define print_vector(vec, delim) ForI(vec.size()) { cout << vec[i] << delim; }

use(std);

int main() {
	readI(n);
	readI(pos);
	--pos;

	$ ln = Vector(n);
	read_vector(ln);

	ll counter = 0;
	if (pos > (n >> 1)) {
		For(i = pos; i < n; ++i, ++counter) {
			for(; ln[i] > 1; ++counter, --ln[i]);
		}
	}
	else {
		For(i = pos; i >= 0; --i, ++counter) {
			for (; ln[i] > 1; ++counter, --ln[i]);
		}
	}

	For(i = 0; i < n; ++i, ++counter) {
		for (; ln[i] > 0; ++counter, --ln[i]);
	}

	cout << counter;

	system("pause");
	return 0;
}