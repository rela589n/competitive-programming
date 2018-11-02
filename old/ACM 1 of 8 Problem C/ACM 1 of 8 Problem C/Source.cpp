#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dishes(n);
	map<int, int> numberOfEntries;

	for (int i = 0; i < n; ++i) {
		cin >> dishes[i];
		++numberOfEntries[dishes[i]];
	}

	int ans = 0;

	int max, maxQ;
	do {
		max = dishes[0];
		maxQ = numberOfEntries[max];

		for (int i = 1; i < n; ++i)
		{
			int currentQ = numberOfEntries[dishes[i]];

			if (maxQ < currentQ) {
				maxQ = currentQ;
				max = dishes[i];
			}
		}

		if (maxQ > 0) {
			++ans;
			for (int i = 0; i < n; ++i) {
				if (dishes[i] >= max) {
					dishes[i] -= max;
				}
			}

			for (auto &elem : numberOfEntries) {
				elem.second = 0;
			}

			for (int i = 0; i < n; ++i) {
				++numberOfEntries[dishes[i]];
			}
		}
	} while (maxQ && max);

	
	cout << ans;
	//cin.get();
	return 0;
}