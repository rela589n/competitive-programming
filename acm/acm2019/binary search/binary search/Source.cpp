#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& vec, int val) {
	int l = 0;
	int r = vec.size() - 1;

	while (l < r) {
		int mid = l + (r - l) / 2;

		if (val < vec[mid]) {
			r = mid - 1;
		}
		else if (val > vec[mid]) {
			l = mid + 1;
		}
		else {
			l = r = mid;
		}
	}

	if (vec[l] == val) {
		return l;
	}

	return -1;
}

static unsigned long x = 123456789, y = 362436069, z = 521288629;

unsigned long xorshf96(void) {          //period 2^96-1
	unsigned long t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;

	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;

	return z;
}

/*inline int randomizer(int l, int r) {
	return l + (xorshf96() % (r - l + 1));
}*/


int notBinarySearch(vector<int>& vec, int val) {
	int l = 0;
	int r = vec.size() - 1;

	while (l < r) {

		int notMid = l;
		int rMinusl = r - l;
		notMid += (rMinusl < 1000) ? (rMinusl >> 1) : (xorshf96() % (rMinusl + 1));

		if (val < vec[notMid]) {
			r = notMid - 1;
		}
		else if (val > vec[notMid]) {
			l = notMid + 1;
		}
		else {
			l = r = notMid;
		}
	}

	if (l == r && vec[l] == val) {
		return l;
	}

	return -1;
}


int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		if (~notBinarySearch(v, x)) {

			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	//system("pause");
	return 0;
}