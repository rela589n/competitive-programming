#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


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

pair<long long, int> lambda_for_tree(const pair<long long, int> &a, const pair<long long, int> &b) {
	
	if (a.first > b.first) {
		return a;
	}
	else {
		return b;
	}
}


int main() {
	int n;
	cin >> n;
	
	vector< pair<long long, int> > arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	SegmentTree< pair<long long, int> > tree(arr, lambda_for_tree, make_pair(-9223372036854775806, -2147483646));

	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		int l, r;
		cin >> l >> r;

		pair< long long, int> ans = tree.get_segment(--l, --r);
		cout << ans.first << ' ' << ans.second + 1 << endl;
	}


	//cin.get();
	
	return 0;
}
