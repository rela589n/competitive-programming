#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define ForI(n) For(i = 0; i < n; ++i)
#define ForJ(m) For(j = 0; j < m; ++j)
#define ForK(l) For(k = 0; k < l; ++k)

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



int main() {
	readI(n);

	cin.get();
	$ mx = _matrix(n, n, int);
	ForI(n) {
		ForJ(n) {
			char c;
			scanf("%c", &c, 1);
			
			cout << c - 48;
			//cin >> mx[i][j];
		}
	}

	For(i = 1; i < n; ++i) {
		mx[0][i] += mx[0][i - 1];
		mx[i][0] += mx[i - 1][0];
	}

	For(i = 1; i < n; ++i) {
		For(j = 1; j < n; ++j) {
			mx[i][j] += min(mx[i - 1][j], mx[i][j - 1]);
		}
	}

	ForI(n) {
		print_vector(mx[i], " ");
		cout << endl;
	}

	system("pause");
	return 0;
}