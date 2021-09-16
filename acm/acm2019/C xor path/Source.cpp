#include <iostream>
#include <vector>

using namespace std;

inline int min(int& a, int& b) {
	return (a < b) ? a : b;
}

inline int max(int& a, int& b) {
	return (a > b) ? a : b;
}

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
	Node* _root;

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

	void AddValue(int number)
	{
		Node* tmp = _root;
		for (int i = MaxLengthOfBits - 1; i >= 0; --i) {
			bool bit = number & (1 << i); // if val has bit as 2 ** i (or current element of array), then 1 else 0

			if (tmp->next[bit] == nullptr) {
				tmp->next[bit] = new Node();
			}

			tmp = tmp->next[bit];
		}
	}
};

class Solve
{
public:
	vector< vector<int> > vec;
	int center;
	int n;
	
	vector<Trie> leftTrie;
	vector<Trie> rightTrie;

	Solve(vector< vector<int> >& vec) {
		this->vec = vec;
		this->n = vec.size();
		center = n - 1; // for central diagonal

		leftTrie = vector<Trie>(n);
		rightTrie = vector<Trie>(n);	
	}

	void solve(int & minXor) {
		utilLeft(0, 0, 0);
		utilRight(n - 1, n - 1, 0);

		for (int outer = 0; outer < n; ++outer) {
			auto l = leftTrie[outer]._root;
			auto r = rightTrie[outer]._root;

			int res = 0;
			for (int i = 0; i < Trie::MaxLengthOfBits; ++i) {
			
				// left isset			  right is not isset			left is not isset     right isset
				if (l->next[0] != nullptr && l->next[1] == nullptr && r->next[0] == nullptr && r->next[1] != nullptr)
				{
					res += 1 << (Trie::MaxLengthOfBits - i - 1);
					l = l->next[0];
					r = r->next[1];
				}
				else if (l->next[0] == nullptr && l->next[1] != nullptr && r->next[0] != nullptr && r->next[1] == nullptr) {
					res += 1 << (Trie::MaxLengthOfBits - i - 1);
					l = l->next[1];
					r = r->next[0];
				}
				else {

					if (l->next[0] != nullptr && l->next[1] != nullptr && r->next[0] != nullptr && r->next[1] != nullptr) {
						int zeroLvl = diffLevel(l->next[0], r->next[0], 0);
						int oneLvl = diffLevel(l->next[1], r->next[1], 0);

						if (zeroLvl >= oneLvl) {
							l = l->next[0];
							r = r->next[0];
						}
						else {
							l = l->next[1];
							r = r->next[1];
						}
					}
					else if (l->next[0] != nullptr && r->next[0] != nullptr) {
						l = l->next[0];
						r = r->next[0];
					}
					else if (l->next[1] != nullptr && r->next[1] != nullptr) {
						l = l->next[1];
						r = r->next[1];
					}
					else {
						break;
					}
				}
			}

			minXor = min(res, minXor);
		}
	}


	int diffLevel(Trie::Node* l, Trie::Node* r, int level) { // return distance to bits that are different
		++level;
		if (l->next[0] != nullptr && l->next[1] == nullptr && r->next[0] == nullptr && r->next[1] != nullptr ||
			l->next[0] == nullptr && l->next[1] != nullptr && r->next[0] != nullptr && r->next[1] == nullptr)
		{
			return level;
		}
		else {
			if (l->next[0] != nullptr && l->next[1] != nullptr && r->next[0] != nullptr && r->next[1] != nullptr) {
				int zeroLvl = diffLevel(l->next[0], r->next[0], level);
				int oneLvl = diffLevel(l->next[1], r->next[1], level);
				return max(zeroLvl, oneLvl);
			}
			else if (l->next[0] != nullptr && r->next[0] != nullptr) {
				return diffLevel(l->next[0], r->next[0], level);
			}
			else if (l->next[1] != nullptr && r->next[1] != nullptr) {
				return diffLevel(l->next[1], r->next[1], level);
			}
			else {
				return level;
			}
		}
	}
	
	void utilLeft(int i, int j, int curXor) {
		curXor ^= vec[i][j];

		if (i + j == center) {
			leftTrie[i].AddValue(curXor);
		}

		if (!((i + 1) + j > center)) {
			utilLeft(i + 1, j, curXor);
		}

		if (!(i + (j + 1) > center)) {
			utilLeft(i, j + 1, curXor);
		}
	}

