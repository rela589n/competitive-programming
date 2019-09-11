#include <iostream>
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

bool desc(const pair<Int, Int>& a, const pair<Int, Int>& b) {
	return a.first + a.second > b.first + b.second;
}

inline int max3(int a, int b, int c)
{
	int ret = a;
	if (ret < b) ret = b;
	if (ret < c) ret = c;
	return ret;
}

int f[16][16] = {};

int main() {
	int white, black;
	$ run = 15;

	while (cin >> white >> black) {			
		For(i = run; i >= 1; --i) {
			For(j = run; j >= 1; --j) {
				f[i][j] = max3(f[i][j], f[i][j - 1] + white, f[i - 1][j] + black);
			}
		}

		For(k = run; k >= 1; --k) {
			f[0][k] = max(f[0][k], f[0][k - 1] + white);
			f[k][0] = max(f[k][0], f[k - 1][0] + black);
		}
	}

	cout << f[15][15] << endl;
	
	//system("pause");
	return 0;
}
/*
87 84
66 78
86 94
93 87
72 100
78 63
60 91
77 64
77 91
87 73
69 62
80 68
81 83
74 63
86 68
53 80
59 73
68 70
57 94
93 62
74 80
70 72
88 85
75 99
71 66
77 64
81 92
74 57
71 63
82 97
76 56


87      84
--------------------
0       84      84
87      87      87
87      87      87

66      78
--------------------
0       84      162
87      165     165
153     165     165

86      94
--------------------
0       94      178
87      181     259
173     251     259

93      87
--------------------
0       94      181
93      187     271
180     274     352

72      100
--------------------
0       100     194
93      193     287
180     280     374

78      63
--------------------
0       100     194
93      193     287
180     280     374

60      91
--------------------
0       100     194
93      193     287
180     280     374

77      64
--------------------
0       100     194
93      193     287
180     280     374

*/