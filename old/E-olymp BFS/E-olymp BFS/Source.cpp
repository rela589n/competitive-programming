#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> breadth_first_search(vector< vector<bool> > &graph, int length, int start) {
	
	vector<int> way;
	way.reserve(length);

	queue<int> search_q;
	search_q.push(start);

	vector<bool> used(length);
	used[start] = true;

	while (!search_q.empty()) {
		int current = search_q.front();
		search_q.pop();
		way.push_back(current);

		for (int i = 0; i < graph[current].size(); ++i) {
			int to = graph[current][i];
			if (!used[to]) {
				used[to] = true;
				search_q.push(to);
			}
		}
	}

	return way;
	
}

int main() {
	int n, m, v;

	cin >> n >> m >> v;

	if (m < 1) {
		cout << 1 << endl;
		cout << v;
		return 0;
	}

	vector< vector<bool> > graph(n, vector<bool>(n, false));

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		graph[a][b] = graph[b][a] = true;
	}

	vector<int> way = breadth_first_search(graph, n, --v);
	cout << way.size() << endl;
	for (int i = 0; i < way.size(); ++i) {
		cout << way[i] + 1 << ' ';
	}

	cin.get();
	cin.get();
	cin.get();
	return 0;
}