	void utilRight(int i, int j, int curXor) {
		curXor ^= vec[i][j];

		if (i + j == center) {
			rightTrie[i].AddValue(curXor ^ vec[i][j]); // xor cuz left tries vector contains vec[i][j]
		}

		if (!((i - 1) + j < center)) {
			utilRight(i - 1, j, curXor);
		}

		if (!(i + (j - 1) < center)) {
			utilRight(i, j - 1, curXor);
		}
	}

	/*

	wrong 
	1 2 3 4 5
	6 {2} 8 9 1
	2 3 {1} 5 6
	7 8 9 {0} 2
	3 4 5 6 7

	goood
	5
	1 2 3 4 {4}
	6 2 8 {3} 1
	2 3 {2} 5 6
	7 {1} 9 0 2
	{0} 4 5 6 7


	i + j + 1 <= n

	*/
};

int main() {
	int n, i, j;
	cin >> n;
	
	vector< vector<int> > arr(n, vector<int>(n));
	int minXor = 1000000001;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	
	//if (n <= 12) {
		//bruteForce(arr, 0, 0, n, 0, minXor);
		
	//}
	//else {
		Solve s(arr);
		s.solve(minXor);
	//}

	cout << minXor << endl;

	//system("pause");
	return 0;
}



/*
6
 66  73  44 44 46 56
 54 107  45 55 80 50
 68  60  84 57 45 49
 85 111  98 51 58 87
 61  75  38 91 53 69
101  95 106 97 99 88


5
 60  78 100  21 47
 55 115  58 112 43
106  91  80  40 62
 88  77  43  33 84
102  70  17  48 34

2
1 8
2 8

3
1 2 3
3 4 5
6 7 8
// 1 -> 2 -> 4 -> 7 -> 8



4
99 146 613 1416
513 5810 1515 9616
1247 5124 6284 5844
1139 6135 6427 1561

20
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6
1 1 2 5 6 1 1 2 5 6 1 1 2 5 6 1 1 2 5 6


10
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90
2 4 1 5 8 0 2 83 8 90

20
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910 10 112 123
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910 10 112 123
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9 18 78 20

17 
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9	
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823 910
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823 910
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68 9

16
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53 68
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7 823
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7 823

15
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7
2 8 95 34 1 7 823 78 20 4 2 8 34 1 7
4 2 8 95 34 1 7 823 910 10 112 123 132 4 53
132 4 53 68 9 18 78 20 4 2 8 95 34 1 7

14
4 2 8 95 34 1 7 823 910 10 112 123 132 4
132 4 53 68 9 18 78 20 4 2 8 95 34 1
2 8 95 34 1 7 823 78 20 4 2 8 34 1
4 2 8 95 34 1 7 823 910 10 112 123 132 4
132 4 53 68 9 18 78 20 4 2 8 95 34 1
2 8 95 34 1 7 823 78 20 4 2 8 34 1
4 2 8 95 34 1 7 823 910 10 112 123 132 4
132 4 53 68 9 18 78 20 4 2 8 95 34 1
2 8 95 34 1 7 823 78 20 4 2 8 34 1
4 2 8 95 34 1 7 823 910 10 112 123 132 4
4 2 8 95 34 1 7 823 910 10 112 123 132 4
132 4 53 68 9 18 78 20 4 2 8 95 34 1
2 8 95 34 1 7 823 78 20 4 2 8 34 1
4 2 8 95 34 1 7 823 910 10 112 123 132 4

13
4 2 8 95 34 1 7 823 910 10 112 123 132
132 4 53 68 9 18 78 20 4 2 8 95 34
2 8 95 34 1 7 823 78 20 4 2 8 34
4 2 8 95 34 1 7 823 910 10 112 123 132
132 4 53 68 9 18 78 20 4 2 8 95 34
2 8 95 34 1 7 823 78 20 4 2 8 34
4 2 8 95 34 1 7 823 910 10 112 123 132
132 4 53 68 9 18 78 20 4 2 8 95 34
2 8 95 34 1 7 823 78 20 4 2 8 34
4 2 8 95 34 1 7 823 910 10 112 123 132
4 2 8 95 34 1 7 823 910 10 112 123 132
132 4 53 68 9 18 78 20 4 2 8 95 34
2 8 95 34 1 7 823 78 20 4 2 8 34
*/