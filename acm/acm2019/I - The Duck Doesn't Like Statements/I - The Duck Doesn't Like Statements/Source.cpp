#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>

typedef long long Int;
const long long INF = 2147483647;

using namespace std;

bool solve(vector<int>& vec, int n, int k) {
	list<int> zeros;

	Int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);

		if (!vec[i]) {
			zeros.push_back(i);
			vec[i] = 1;
		}

		sum += vec[i];
	}

	if (sum <= 0) {
		return false;
	}
	if (sum % k == 0) {
		return true;
	}

	for (auto i = zeros.begin(); i != zeros.end(); ++i)
	{
		vec[*i] = -1;
		sum -= 2;

		if (sum % k == 0) {
			if (sum > 0) {
				return true;
			}
			return false;
		}
	}

	return false;
}

int main() {
	Int n, k;
	cin >> n >> k;

	vector<int> elems(n);

	if (solve(elems, n, k)) {
		printf("Yes\n");

		for (Int i = 0; i < n; ++i) {
			printf("%d ", elems[i]);
		}
	}
	else {
		printf("No");
	}

	//system("pause");
	return 0;
}

/*
4 2
-1 -1 0 0

4 4
0 0 -1 0

6 2
-1 -1 1 1 1 1

21 7
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0

6 3
1 1 1 0 0 0

8 2
1 1 1 0 0 0 0 0

8 2
-1 -1 -1 0 0 0 0 0

7 2
-1 -1 -1 0 0 0 0
*/
