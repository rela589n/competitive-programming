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

use(std);

int main() {


	readI(n);
	$ arr = matrix(n + 1, n);
	
	For (i = 1; i <= n; ++i) {
		For (j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}		
	}

	For (i = 1; i <= n; ++i) {
		For (j = 0; j < n; ++j) {
			arr[i][j] += arr[i - 1][j];
		}
	}

	ll result = -1;

	For (i = 1; i <= n; ++i) {
		For (j = i; j <= n; ++j) {
			ll t = 0;
			forK(n) {
				t += arr[j][k] - arr[i - 1][k];
				if (t < 0) 
					t = 0;
				result = max(result, t);
			}
		}
	}

	cout << result << endl;
	

	//system("pause");
	return 0;
}