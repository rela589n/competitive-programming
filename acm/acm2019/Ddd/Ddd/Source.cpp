#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long long Int;

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

	unsigned int (*hashFunc)(Tkey);

	static unsigned int hashDefault(Tkey key) {
		return key;
	}

	

public:

	list<Tkey> keys;

	HashMap(int tableSize = 128, unsigned int(*setHashFunction)(Tkey) = hashDefault) {
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


int main()
{
	ll q;
	cin >> q;

	HashMap<ll, ll> cof = HashMap<ll, ll>(2 * 1e5);

	ll b = 0;

	for (ll i = 0; i < q; ++i) {
		int o;
		cin >> o;

		if (o == 1) {
			ll a;
			cin >> a;

			if (cof.isset(a)) {
				cof[a] += 1;
			}
			else {
				cof[a] = 1;
			}
			
			ll _b;
			cin >> _b;

			b += _b;
		}
		else {
			ll res = b;

			auto endd = cof.keys.end();
			for (auto it = cof.keys.begin(); it !=endd ; ++it) {

			}
		}
	}

	// system("pause");
	return 0;
}
/*

*/