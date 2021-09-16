#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

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

#define use(space) using namespace space

inline int max(int& a, int& b) {
	return a > b ? a : b;
}

use(std);

#define N 1000
$ mx = _matrix(N + 1, N + 1, int);

void bootstrap() {
	ForI(N + 1) {
		mx[i][1] = i;
		mx[1][i] = 1;
	}

	For(i = 2; i < N + 1; ++i) {
		// center of building
		int bestPoint = (i + 1) >> 1;

		For(j = 2; j < N + 1; ++j) {

			// best case is when we have unlimited amount of eggs and we would drop egg from center of building
			int point = bestPoint;
			int val = 1 + max(mx[point - 1][j - 1], mx[i - point][j]);
			
			--point;

			int endPoint = mx[i - 1][j];
			for (; point >= endPoint; --point) {
				int newVal = 1 + max(mx[point - 1][j - 1], mx[i - point][j]);
				if (val >= newVal) {
					val = newVal;
				}
				else {
					break;
				}
			}

			mx[i][j] = val;
		}
	}
}

void runProduction() {
	for (;;) {
		int a, b;
		scanf("%i %i", &a, &b);

		if (a == 0 || b == 0) {
			break;
		}

		printf("%i\n", mx[b][a]);
	}
}

int main() {
	bootstrap();

	runProduction();
	return 0;
}