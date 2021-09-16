#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int valuePresent(vector<int>& vec, int val) {

}

int main() {
	srand((unsigned)time(0));
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		if (~valuePresent(v, x)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	system("pause");
	return 0;
}