#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> roads(m);
	for (int i = 0; i < m; ++i) {
		cin >> roads[i].first >> roads[i].second;
	}


	system("pause");
	return 0;
}