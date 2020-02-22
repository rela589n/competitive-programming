#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>

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

template <class Tkey, class Tval>
class HashMap {
private:
	class HashEntry;
	HashEntry** table;
	int TABLE_SIZE;

	class HashEntry {
	private:
		Tkey key;
		Tval value;
	public:
		HashEntry(Tkey key, Tval value) {
			this->key = key;
			this->value = value;
		}

		Tkey getKey() {
			return key;
		}

		Tval& getValue() {
			return value;
		}
	};

	void init() {
		this->keys = list<Tkey>();
		table = new HashEntry * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
			table[i] = nullptr;
	}

	int (*hashFunc)(Tkey);

	static int hashDefault(Tkey key) {
		return key;
	}

	list<Tkey> keys;

public:
	HashMap(int(*setHashFunction)(Tkey) = hashDefault, int tableSize = 128) {
		this->hashFunc = setHashFunction;
		this->TABLE_SIZE = tableSize;
		init();
	}

	HashMap(int tableSize = 128, int(*setHashFunction)(Tkey) = hashDefault) {
		this->TABLE_SIZE = tableSize;
		this->hashFunc = setHashFunction;
		init();
	}

	Tval& operator [] (Tkey key) {
		int hash = (hashFunc(key) % TABLE_SIZE);

		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		if (table[hash] == nullptr) {
			table[hash] = new HashEntry(key, Tval());
			this->keys.push_back(key);
		}
		return table[hash]->getValue();
	}

	list<Tkey> getKeys() {
		return this->keys;
	}

	bool isset(Tkey key) {
		int hash = (hashFunc(key) % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		return table[hash] != nullptr;
	}

	void put(Tkey key, Tval value) {
		int hash = (hashFunc(key) % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;

		if (table[hash] != nullptr) {
			delete table[hash];
		}
		else {
			this->keys.push_back(key);
		}

		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; ++i)
			if (table[i] != nullptr)
				delete table[i];
		delete[] table;
	}
};

ll firstTwoNums(ll num) {
	while (num > 100) {
		num /= 10;
	}

	return num;
}

ll lastTwoNums(ll num) {
	return num % 100;
}

HashMap<ll, int > visitedCounts = HashMap<ll, int > (10);
HashMap<ll, int > elementCounts = HashMap<ll, int >(10);

HashMap<ll, vector<ll> > startsWith = HashMap<ll, vector<ll> >(10);
//HashMap<ll, vector<ll> > endsWith = HashMap<ll, vector<ll> >(10);

//HashMap<ll, HashMap<ll, ll> > graph = HashMap<ll, HashMap<ll, ll> >(10);

string result;

void trySolve(stringstream tail, ll start) {
	if (visitedCounts[start] >= elementCounts[start]) {
		return;
	}

	++visitedCounts[start];
	
	Forelse(i = 0; i < startsWith[lastTwoNums(start)].size(); ++i) {
		ll el = startsWith[lastTwoNums(start)][i];
		trySolve(tail << std::to_string(start / 100), el);
	}
	empty{
		tail << std::to_string(start);
	}

	--visitedCounts[start];

	string ans = tail.str();
	if (ans.size() > result.size()) {
		result = ans;
	}
}

void runProduction() {
	result = "";

	ll n;
	cin >> n;

	vector<ll> vec;

	bool only1Digits = true;
	bool only2Digits = true;

	ForI(n) {
		ll current;
		cin >> current;

		if (current > 9) {
			only1Digits = false;
		}

		if (current < 100) {
			continue;
		}

		only2Digits = false;
		vec.push_back(current);
		++elementCounts[current];

		startsWith[firstTwoNums(current)].push_back(current);
		//endsWith[lastTwoNums(current)].push_back(current);
	}

	if (only1Digits) {
		cout << 1 << endl;
		return;
	}

	if (only2Digits) {
		cout << 2 << endl;
		return;
	}

	For(i = 0; i < vec.size(); ++i) {
		trySolve("", vec[i]);
	}

	cout << result.size() << endl;
}

vector< pair<const char*, const char*> > tests =
{
	/*make_pair(multiStr(
4
123 2347 476 4723
	), "7"),*/
	make_pair(multiStr(
5
47 476 2347 123 7
	), "6"),
	make_pair(multiStr(
5
1 2 3 8 99
	), "2"),
	make_pair(multiStr(
3
333 333 334
	), "5")
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

// 333
//  333
//   334
// 12345