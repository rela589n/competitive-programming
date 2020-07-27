#include <iostream>
#include <list>
using namespace std;



#define ll long long
#define Int long long

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
			
			if (table[hash] != nullptr){
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


ll gcd(ll a, ll b)
{
  while(a && b){
    if (a > b) {
      a %= b;
    }
    else {
      b %= a;
    }
  }

  return a + b;

}

int main()
{
  ll g = 0;

  while (true) {
    ll n;
    cin >> n;
    if (n == 0) break;

    for (ll i = 1; i < n; ++i) {
      for (ll j = i + 1; j < n; ++j) {
        g += gcd(i,j);
      }
    }
  }
  cout << g;

  return 0;
}
