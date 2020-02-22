#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define ForParam(iter, start, size) Int __for_size = size; For(iter = start; iter < __for_size; ++iter)
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

use(std);

vector< vector<ll> > mx;
ll counter = 0;
ll k;

ll resultRow =  -2;
ll resultCol = -2;

// 1 2 3 4
void traverseMx(int direction, Int row, Int col) {
	if (row >= mx.size()) {
		return;
	}

	if (col >= mx[0].size()) {
		return;
	}

	if (mx[row][col]) {
		return;
	}

	mx[row][col] = ++counter;
	if (counter == k) {
		resultRow = row;
		resultCol = col;
		return;
	}

	switch (direction)
	{
	case 1:
		if (col == mx[0].size() - 1 || mx[row][col + 1]) {
			traverseMx(2, row + 1, col);
			return;
		}

		traverseMx(1, row, col + 1);
		break;
	case 2:
		if (row == mx.size() - 1 || mx[row + 1][col]) {
			traverseMx(3, row, col - 1);
			return;
		}
		
		traverseMx(2, row + 1, col);
		break;
	case 3:
		if (col == 0 || mx[row][col - 1]) {
			traverseMx(4, row - 1, col);
			return;
		}

		traverseMx(3, row, col - 1);
		break;
	case 4:
		if (row == 0 || mx[row - 1][col]) {
			traverseMx(1, row, col + 1);
			return;
		}

		traverseMx(4, row - 1, col);
		break;
	}
}

void runProduction() {
	readI(cols);
	readI(rows);
	cin >> k;

	mx = matrix(rows, cols);

	resultRow = -2;
	resultCol = -2;
	traverseMx(1, 0, 0);
	cout << resultCol + 1 << " " << resultRow + 1 << endl;
}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
4 5
20
	), "2 3"),
		make_pair(multiStr(
4 5
223
	), "-1 -1")
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

bool _envTest_ = false;
int main() {
	if (_envTest_) {
		runTests();
		system("pause");
		return 0;
	}

	runProduction();
	return 0;
}
