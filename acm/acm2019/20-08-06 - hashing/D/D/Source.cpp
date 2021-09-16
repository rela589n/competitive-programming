#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

#define ull unsigned long long
#define st size_t

ull P = 27;

char str[(st)1e5];

int n;

ull* powers;
ull* prefixes;
ull* rev_prefixes;

inline ull getPreHash(const st& left, const st& right) {
	ull result = prefixes[right];

	if (left > 0) {
		result -= prefixes[left - 1u];
	}

	return result;
}

inline ull getPreRevHash(const st& left, const st& right) {
	ull result = rev_prefixes[left];

	if (right < n - 1) {
		result -= rev_prefixes[right + 1];
	}

	return result;
}

inline bool isPalindrome(const st& left, const st& right) {
	return getPreHash(left, right) * powers[n - 1 - right]
		== getPreRevHash(left, right) * powers[left];
}

inline void init() {
	powers = new ull[n];
	powers[0] = 1;
	for (st i = 1; i < n; ++i) {
		powers[i] = powers[i - 1] * P;
	}

	prefixes = new ull[n];
	prefixes[0] = str[0];
	for (st i = 1; i < n; ++i) {
		prefixes[i] = prefixes[i - 1] + powers[i] * str[i];
	}

	rev_prefixes = new ull[n];
	rev_prefixes[n - 1] = str[n - 1];

	for (int i = n - 2; i >= 0; --i) {
		rev_prefixes[i] = rev_prefixes[i + 1] + str[i] * powers[n - i - 1];
	}
}


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

int hashStr(string str) {
	return std::hash<std::string>()(str) % 2147483646;
}

ull hashCharList(list<char>& lst) {
	ull hash = 0;

	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		hash += (*it) * powers[i];

		++i;
	}

	return hash;
}

int main()
{
	cin >> str;
	n = strlen(str);
	
	int evn_c = 0;

	for (int i = 0; i < n; ++i) {
		for (int off = 1; off < n && i - off >= 0; ++off) {
			
			if (str[i + off] != str[i - off]) break;
			++evn_c;
		}
	}
	/*
	int odd_c = 0;
	for (int i = 0, j = 1; i < n - 1 && j < n; ++i, ++j) {
		for (int off = 0; j + off < n && i - off >= 0; ++off) {
			if (str[i - off] != str[j + off])  break;

			++odd_c;
		}
	}
	*/

	cout << evn_c << endl;
	
	system("echo `which openssh-client`");
	return 0;
	

	init();

	st p_odd_cnt = 0;

	for (int pointLeft = 0, pointRight = 1; pointLeft < n - 1 && pointRight < n; ++pointLeft, ++pointRight) {
		int offsetInner = 0;
		int offsetOuter = min(pointLeft, n - pointRight - 1);
		int offset = 0;

		bool found = false;

		while (offsetInner <= offsetOuter) {
			offset = (offsetInner + offsetOuter) / 2;

			int leftBoundary = pointLeft - offset;
			int rightBoundary = pointRight + offset;

			if (isPalindrome(leftBoundary, rightBoundary)) {
				if (leftBoundary == 0
					|| rightBoundary == n - 1
					|| !isPalindrome(leftBoundary - 1, rightBoundary + 1)
					) {
					found = true; // there are offset + 1 palindromes
					break;
				}

				offsetInner = offset + 1;
			}
			else {
				offsetOuter = offset - 1;
			}
		}
		if (found) {
			p_odd_cnt += offset + 1;
		}
	}


	st p_evn_cnt = 0;
	for (int point = 0; point < n; ++point) {
		int offsetInner = 0;
		int offsetOuter = min(point, n - point - 1);
		int offset = 0;

		while (offsetInner <= offsetOuter) {
			offset = (offsetInner + offsetOuter) / 2;

			int leftBoundary = point - offset;
			int rightBoundary = point + offset;

			if (isPalindrome(leftBoundary, rightBoundary)) {
				if (leftBoundary == 0
					|| rightBoundary == n - 1
					|| !isPalindrome(leftBoundary - 1, rightBoundary + 1)
					) {
					// found, there are offset + 1 palindromes
					break;
				}

				offsetInner = offset + 1;
			}
			else {
				offsetOuter = offset - 1;
			}
		}

		p_evn_cnt += offset + 1;
	}

	p_evn_cnt -= n;

	cout << p_evn_cnt + p_odd_cnt << endl;
		
	//system("pause");
	return 0;
}
/*
[c[dd]c]sz[{t("t][t)(t}]t")zsf

cddcszttttzsf


*/