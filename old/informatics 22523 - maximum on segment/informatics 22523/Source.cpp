#include <iostream>
#include <vector>


using namespace std;

int gcd(const int &a, const int &b) {
	int a1 = a, b1 = b;

	while (a1 && b1) {
		if (a1 > b1) {
			a1 %= b1;
		}
		else {
			b1 %= a1;
		}
	}

	return a1 + b1;
}

template <class T>
class SegmentTree {
public:
	SegmentTree(vector<T> &start_arr, T(*set_operation)(const T &a, const T &b), T by_default) {
		len = start_arr.size();

		// if len is the power of 2
		if (len && !(len & (len - 1))) {
			arr.assign(len << 1, by_default);
		}
		else {
			arr.assign(len << 2, by_default);
		}

		operation = set_operation;

		__create(start_arr, 0, 0, len - 1);
	}

	int len;
	vector<T> arr;
	T(*operation)(const T &a, const T &b);

	T get_segment(int l, int r) {
		return __get_segment(0, 0, len - 1, l, r);
	}

	void update(int index, T new_val) {
		__update(0, 0, len - 1, index, new_val);
	}

private:
	T __create(vector<T> &start, int v, int vl, int vr) {
		if (vl == vr) {
			arr[v] = start[vl];
		}
		else {
			int vm = (vl + vr) >> 1;

			T a = __create(start, (v << 1) + 1, vl, vm);
			T b = __create(start, (v << 1) + 2, vm + 1, vr);

			arr[v] = operation(a, b);
		}

		return arr[v];
	}

	T __get_segment(int v, int vl, int vr, int l, int r) {
		if (vl == l && vr == r) {
			return arr[v];
		}

		int vm = (vl + vr) >> 1;

		if (l > vm) {
			return __get_segment((v << 1) + 2, vm + 1, vr, l, r);
		}

		if (r <= vm) {
			return __get_segment((v << 1) + 1, vl, vm, l, r);
		}

		return operation(__get_segment((v << 1) + 1, vl, vm, l, vm),
			__get_segment((v << 1) + 2, vm + 1, vr, vm + 1, r));
	}

	void __update(int v, int vl, int vr, int index, T val) {

		if (vl == vr) {
			arr[v] = val;
		}
		else {
			int mid = (vl + vr) >> 1;

			if (index <= mid) {
				__update((v << 1) + 1, vl, mid, index, val);
			}
			else {
				__update((v << 1) + 2, mid + 1, vr, index, val);
			}

			arr[v] = operation(arr[(v << 1) + 1], arr[(v << 1) + 2]);
		}
	}
};


int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	SegmentTree<int> tree(arr, gcd, 1);

	int tests;
	cin >> tests;
	
	vector<int> ans;
	ans.reserve(tests);

	for (int i = 0; i < tests; ++i) {
		cin.get();

		char request;
		cin >> request;

		if (request == 's') {
			int l, r;
			cin >> l >> r;

			--l;
			--r;
			ans.push_back(tree.get_segment(l, r));

		}
		else {
			int index, new_val;

			cin >> index >> new_val;

			index -= 1;
			tree.update(index, new_val);
		}

	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}


	return 0;
}
