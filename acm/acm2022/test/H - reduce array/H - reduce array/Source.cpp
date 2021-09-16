#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	auto vec = vector<int>(n);
	

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}

	for (int i = n - 1; i > 0; --i) {
		if (vec[i - 1] <= vec[i]) {
			continue;
		}

		--vec[i - 1];

		if (vec[i - 1] <= vec[i]) {
			continue;
		}

		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	return 0;
}

/*

n = int(input())
ar = [int(i) for i in input().split()]
for i, el in enumerate(ar):
	if i < 1:
		continue
	if ar[i - 1] <= ar[i]:
		continue
	if ar[i - 1] <= ar[i]:
		print (i)
print (ar)


*/