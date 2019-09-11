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

void runProduction() {
	readI(n);
	$ nums = Vector(n + 2);
	_read_vector(nums, 1, n + 1);

	readI(k);

	For(i = 1; i < nums.size(); ++i) {
		$ maxVal = nums[i - 1];
		For(j = i - 2; j >= max(i - k, 0ll); --j) {
			maxVal = max(maxVal, nums[j]);
		}

		nums[i] += maxVal;
	}

	cout << nums[n + 1] << endl;
}

vector< pair<const char*, const char*> > tests =
{ 
	make_pair(multiStr(
3\n
100 -11 5\n
2\n
	), "105")
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

bool _envTest_ = true;
int main() {
	if (_envTest_) {
		runTests();
		system("pause"); 
		return 0;
	}

	runProduction();
	return 0;
}