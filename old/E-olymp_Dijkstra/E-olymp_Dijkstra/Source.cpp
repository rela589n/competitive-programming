#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> inputGraph(int n);
int getMinDistanceVertex(vector<int> arr, vector<bool> visited);

const int INF = 2147483647;

int main() {

	int v, a, b;
	cin >> v >> a >> b; 

	if (v == 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<vector<int>> graph = inputGraph(v);

	vector<bool> visited(v + 1, false);

	vector<int> distances(v + 1, INF);
	distances[a] = 0;

	int current = a;
	while (~current) {
		visited[current] = true;

		for (int i = 1; i <= v; ++i) {
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

int getMinDistanceVertex(vector<int> arr, vector<bool> visited) {
	int min = INF;
	int index = -1;

	for (int i = 1; i < arr.size(); ++i) {
		if (!visited[i] && arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}

	return index;
}

vector<vector<int>> inputGraph(int n) {
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> graph[i][j];

			if (graph[i][j] == -1) {
				graph[i][j] = INF;
			}
		}
	}

	return graph;
}