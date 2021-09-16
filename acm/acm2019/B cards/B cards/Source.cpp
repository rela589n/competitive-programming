#include <iostream>
#include <vector>

typedef long long Int;
const Int INF = 2147483647;

using namespace std;

struct elem
{
	Int prior = INF;	
	Int num = 0;
} INF_El;

vector<Int> input(vector<elem> &elems, int n) {
	vector<bool> used(2 * n, false);
	vector<Int> mirrorElems(n);

	Int priority = 0;

	for (int i = 0; i < 2 * n; ++i) {
		cin >> elems[i].num;
		--elems[i].num;

		if (used[elems[i].num]) {
			elems[i].prior = ++priority;

			elems[mirrorElems[elems[i].num]].prior = elems[i].prior;
		}

		used[elems[i].num] = true;
		mirrorElems[elems[i].num] = i;
	}

	return mirrorElems;
}

int main()
{
	INF_El.num = -1;
	INF_El.prior = INF;

	Int n;
	cin >> n;
	
	if (n == 1) {
		cout << 1;
		return 0;
	}

	vector<elem> elems(2 * n);
	vector<Int> mirror = input(elems, n);

	Int res = 0;
	
	elem f1 = elems[0];
	elem f2 = elems[1];
	elem f3 = elems[2];

	Int l = 3;

	while (l < 2 * n) {
		if (f1.num == f2.num) {
			++res;
			f1 = f3;
			f2 = elems[l++];

			if (l < 2 * n) {
				f3 = elems[l++];
			}
			else {
				f3 = INF_El;
			}
		}
		else if (f2.num == f3.num) {
			++res;
			f2 = elems[l++];

			if (l < 2 * n) {
				f3 = elems[l++];
			}
			else {
				f3 = INF_El;
			}
		}
		else if (f1.num == f3.num) {
			++res;

			f1 = f2;
			f2 = elems[l++];

			if (l < 2 * n) {
				f3 = elems[l++];
			}
			else {
				f3 = INF_El;
			}
		}
		else if (f1.prior > f2.prior) {
			elems[mirror[f1.num]].prior = INF;

			f1 = f2;
			f2 = f3;
			f3 = elems[l++];
		}
		else { //f2.prior > f1.prior
			elems[mirror[f2.num]].prior = INF;

			f2 = f3;
			f3 = elems[l++];
		}
	}

	if (f1.num == f2.num || f1.num == f3.num || f2.num == f3.num) {
		++res;
	}
	
	cout << res;
//	system("pause");
	return 0;
}

/*

5
1 4 2 2 4 3 5 5 3 1

7
1 4 2 5 6 2 7 7 1 3 4 6 3 5

9
7 9 1 8 3 4 5 1 2 4 5 6 6 9 8 7 3 2

	*/
