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

	cout << step << endl;
	system("pause");
	
	vector<vector<Int>> dynamicTable(n + 1, vector<Int>(w + 1, 0));
	
	for (Int i = 1; i <= n; ++i) {
		for (Int j = 1; j <= w; ++j) {
			/*
			if (1 < j) {
				dynamicTable[i][j] = dynamicTable[i - 1][j];
			}
			else {
			*/
				dynamicTable[i][j] = max(dynamicTable[i - 1][j], subjects[i] + dynamicTable[i - 1][j - 1]);
			//}
		}
	}

	cout << dynamicTable[n][w] << endl;

	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	return 0;
}