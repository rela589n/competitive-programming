#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>

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


	HashMap(int tableSize = 128, int(*setHashFunction)(Tkey) = hashDefault) {		
		this->hashFunc = setHashFunction;
		this->TABLE_SIZE = tableSize;
		init();
	}

	Tval& get(Tkey key) {
		return (*this)[key];
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



bool checkCoefs(vector<ll>& trace, vector<ll>& sequence, ll offset) {
	ll result = 0;
	for (ll i = 0; i < trace.size(); ++i) {

		result += trace[i] * sequence[i + offset];
	}

	return result == sequence[trace.size() + offset];
}

void findCoefsRecursive(vector<ll>& trace, vector<ll>& sequence, ll elementIndex, ll depth, ll& coefMin, ll& coefMax) {
	if (depth >= elementIndex) {
		for (ll offset = 0; offset < sequence.size() - trace.size(); ++offset) {
			if (!checkCoefs(trace, sequence, offset)) {
				return;
			}
		}

		print_vector(trace, " ");
		cout << endl << endl;
		return;
	}

	for (ll i = coefMin; i < coefMax; ++i) {
		trace[depth] = i;
		findCoefsRecursive(trace, sequence, elementIndex, depth + 1, coefMin, coefMax);
	}
}

/// find probable formula for given sequence
void findCoefs(vector<ll>& sequence, ll elemIndex, ll coefMin = -10, ll coefMax = 10) {
	vector<ll> trace = vector<ll>(elemIndex);
	findCoefsRecursive(trace, sequence, elemIndex, 0, coefMin, coefMax);
	cout << "finished" << endl;
}

class Solve {

public:

	HashMap<int, bool> *is_isset;

	ll counter;

	vector<int> vals;

	void saveResult(vector<int>& trace) {
		ll sum = 0;
		ForI(trace.size()) {
			sum += trace[i];
		}

		if (!is_isset->get(sum)) {
			++counter;
		}

		is_isset->put(sum, true);

	}

	void buildNumbers(vector<int>& trace, int level, int currentValue) {
		if (level >= trace.size()) {
			return;
		}

		trace[level] = currentValue;
		ForI(vals.size()) {
			buildNumbers(trace, level + 1, vals[i]);
			saveResult(trace);
		}
	}

	void run() {
		delete is_isset;
		is_isset = new  HashMap<int, bool>(10000);
		is_isset->put(0, true);

		vals = vector<int>{
		1,
		5,
		10,
		50
		};
		
		counter = 0;

		readI(n);

		$ trace = vector<int>(n, 0);

		ForI(vals.size()) {
			buildNumbers(trace, 0, vals[i]);
		}

		cout << counter << endl;
	}


};

vector<int> mult(vector<int>a1, vector<int >a2)
{
	set<int >a3;
	vector<int > a4;

	for (int e = 0; e < a1.size(); e++)
	{
		for (int f = 0; f < a2.size(); f++)
		{
			a3.insert(a1[e] + a2[f]);
		}
	}
	for (set<int> ::iterator it = a3.begin(); it != a3.end(); it++)
	{
		a4.push_back(*it);
	}
	return(a4);
}

vector<int > az = vector<int>{
	1, 5, 10, 50
};

vector<int> recur(int n)
{
	if (n == 1)
		return az;

	vector<int> a1 = recur(n / 2);
	vector<int> a2 = mult(a1, a1);

	if (n % 2 == 1)
		a2 = mult(a2, az);
	
	return a2;
}


void runProduction() 
{

	int a[] = { 0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390, 439 };
	readI(n);
	if (n < 18) {
		cout << a[n] << endl;
	}
	else {
		cout << (292ll + (n - 11ll) * 49ll) << endl;
	}
	/*
	Solve* solve = new Solve();
	solve->run();
	delete solve;
	*/
}

vector< pair<const char*, const char*> > tests =
{
	make_pair(multiStr(
1
	), "4"),
	
};

void mockProduction(string input) {
	istringstream myinput(input);
	cin.rdbuf(myinput.rdbuf());

	cout << input << endl;
	runProduction();
}

void runTests() {
	streambuf* orig = std::cin.rdbuf();
	{
		ForI(tests.size()) {
			mockProduction(tests[i].first);
			cout << " => " << tests[i].second << endl;
		}
	}
	cin.rdbuf(orig);
}

bool _envTest_ = false;
int main() {
	if (_envTest_) {

	
		
		
		vector<ll> part = vector<ll>
		{
0  ,
4  , // 0  * x + 0
10 , // 0  * x + 0
20 , // 0  * x + 0
35 , // 0  * x + 0
56 , // 0  * x + 0
83 , // 0  * 2 + 1
116, // 1  * 2 + 2
155, // 4  * 2 + 2
198, // 10 * 2 + 2
244, // 20 * 2 + 2
292, // 35 * 2 + 2
341, // 56 * 2 + 2
390, // 84 * 2 + 2
439 // 120 * 2  1
		};
		
		//findCoefs(part, 6, -10, 50);

		For(i = 1; i < 30; ++i) {
			mockProduction(to_string(i));
			cout << endl;
		}

		//runTests();
		system("pause");
		return 0;
	}

	runProduction();
	return 0;
}


