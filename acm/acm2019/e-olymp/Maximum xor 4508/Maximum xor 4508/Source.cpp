#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
public:
	const int INT_SIZE = 32;

	class Node {
	public:
		int val;
		Node* arr[2];

		Node() {
			arr[0] = arr[1] = nullptr;
			val = 0;
		}
	};
	
	Node* root;

	Trie() {
		root = new Node();
		insert(0);
	}

	void insert(int val) {
		Node* tmp = root;

		for (int i = INT_SIZE - 1; i >= 0; --i) {
			bool bit = val & (1 << i); // if val has bit as 2 ** i (or current element of array), then 1 else 0

			if (tmp->arr[bit] == nullptr) {
				tmp->arr[bit] = new Node();
			}

			tmp = tmp->arr[bit];
		}

		tmp->val = val;
	}

	int query(int currentXor) {
		Node* tmp = root;
		
		for (int i = INT_SIZE - 1; i >= 0; --i) {
			bool bit = currentXor & (1 << i);

			// try to go into another bit (that will be good to do xor after)
			if (tmp->arr[1 - bit] != nullptr) {
				tmp = tmp->arr[1 - bit];
			}
			else { // if (tmp->arr[bit] != nullptr)
				tmp = tmp->arr[bit];
			}
		}

		return currentXor ^ (tmp->val);
	}
};


int maxSubArrayXor(vector<int>& v) {
	int maxXor = 0;
	int cXor = 0;
	Trie t;
	t.insert(0);

	for (int i = 0; i < v.size(); ++i) {
		cXor ^= v[i];
		t.insert(cXor);

		maxXor = max(maxXor, t.query(cXor));
	}

	return maxXor;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		//cout << &v[i] << endl;
		scanf_s("%d", &v[i]);
	}
	cout << maxSubArrayXor(v);


	system("pause");
	return 0;
}