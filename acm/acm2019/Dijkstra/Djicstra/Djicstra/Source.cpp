#include <iostream>
#include <vector>

using namespace std;

typedef long long Int;
typedef long double Double;
const Int INF = 2147483647;

int main() {
	Int v, a, b;
	cin >> v >> a >> b;

	if (v == 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<vector<Int>> graph = inputGraph(v);

	vector<bool> visited(v + 1, false);

	vector<Int> distances(v + 1, INF);
	distances[a] = 0;

	Int current = a;
	while (~current) {
		visited[current] = true;

		for (Int i = 1; i <= v; ++i) {
			if (!visited[i] &&
				distances[i] - distances[current] > graph[current][i])
			{
				distances[i] = graph[current][i] + distances[current];
			}
		}

		current = getMinDistanceVertex(distances, visited);
	}

	if (distances[b] == INF) {
		distances[b] = -1;
	}
	cout << distances[b];

	system("pause");
	return 0;
}

vector<vector<Int>> inputGraph(Int n) {
	vector<vector<Int>> graph(n + 1, vector<Int>(n + 1));

	for (Int i = 1; i <= n; ++i) {
		for (Int j = 1; j <= n; ++j) {
			cin >> graph[i][j];

			if (graph[i][j] == -1) {
				graph[i][j] = INF;
			}
		}
	}

	return graph;
}

Int getMinDistanceVertex(vector<Int> arr, vector<bool> visited) {
	Int min = INF;
	Int index = -1;

	for (Int i = 1; i < arr.size(); ++i) {
		if (!visited[i] && arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}

	return index;
}