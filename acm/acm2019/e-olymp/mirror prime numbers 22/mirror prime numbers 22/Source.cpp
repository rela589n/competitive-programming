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


vector<bool> primes(Int to)
{
	vector<bool> isSimple(to + 1, true);

	for (Int i = 4; i <= to; i += 2) {
		isSimple[i] = false;
	}

	isSimple[0] = isSimple[1] = false;

	for (Int i = 3; i * i <= to; i += 2)
	{
		if (isSimple[i])
		{
			for (Int j = i * i; j <= to; j += i) {
				isSimple[j] = false;
			}
		}
	}

	return isSimple;
}

ll reverseNum(ll num) {
	ll result = 0, remainder;

	for (; num; num /= 10) {
		remainder = num % 10;
		result = result * 10 + remainder;
	}

	return result;
}


void runProduction() {
	/*ForI(100) {
		cout << i << " " << reverseNum(i) << endl;
	}*/

	readI(a);
	readI(b);

	//HashMap<int, bool> used((b - a) + 10);
	$ is_prime = primes((b + 1) * 10);
	
	ll counter = 0;
	For(i = a; i <= b; ++i) {
		if (!is_prime[i]) {
			continue;
		}

		ll reversed = reverseNum(i);

		if (is_prime[reversed]) {
			++counter;
		}
	}

	cout << counter << endl;
}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
10 25
	), "3"),
	make_pair(multiStr(
11 11
	), "1"),
	make_pair(multiStr(
12 13
	), "1"),
	make_pair(multiStr(
14 16
	), "0"),
	make_pair(multiStr(
1 100
	), "13"),
	make_pair(multiStr(
10 99
	), "9"),
	make_pair(multiStr(
1 2
	), "1"),
	make_pair(multiStr(
1 10000
	), "140")
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

