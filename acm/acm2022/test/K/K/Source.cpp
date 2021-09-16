#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;

int n;
int vec[2 * 100000 + 2] = {};
int counts[2 * 100000 + 2] = {};
int previousZerosCount[2 * 100000] = {};
int remOp = 0;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int left = -1;
	int right = 2 * 100000 + 2;


	int m;
	cin >> n >> m;

	//unordered_map<int, int> counts = unordered_map<int, int>(n);

	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		++counts[vec[i]];

		left = max(left, vec[i]);
		right = min(right, vec[i]);
	}

	int lastZeros = 0;
	for (int i = 1; i <= n; ++i) {
		remOp += max(counts[i] - lastZeros - 1, 0);

		if (counts[i] == 0) {
			lastZeros += 1;
		} else {
			previousZerosCount[i] = lastZeros;
			lastZeros = 0;
		}
	}

	cout << remOp;
	return 0;
/*


1: 1
5: 4
9: 4


Sum of
1 - 0 - 1
4 - 3 - 1
4 - 3 - 1
c,  z,  1

c - count of corresponding numbers
z - previous zeros count
1 - 1



7 7 7 7 7 7 6

7 => 6
6 => 1

Either 6 => 1 or 6 => 7


1 - no changes necessary

1 2
1 1 => 1->2
2 2 - no changes necessary


1 1 1 => 1->2, 1->3
1 => 3
2 => 0
3 => 0

1 1 2 => 1->3
1 => 2
2 => 1
3 => 0

1 2 2 => 2->3 or 1->3
1 => 1
2 => 2
3 => 0

1 2 3 => no changes necessary
1 => 1
2 => 1
3 => 1

2 2 3 => no changes necessary
1 => 0
2 => 2
3 => 1

2 3 3 => 2->3 or 3->1 or 3->2
1 => 0
2 => 1
3 => 2




10: {
 count => 3,
 freeZeros = 3
  
}





1
1

2
1 2
2 2
1 1
// 0, 1

3
1 1 1
1 1 2
1 3 3 // 1
1 2 2
1 3 3
2 2 2
3 3 3

1 4 4 4 // 1


7 0

3 3 3 4 4 4 4
// 3

3 => 3
4 => 4


7 0
3 3 3 3 4 4 4
// 3
3 => 4
4 => 3


7 0
3 3 3 3 5 5 5

1 => 1
2 => 1
3 => 1
  ||
1 => 0
2 => 0
3 => 3
  ||
1 => 1
2 => 0
3 => 2

7 0
7 7 7 7 7 7 6

4 0
4 4 4 4

5 0
5 5 5 2 2

7 0
3 3 3 4 7 7 7

*/
	for (int t = 0; t < m; ++t) {
		int position, newValue;
		cin >> position >> newValue;
		--position;

		if (vec[position] != newValue) {

			int prevValue = vec[position];

			// update values
			--counts[prevValue];
			++counts[newValue];

			left = max(left, newValue);

		}

		cout << remOp << endl;
	}

	return 0;
}

/*
4 4
4 4 4 4
4 1
3 1
1 1
2 1


10 10
8 7 2 9 10 6 6 5 5 4
8 1
6 3
6 2
7 10
9 7
9 9
2 4
8 1
1 8
7 7

*/