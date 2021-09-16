#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

typedef long long Int;
const long long INF = 2147483647;

using namespace std;

Int maxSubArrayCost(vector<Int> &arr, vector<Int> &costs) {
	Int n = arr.size() - 1;
	Int m = costs.size() - 1;

	vector< bool > used(m + 1, false);

	// fix the last iteration
	arr[n] = m;
	used[m] = true;

	Int l = 0,
		r = 0,
		sum = costs[arr[0]],
		maxCost = sum;

	used[arr[0]] = true;

	while (l < n - 1) {
		while (!used[arr[r + 1]]) {
			++r;
			used[arr[r]] = true;
			sum += costs[arr[r]];
		}
		maxCost = max(maxCost, sum);

		// right pointer not changed, but left cught up with him
		if (l == r) {
			Int elem = arr[l];

			while (arr[r + 1] == elem) {
				++r;
			}
			l = r;

			continue;
		}

		++l;
		used[arr[l - 1]] = false;
		sum -= costs[arr[l - 1]];
	}

	return maxCost;
}

template <class T>
class SegmentTree {
public:
	SegmentTree(vector<T>& arr, T(*func)(const T& a, const T& b), T defaultVal) {
		len = arr.size();

		// if len is the power of 2
		if (len && !(len & (len - 1))) {
			p_arr.assign(len << 1, defaultVal);
		}
		else {
			p_arr.assign(len << 2, defaultVal);
		}

		this->operation = func;

		__create(arr, 0, 0, len - 1);
	}

	Int len;
	vector<T> p_arr;
	T(*operation)(const T& a, const T& b);

	T get_segment(Int l, Int r) {
		return __get_segment(0, 0, len - 1, l, r);
	}

	void update(Int index, T new_val) {
		__update(0, 0, len - 1, index, new_val);
	}

	void update(Int index, T(*func)(const T& el)) {
		__update(0, 0, len - 1, index, func);
	}

	void update(Int l, Int r, T(*func)(const T& el)) {
		__update(0, 0, len - 1, l, r, func);

		//void __update(Int v, Int vl, Int vr, Int l, Int r, T(*func)(const T& el))
	}

private:
	T __create(vector<T>& start, Int v, Int vl, Int vr) {
		if (vl == vr) {
			p_arr[v] = start[vl];
		}
		else {
			Int vm = (vl + vr) >> 1;

			T a = __create(start, (v << 1) + 1, vl, vm);
			T b = __create(start, (v << 1) + 2, vm + 1, vr);

			p_arr[v] = operation(a, b);
		}

		return p_arr[v];
	}


	/*
	void updateRange(int node, int start, int end, int l, int r, int val)
{
	// out of range
	if (start > end or start > r or end < l)
		return;

	// Current node is a leaf node
	if (start == end)
	{
		// Add the difference to current node
		tree[node] += val;
		return;
	}

	// If not a leaf node, recur for children.
	int mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);
	updateRange(node*2 + 1, mid + 1, end, l, r, val);

	// Use the result of children calls to update this node
	tree[node] = tree[node*2] + tree[node*2+1];
}

	*/


	T __get_segment(Int v, Int vl, Int vr, Int l, Int r) {
		if (vl == l && vr == r) {
			return p_arr[v];
		}

		Int vm = (vl + vr) >> 1;

		if (l > vm) {
			return __get_segment((v << 1) + 2, vm + 1, vr, l, r);
		}

		if (r <= vm) {
			return __get_segment((v << 1) + 1, vl, vm, l, r);
		}

		return operation(__get_segment((v << 1) + 1, vl, vm, l, vm),
			__get_segment((v << 1) + 2, vm + 1, vr, vm + 1, r));
	}

	void __update(Int v, Int vl, Int vr, Int index, T val) {

		if (vl == vr) {
			p_arr[v] = val;
		}
		else {
			Int mid = (vl + vr) >> 1;

			if (index <= mid) {
				__update((v << 1) + 1, vl, mid, index, val);
			}
			else {
				__update((v << 1) + 2, mid + 1, vr, index, val);
			}

			p_arr[v] = operation(p_arr[(v << 1) + 1], p_arr[(v << 1) + 2]);
		}
	}

	void __update(Int v, Int vl, Int vr, Int index, T(*func)(const T& el)) {

		if (vl == vr) {
			p_arr[v] = func(p_arr[v]);
		}
		else {
			Int mid = (vl + vr) >> 1;

			if (index <= mid) {
				__update((v << 1) + 1, vl, mid, index, func);
			}
			else {
				__update((v << 1) + 2, mid + 1, vr, index, func);
			}

			p_arr[v] = operation(p_arr[(v << 1) + 1], p_arr[(v << 1) + 2]);
		}
	}

	// update segment;
	void __update(Int v, Int vl, Int vr, Int l, Int r, T(*func)(const T& el)) {
		if (vl > vr || vl > r || vr < l)
			return;

		if (vl == vr) {
			p_arr[v] = func(p_arr[v]);
			return;
		}

		Int vm = (vl + vr) >> 1;

		__update((v << 1) + 1, vl, vm, l, r, func);
		__update((v << 1) + 2, vm + 1, vr, l, r, func);

		p_arr[v] = operation(p_arr[(v << 1) + 1], p_arr[(v << 1) + 2]);

	}
};

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

int hashCode(float a) {
	return (int)(31 * a);
}

int main() {
	
	HashMap<float, Int> map(200, hashCode);
	
	Int n, m;
	cin >> n >> m;
	
	vector< Int > arr(n + 1);
	vector< Int > costs(m + 1);
	HashMap<int, Int> count(2 * n);

	for (Int i = 0; i < n; ++i) {
		cin >> arr[i];
		--arr[i];
		++count[arr[i]];
	}

	for (Int i = 0; i < m; ++i) {
		cin >> costs[i];
	}

	for (auto el : count.getKeys()) {
		cout << el << " " << count[el] << endl;
	}
	

	system("pause");
	return 0;
}
/*
7 3
3 1 3 3 2 2 1
12 10 1
*/