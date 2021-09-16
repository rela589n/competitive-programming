#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

//const unsigned long long INF = 1844744073709551613;
vector<unsigned long long> p;
int pi = 31;

unsigned long long getHash(vector<unsigned long long>& h, int L, int R) {
	unsigned long long temp = h[R];
	if (L > 0)temp -= h[L - 1];

	return temp;
}
vector<unsigned long long> a;

int main()
{

	SegmentTree<






















	// cout << INF;
	string str1;
	cin >> str1;
	//scanf("%s", str1);

	int leng_ = str1.length();

	p.resize(leng_);
	a.resize(leng_);

	p[0] = 1;
	a[0] = str1[0] - 97 + 1;
	for (int i = 1; i < p.size(); i++) {
		p[i] = p[i - 1] * pi;
		a[i] = (a[i - 1] + (str1[i] - 97 + 1) * p[i]);
	}
	int t;
	cin >> t;
	// scanf("%d", &t);
	int vub;

	for (int i = 0; i < t; i++) {
		//scanf("%d", &vub);
		cin >> vub;
		switch (vub) {
		case 1: {
			int l;
			char s;
			cin >> l >> s;
			//scanf("%d%c", &l, &s);
			str1[l - 1] = s;
			if (l == 1) {
				//  str1[0] = s;
				a[0] = s - 96;
				l = 2;
				//  cout << str1 << endl;
			}
			for (int j = l - 1; j < leng_; j++) {
				//cout << j <<" "<<a.size()<< endl;
				a[j] = (a[j - 1] + (str1[j] - 97 + 1) * p[j]);
			}
			break;
		}
		case 2: {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			// scanf("%d%d%d%d", &l, &r, &x, &y);

			 //if  (getHash(a, l - 1, r - 1) * p[x-1] == getHash(a, x - 1, y - 1) * p[l-1])cout << "Yes" << endl;
			if ((l < x && getHash(a, l - 1, r - 1) * p[x - l] == getHash(a, x - 1, y - 1)) || (l > x && getHash(a, l - 1, r - 1) == getHash(a, x - 1, y - 1) * p[l - x]) || l == x)printf("Yes\n");
			else printf("No\n");
			break;
		}
		}
	}

}