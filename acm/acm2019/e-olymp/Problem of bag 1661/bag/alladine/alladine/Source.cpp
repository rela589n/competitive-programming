#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

struct subject
{
	Int weight;
	Int price;
};

Int gcd(Int a, Int b) {
	while (a && b) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	return a + b;
}

int main() {
	Int w, n;
	cin >> w >> n;
	vector<subject> subjects(n + 1);

	Int step = w;
	for (Int i = 1; i <= n; ++i) {
		cin >> subjects[i].weight;
		cin >> subjects[i].price;

		step = gcd(step, subjects[i].weight);
	}
	
	sort(subjects.begin(), subjects.end(), [](subject a, subject b) { return a.weight < b.weight; });

	vector<vector<Int>> dynamicTable(n + 1, vector<Int>(w / step + 1, 0));

	for (Int i = 1; i <= n; ++i) { // subjects (rows)
		for (Int j = 1; j < dynamicTable[i].size(); ++j) {
			
			Int weight = j * step;  // weight "index"
						
			Int goodsAvailable = weight / subjects[i].weight;
			dynamicTable[i][j] = max(
				dynamicTable[i - 1][j],
				goodsAvailable * subjects[i].price + dynamicTable[i - 1][j - goodsAvailable * subjects[i].weight / step]
			);
		}
	}

	/*for (Int i = 1; i <= n; ++i) {
		for (Int j = 1; j < dynamicTable[i].size(); ++j) {
			cout << dynamicTable[i][j] << "\t";
		}
		cout << endl;
	}*/

	cout << dynamicTable[n][w / step];

	//system("pause");
	return 0;
}
/*
11 3
1 1
6 21
5 19
 40

12 2
5 10
6 19
 38

13 3
1 3
5 10
6 19
 41

13 3
1 1
5 10
6 19
 39

2 1
2 100
*/

// base dynamic
/*

Int w, n;
	cin >> w >> n;
	vector<subject> subjects(n + 1);

	Int step = w;
	for (Int i = 1; i <= n; ++i) {
		cin >> subjects[i].weight;
		cin >> subjects[i].price;

		step = gcd(step, subjects[i].weight);
	}

	vector<vector<Int>> dynamicTable(n + 1, vector<Int>(w / step + 1, 0));

	for (Int i = 1; i <= n; ++i) {
		for (Int j = 1; j <= w / step; ++j) {

			if (subjects[i].weight > j * step) {
				dynamicTable[i][j] = dynamicTable[i - 1][j];
			}
			else {
				dynamicTable[i][j] = max(
					dynamicTable[i - 1][j],
					subjects[i].price + dynamicTable[i - 1][j - subjects[i].weight]
				);
			}
		}
	}

*/