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

bool contains(Int source) {
	string str = to_string(source);
	
	return str.find("555") != string::npos || str.find("999") != string::npos;
}

Int n;
Int counter = 0;


void bruteForce(Int current, int depth) {
	if (depth >= n) {
		if (!(contains(current))) {
			++counter;
		}

		return;
	}

	bruteForce(current * 10 + 5, depth + 1);
	bruteForce(current * 10 + 9, depth + 1);
}

void prePrint(int _n, int _counter) {
	cout << "case " << _n << ": \n";
	cout << "	cout << " << _counter << ";\n";
	cout << "break;\n";
}

int main() {
	//cin >> n;

	int prev = 0, current = 2;
	For(i = 1; i <= 30; ++i) {
		current += prev;
		prePrint(i, current);
		prev = current - prev;
	}
	
	For(i = 1; i <= 30; ++i) {
		n = i;
		counter = 0;

		cout << "case " << n << ": \n";
		bruteForce(0, 0);
		cout << "cout << " << counter << ";\n";
		cout << "break;\n";
	}

	
	system("pause");
	return 0;
}