#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (a && b)
	{
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}

	}
	return a + b;
}


class SegmentTree {
public:
	SegmentTree(vector<int> &start) {
		len = start.size();
		arr.assign(len * 4, 1);

		create(start, 0, 0, len - 1);
	}

	int len;
	vector<int> arr;

	int create(vector<int> &start, int v, int vl, int vr) {
		if (vl == vr) {
			arr[v] = start[vl];
		}
		else {
			int vm = (vl + vr) / 2;

			int a = create(start, v * 2 + 1, vl, vm);
			int b = create(start, v * 2 + 2, vm + 1, vr);

			arr[v] = gcd(a, b);
		}

		return arr[v];
	}

	int get_gcd(int l, int r) {
		return __get_gcd(0, 0, len - 1, l, r);
	}
	
private:

	int __get_gcd(int v, int vl, int vr, int l, int r) {
		if (vl == l && vr == r) {
			return arr[v];
		}

		int vm = (vl + vr) / 2;

		if (l > vm) {
			return __get_gcd(v * 2 + 2, vm + 1, vr, l, r);
		}

		if (r <= vm) {
			return __get_gcd(v * 2 + 1, vl, vm, l, r);
		}

		return gcd(__get_gcd(v * 2 + 1, vl, vm, l, vm),
			__get_gcd(v * 2 + 2, vm + 1, vr, vm + 1, r));
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	SegmentTree tree(arr);

	int requests;
	cin >> requests;

	vector<int> ans(requests);
	for (int i = 0; i < requests; ++i) {
		int a, b;
		cin >> a >> b;
		
		ans[i] = tree.get_gcd(--a, --b);
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}

	cin.get();
	cin.get();
	return 0;
}