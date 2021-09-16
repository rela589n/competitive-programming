#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <time.h>
#include <algorithm>
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

bool _envTest_ = false;
void runProduction() {
	srand(time(NULL));
	string _str;
	getline(cin, _str);

	int n = _str.length();
	char* str = new char[n];
	strcpy(str, _str.c_str());

	vector<pair<char, int>> occ = vector<pair<char, int>>(26);
	for (int i = 0; i < occ.size(); ++i) {
		occ[i].first = i + 'a';
		occ[i].second = 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < occ.size(); ++j) {
			if (occ[j].first == str[i]) {
				++occ[j].second;
				break;
			}
		}
	}

	char p, pp;
	for (int i = 2; i < n; ++i) {
		p = str[i - 1];
		pp = str[i - 2];

		if (str[i] == p && p == pp) {
			// subst
			// asc
			std::stable_sort(occ.begin(), occ.end(), [](pair<char, int> a, pair<char, int> b) {
				return a.second < b.second;
				});

			for (int j = 0; j < occ.size(); ++j) {
				if (occ[j].first == str[i]) {
					--occ[j].second;
					break;
				}
			}

			str[i] = occ[0].first;
			++occ[0].second;
		}
	}

	// desc
	std::stable_sort(occ.begin(), occ.end(), [](pair<char, int> a, pair<char, int> b) {
		return a.second > b.second;
		});

	for (int i = 0; i < occ.size(); ++i) {
		if (occ[i].second > n / 2) {
			for (int j = n - 1; j >= 0; --j) {
				if (str[j] == occ[i].first) {
					
					for (int k = occ.size() - 2; k >= 0; --k) {
						for (int f = k + 1; f < occ.size() && occ[f].second > occ[f - 1].second; ++f) {
							swap(occ[f], occ[f - 1]);
						}

					}

					for (int as = 0; as < occ.size(); ++as) {
						if (occ[as].first == str[j]) {
							--occ[as].second;
							break;
						}
					}

					int indx = rand() % 5;

					str[j] = occ[occ.size() - indx - 1].first;
					++occ[occ.size() - 1].second;
				}
			}
		}
	}

	cout << str << endl;

	
}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
cooooode
	), "desired result")
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