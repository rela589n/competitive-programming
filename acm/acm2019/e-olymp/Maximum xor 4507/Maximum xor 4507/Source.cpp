#define _CRT_SECURE_NO_WARNINGS // for visual studio & scanf

#include <iostream>
#include <vector>

using namespace std;

//typedef long long Int;

class Trie 
{
public:
	static const int INT_SIZE = 32;

	class Node
	{
	public:
		Node* arr[2];

		Node() 
		{
			arr[0] = arr[1] = nullptr;
		}
	};

	Node* root;

	Trie()
	{
		root = new Node();
		insert(0);
	}

	void insert(int val)
	{
		Node* tmp = root;

		for (int i = INT_SIZE - 1; i >= 0; --i) {
			bool bit = val & (1 << i); /* if val has bit as 2 ** i (it is current element of array), then 1 else 0
									    * that is the same as convert number to binary and work with each bit separatly 
									    */
			if (tmp->arr[bit] == nullptr) {
				tmp->arr[bit] = new Node();
			}

			tmp = tmp->arr[bit];
		}
	}

	void maxXor(Node * tmp, vector<bool> &res, int depth) 
	{
		if (tmp->arr[1] != nullptr) {
			res[depth] = 1;	
			maxXor(tmp->arr[1], res, depth + 1);
		}

		if (tmp->arr[0] != nullptr) {
			maxXor(tmp->arr[0], res, depth + 1);
		}
	}

	// not used in this program
	static vector<bool> toBinary(int n)
	{
		vector<bool> res(INT_SIZE, false);

		int counter = INT_SIZE;
		while (n > 0) {
			res[--counter] = n % 2;
			n /= 2;
		}

		return res;
	}

	static int toDecimal(vector<bool> bits)
	{
		int base = 1;
		int result = 0;

		for (int i = bits.size() - 1; i >= 0; --i) {
			result += bits[i] * base;
			base *= 2;
		}

		return result;
	}
};


int maxSubArrayXor(vector<int>& v) {
	Trie t;
	
	for (int i = 0; i < v.size(); ++i)
	{
		t.insert(v[i]);
	}

	vector <bool> ans(t.INT_SIZE, false);
	t.maxXor(t.root, ans, 0);

	return t.toDecimal(ans);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		//cout << &v[i] << endl;
		scanf("%d", &v[i]);
	}
	printf("%d", maxSubArrayXor(v));

//	system("pause");
	return 0;
}
/*
32
1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216 33554432 67108864 134217728 268435456 536870912 1073741824 2000000000

*/