#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> a, int val) {
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


int main() {
	vector<int> vec;

	int n;
	cin >> n;
	vec.reserve(n);
	
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		vec.push_back(val);
	}
start:

	int val;
	cin >> val;
	cout << binary_search(vec, val) << endl;

	goto start;
	cin.get();
	cin.get();
	return 0;
}