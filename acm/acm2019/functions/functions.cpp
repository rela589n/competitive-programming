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

bool _envTest_ = true;
void runProduction() {
	// todo create something great!
}

vector< pair<const char*, const char*> > tests =
{ 
	make_pair(multiStr(
3
1 2 3
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

namespace Dijkstra {
	vector<Int> getDistances(vector< vector<Int> > graph, Int start) {
		Int n = graph.size();
		vector<bool> visited(n, false);
		vector<Int> distances(n, INF);
		distances[start] = 0;

		Int current = start;
		while (~current) {
			visited[current] = true;

			for (Int i = 0; i < n; ++i) {
				if (!visited[i] && graph[current][i] < distances[i] - distances[current]) { 
					// graph[current][i] + distances[current] < distances[i]
					distances[i] = graph[current][i] + distances[current];
				}
			}

			current = getMinDistanceVertex(distances, visited);
		}

		return distances;
	}

	Int getMinDistanceVertex(vector<Int> dist, vector<bool> visited) {
		Int min = INF;
		Int indx = -1;

		for (Int i = 0; i < dist.size(); ++i) {
			if (!visited[i] && dist[i] < min) {
				min = dist[i];
				indx = i;
			}
		}

		return indx;
	}
}

namespace sort {

	template <class T>
	void bubbleSort(vector<T> iterable)
	{
		bool swapped;
		
		for (int i = 0; i < iterable.size(); ++i)
		{
			swapped = false;
			for (int j = 0; j < iterable.size() - 1 - i; ++j)
			{
				if (iterable[j] > iterable[j + 1])
				{
					swap(iterable[j], iterable[j + 1]);
					swapped = true;
				}
			}

			if (!swapped)
			{
				break;
			}
		}
	}

	template <class T>
	void cocktailSort(vector<T> iterable)
	{
		bool swapped = true;
		int l = 0;
		int r = iterable.size() - 1;

		while (swapped)
		{
			swapped = false;
			for (int i = l; i < r; ++i)
			{
				if (iterable[i] > iterable[i + 1])
				{
					swap(iterable[i], iterable[i + 1]);
					swapped = true;
				}
			}

			if (!swapped)
			{
				break;
			}

			--r;
			swapped = false;

			for (int i = r; i > l; --i)
			{
				if (iterable[i - 1] > iterable[i])
				{
					swap(iterable[i - 1], iterable[i]);
					swapped = true;
				}
			}
			++l;
		}
	}

	template <class T>
	void selectionSort(vector<T> iterable)
	{
		for (int i = 0; i < iterable.size(); ++i)
		{
			swap(iterable[i], iterable[findMinIndex(iterable, i, iterable.size() - 1)]);
		}
	}

	template <class T>
	int findMinIndex(vector<T> iterable, int l, int r)
	{
		int minIndex = l;
		T min = iterable[l];

		for (int i = l; i <= r; ++i)
		{
			if (iterable[i] < min) {
				min = iterable[i];
				minIndex = i;
			}
		}

		return minIndex;
	}

	template <class T>
	void insertionSort(vector<T> iterable)
	{
		for (int i = 1; i < iterable.size(); ++i)
			for (int j = i; (j > 0) && iterable[j - 1] > iterable[j]; --j)
				swap(iterable[j - 1], iterable[j]);
	}

	template <class T>
	void shellSort(vector<T> iterable)
	{
		for (int gap = iterable.size() >> 1; gap > 0; gap >>= 1)
			for (int i = gap; i < iterable.size(); i += gap)
				for (int j = i; (j > 0) && iterable[j - gap] > iterable[j]; j -= gap)
					swap(iterable[j - gap], iterable[j]);
	}


	template <class T>
	void mergeSort(vector<T> a, int lo, int hi) {
		if (hi <= lo)
			return;
		int mid = lo + (hi - lo) / 2;

		mergeSort(a, lo, mid);
		mergeSort(a, mid + 1, hi);

		int len_b = hi - lo + 1;
		T* b = new T[len_b];
		int l = lo, r = mid + 1;
		for (int i = 0; i < len_b; ++i)
			if (l <= mid)
				if (r <= hi)
					if (a[l] <= a[r])
						b[i] = a[l++];
					else
						b[i] = a[r++];
				else {
					while (l <= mid)
						b[i++] = a[l++];
					break;
				}
			else {
				while (r <= hi)
					b[i++] = a[r++];
				break;
			}
		for (int i = lo; i <= hi; ++i)
			a[i] = b[i - lo];
		delete[] b;
	}

}


namespace hashMap {
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

		list<Tkey> keys;

	public:
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


	// hash function
	std::hash<std::string>()("string to hash")

}

namespace algorithms {
	int binary_search(vector<Int> a, Int val) {
		int l = 0, r = a.size() - 1;

		while (l < r) {
			int c = (l + r) / 2;

			if (val < a[c]) {
				r = c - 1;
			}
			else if(val > a[c]) {
				l = c + 1;
			}
			else {
				l = r = c;
				break;
			}
		}

		if (a[l] == val) {
			return l;
		}

		return -1;
	}

	Int gcd(Int a, Int b) {
		while (a && b) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}

		return a + b;
	}

	Int lcm(Int a, Int b) {
		return a * b / gcd(a, b);
	}


	Int binaryPow (Int a, int n) {
		Int res = 1;
		while (n) {
			if (n & 1)
				res *= a;
			a *= a;
			n >>= 1;
		}
		return res;
	}

	ll reverseNum(ll num) {
		ll result = 0, remainder;

		for (; num; num /= 10) {
			remainder = num % 10;
			result = result * 10 + remainder;
		}

		return result;
	}
}

namespace NumberSystemConverter {
	class NumberSystemConverter {
	private:
		//Вектор содержит исходное число
		vector<int> a;
		//Исходная система счисления
		int initial;
	public:
		//Конструктор, содержит 2 параметра: строка исходного числа, исходная система счисления
		NumberSystemConverter(string str, int initial) {
			this->initial = initial;
			a.reserve(str.length());
			//Заносит числа исходного числа в вектор
			for (string::iterator i = str.begin(); i != str.end(); ++i) {
				a.push_back(charToInt(*i));
			}
		}
		//Переводит символ в число, вместо некорректных символов возвращает -1
		int charToInt(char c) {
			if (c >= '0' && c <= '9' && (c - '0') < this->initial) {
				return c - '0';
			}
			else {
				if (c >= 'A' && c <= 'Z' && (c - 'A') < this->initial) {
					return c - 'A' + 10;
				}
				else {
					return -1;
				}
			}
		}
		//Переводит число в символ
		static char intToChar(int c) {
			if (c >= 0 && c <= 9) {
				return c + '0';
			}
			else {
				return c + 'A' - 10;
			}
		}
		//Получает следующую цифру числа в новой системе счисления
		int nextNumber(int final) {
			int temp = 0;
			for (int i = 0; i < this->a.size(); ++i) {
				temp = temp * this->initial + this->a[i];
				a[i] = temp / final;
				temp = temp % final;
			}
			return temp;
		}
		//Возвращает true - если массив состоит из одних нулей и false в противном случае
		bool zero() {
			for (int i = 0; i < this->a.size(); ++i) {
				if (a[i] != 0) {
					return false;
				}
			}
			return true;
		}
		//Конвертирует исходное число в заданную систему счисления
		string convertTo(int final) {
			vector<int> b;
			int size = 0;
			do {
				b.push_back(this->nextNumber(final));
				++size;
			} while (!this->zero());

			string sTemp = "";
			for (int i = b.size() - 1; i >= 0; --i) {
				sTemp += intToChar(b[i]);
			}
			return sTemp;
		}
	};
}

namespace BFS_DFS {
	typedef long long Int;
	const Int INF = 2147483647;

	class Graph
	{
		int numVertices;
		vector< list<int> > graph;
		vector<bool> visitedBFS;
		
		vector<Int> distance;
		vector<Int> parent;

		void DFSUtil(int v, vector<bool>& visited);
	public:
		Graph(int vertices);
		void addEdge(int src, int dest);
		void BFS(int startVertex);
		
		Int minDistance(int start, int finish);
		vector<int> path(int to);

		void DFS(int v);
	};

	Graph::Graph(int vertices)
	{
		numVertices = vertices;
		graph = vector< list<int> > (vertices);
	}

	void Graph::addEdge(int src, int dest)
	{
		graph[src].push_back(dest);
		//graph[dest].push_back(src);
	}

	void Graph::BFS(int startVertex)
	{
		visitedBFS = vector<bool>(numVertices, false);
		
		queue<int> q;

		visitedBFS[startVertex] = true;
		q.push(startVertex);

		distance = vector<Int>(numVertices);
		parent = vector<Int>(numVertices);

		parent[startVertex] = -1;

		list<int>::iterator i;
		while (!q.empty())
		{
			int currVertex = q.front();
			//cout << "Visited " << currVertex << " ";
			q.pop();

			for (i = graph[currVertex].begin(); i != graph[currVertex].end(); ++i)
			{
				int to = *i;
				if (!visitedBFS[to])
				{
					visitedBFS[to] = true;
					q.push(to);

					distance[to] = distance[currVertex] + 1;
					parent[to] = currVertex;
				}
			}
		}
	}

	Int Graph::minDistance(int start, int finish) 
	{
	//	BFS(start);
		return distance[finish];
	}
	vector<int> Graph::path(int to) {
		if (!visitedBFS[to]) {
			return vector<int>(0);
		}
		vector<int> _path;
		_path.reserve(100);

		for (int v = to; ~v; v = parent[v]) {
			_path.push_back(v);
		}
		
		reverse(_path.begin(), _path.end());
		return _path;
	}


	void Graph::DFSUtil(int v, vector<bool>& visited)
	{
		// Mark the current node as visited and 
		// print it 
		visited[v] = true;
		cout << v + 1 << " ";

		// Recur for all the vertices adjacent 
		// to this vertex 
		list<int>::iterator i;
		for (i = graph[v].begin(); i != graph[v].end(); ++i)
			if (!visited[*i])
				DFSUtil(*i, visited);
	}

	// DFS traversal of the vertices reachable from v. 
	// It uses recursive DFSUtil() 
	void Graph::DFS(int v)
	{
		vector<bool> visited(numVertices, false);

		DFSUtil(v, visited);
	}
}

namespace eratospheneSieve {
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
}

namespace SegmentTree {
	
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
}

namespace Trie {
	#include <iostream>
	#include <vector>
	#include <algorithm>

	// define character size
	#define CHAR_SIZE 128

	// A Class representing a Trie node
	class Trie
	{
	public:
		bool isLeaf;
		Trie* character[CHAR_SIZE];

		// Constructor
		Trie()
		{
			this->isLeaf = false;

			for (int i = 0; i < CHAR_SIZE; i++)
				this->character[i] = nullptr;
		}

		void insert(std::string);
		bool deletion(Trie*&, std::string);
		bool search(std::string);
		bool haveChildren(Trie const*);
	};

	// Iterative function to insert a key in the Trie
	void Trie::insert(std::string key)
	{
		// start from root node
		Trie* curr = this;
		for (int i = 0; i < key.length(); i++)
		{
			// create a new node if path doesn't exists
			if (curr->character[key[i]] == nullptr)
				curr->character[key[i]] = new Trie();

			// go to next node
			curr = curr->character[key[i]];
		}

		// mark current node as leaf
		curr->isLeaf = true;
	}

	// Iterative function to search a key in Trie. It returns true
	// if the key is found in the Trie, else it returns false
	bool Trie::search(std::string key)
	{
		// return false if Trie is empty
		if (this == nullptr)
			return false;

		Trie* curr = this;
		for (int i = 0; i < key.length(); i++)
		{
			// go to next node
			curr = curr->character[key[i]];

			// if string is invalid (reached end of path in Trie)
			if (curr == nullptr)
				return false;
		}

		// if current node is a leaf and we have reached the
		// end of the string, return true
		return curr->isLeaf;
	}

	// returns true if given node has any children
	bool Trie::haveChildren(Trie const* curr)
	{
		for (int i = 0; i < CHAR_SIZE; i++)
			if (curr->character[i])
				return true;	// child found

		return false;
	}

	// Recursive function to delete a key in the Trie
	bool Trie::deletion(Trie*& curr, std::string key)
	{
		// return if Trie is empty
		if (curr == nullptr)
			return false;

		// if we have not reached the end of the key
		if (key.length())
		{
			// recur for the node corresponding to next character in the key
			// and if it returns true, delete current node (if it is non-leaf)

			if (curr != nullptr &&
				curr->character[key[0]] != nullptr &&
				deletion(curr->character[key[0]], key.substr(1)) &&
				curr->isLeaf == false)
			{
				if (!haveChildren(curr))
				{
					delete curr;
					curr = nullptr;
					return true;
				}
				else {
					return false;
				}
			}
		}

		// if we have reached the end of the key
		if (key.length() == 0 && curr->isLeaf)
		{
			// if current node is a leaf node and 	don't have any children
			if (!haveChildren(curr))
			{
				// delete current node
				delete curr;
				curr = nullptr;

				// delete non-leaf parent nodes
				return true;
			}

			// if current node is a leaf node and have children
			else
			{
				// mark current node as non-leaf node (DON'T DELETE IT)
				curr->isLeaf = false;

				// don't delete its parent nodes
				return false;
			}
		}

		return false;
	}

	// C++ implementation of Trie Data Structure
	int main()
	{
		Trie* head = new Trie();

		head->insert("hello");
		std::cout << head->search("hello") << " ";  	// print 1

		head->insert("helloworld");
		std::cout << head->search("helloworld") << " "; // print 1

		std::cout << head->search("helll") << " ";  	// print 0 (Not found)

		head->insert("hell");
		std::cout << head->search("hell") << " ";   	// print 1

		head->insert("h");
		std::cout << head->search("h"); 				// print 1

		std::cout << std::endl;

		head->deletion(head, "hello");
		std::cout << head->search("hello") << " ";  	// print 0

		std::cout << head->search("helloworld") << " "; // print 1
		std::cout << head->search("hell");  			// print 1

		std::cout << std::endl;

		head->deletion(head, "h");
		std::cout << head->search("h") << " ";  		// print 0
		std::cout << head->search("hell") << " ";   	// print 1
		std::cout << head->search("helloworld");		// print 1

		std::cout << std::endl;

		head->deletion(head, "helloworld");
		std::cout << head->search("helloworld") << " "; // print 0
		std::cout << head->search("hell") << " ";   	// print 1

		head->deletion(head, "hell");
		std::cout << head->search("hell");  			// print 0

		std::cout << std::endl;

		if (head == nullptr)
			std::cout << "Trie empty!!\n";  			// Trie is empty now

		std::cout << head->search("hell");  			// print 0

		system("pause");
		return 0;
	}
}

namespace XorPath {
	inline void bruteForce(vector< vector<int> > &arr, int i, int j, int& n, int curXor, int& minXor) {
		curXor ^= arr[i][j];

		if (i == n - 1 && j == n - 1) {
			minXor = min(minXor, curXor);
			return;
		}

		if (i + 1 < n) {
			bruteForce(arr, i + 1, j, n, curXor, minXor);
		}

		if (j + 1 < n) {
			bruteForce(arr, i, j + 1, n, curXor, minXor);
		}
	}

	class Trie
	{
	public:
		//for integer representation in binary system 2^32
		static const int MaxLengthOfBits = 32;
		//size of alphabet
		static const int N = 2;

		class Node
		{
		public:
			Node* next[Trie::N];

			Node() {
				next[0] = next[1] = nullptr;
			}
		};

		Trie() {
			_root = new Node();
		}

		void clear() {
			clear(_root);
			_root = new Node();
		}

		void clear(Node *root) {
			if (root->next[0] != nullptr) {
				clear(root->next[0]);
			}
			if (root->next[1] != nullptr) {
				clear(root->next[1]);
			}
			delete root;
		}

		static vector<bool> ConvertDecimalToBInary(int number)
		{
			int counter = Trie::MaxLengthOfBits;
			vector<bool> result = vector<bool>(counter);
			while (number > 0)
			{
				result[--counter] = number % 2;
				number >>= 1;
			}

			return result;
		}

		static int ConvertBinaryToDecimal(vector<bool> bits)
		{
			int result = 0;
			int base_val = 1;
			for (int i = bits.size() - 1; i >= 0; --i)
			{
				result += bits[i] * base_val;
				base_val <<= 1;
			}

			return result;
		}

		void AddValue(int number)
		{
			//AddValue(ConvertDecimalToBInary(number)); // it is tooo long!!!

			Node* tmp = _root;
			for (int i = MaxLengthOfBits - 1; i >= 0; --i) {
				bool bit = number & (1 << i); // if val has bit as 2 ** i (or current element of array), then 1 else 0

				if (tmp->next[bit] == nullptr) {
					tmp->next[bit] = new Node();
				}

				tmp = tmp->next[bit];
			}
		}

		void AddValue(vector<bool> binaryNumber)
		{
			_root = AddValue(_root, binaryNumber, 0);
		}
		
		Node* _root;


	private:
		
		Node* AddValue(Node* node, vector<bool> val, int d)
		{
			if (node == nullptr) node = new Node();

			//if least sagnificient bit has been added
			//need return
			if (d == val.size())
			{
				return node;
			}

			// get 0 or 1 index of next array(length 2)
			int index = val[d];
			node->next[index] = AddValue(node->next[index], val, ++d);
			return node;
		}
	};
	
}

namespace DynamicProgramming {
	bool checkCoefs(vector<ll>& trace, vector<ll>& sequence, ll offset) {
		ll result = 0;
		for (ll i = 0; i < trace.size(); ++i) {
			
			result += trace[i] * sequence[i + offset];
		}

		return result == sequence[trace.size() + offset];
	}

	void findCoefsRecursive(vector<ll> &trace, vector<ll>& sequence, ll elementIndex, ll depth, ll & coefMin, ll& coefMax) {
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

	/*
	Перед каждым переприсвоением обязательно нужно проверять, больше ли следующее значение предыдущего, а не пологаться
	на недоказанные предположения
	*/
}

namespace NDeepLoops {
	template<int dim>
	struct multi_index_t
	{
		std::array<int, dim> size_array;
		template<typename ... Args>
		multi_index_t(Args&& ... args) : size_array(std::forward<Args>(args) ...) {}

		struct iterator
		{
			struct sentinel_t {};

			std::array<int, dim> index_array = {};
			std::array<int, dim> const& size_array;
			bool _end = false;

			iterator(std::array<int, dim> const& size_array) : size_array(size_array) {}

			auto& operator++()
			{
				for (int i = 0; i < dim; ++i)
				{
					if (index_array[i] < size_array[i] - 1)
					{
						++index_array[i];
						for (int j = 0; j < i; ++j)
						{
							index_array[j] = 0;
						}
						return *this;
					}
				}
				_end = true;
				return *this;
			}
			auto& operator*()
			{
				return index_array;
			}
			bool operator!=(sentinel_t) const
			{
				return !_end;
			}
		};

		auto begin() const
		{
			return iterator{ size_array };
		}
		auto end() const
		{
			return typename iterator::sentinel_t{};
		}
	};

	template<typename ... index_t>
	auto multi_index(index_t&& ... index)
	{
		static constexpr int size = sizeof ... (index_t);
		auto ar = std::array<int, size>{std::forward<index_t>(index) ...};
		return multi_index_t<size>(ar);
	}
}


std::to_string(T n); // convert primitive type to string
bool str_replace(std::string& str, const std::string& from, const std::string& to) { // replace $"from" into $"to" in $"str"
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

int reverseLLLastSize;

ll reverseLL(ll in) {
	reverseLLLastSize = 0;

	ll out = 0;
	while (in)
	{
		out *= 10;
		out += in % 10;
		in /= 10;

		++reverseLLLastSize;
	}

	return out;
}
// a < b
bool compareIntsAsString(ll a, ll b) {
	if (a == b) return true;
	if (a < 0 && b >= 0) return true;
	if (b < 0 && a >= 0) return false;

	if (a < 0) {
		a = -a;
	}

	if (b < 0) {
		b = -b;
	}

	a = reverseLL(a);
	int lenA = reverseLLLastSize;

	b = reverseLL(b);
	int lenB = reverseLLLastSize;

	while (a && b) {
		int pa = a % 10;
		int pb = b % 10;

		if (pa < pb) {
			return true;
		}
		if (pa > pb) {
			return false;
		}
		
		a /= 10;
		b /= 10;
	}

	return lenA < lenB;
}