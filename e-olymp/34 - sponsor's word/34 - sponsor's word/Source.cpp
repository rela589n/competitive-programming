#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;
const long long INF = 2147483647;

vector<Int> getDistances(vector< vector<Int> > graph, Int start);
Int getMinDistanceVertex(vector<Int> dist, vector<bool> visited);

int main() {
	Int n, gifts, terms;
	cin >> n >> gifts >> terms;

	vector<Int> winners(gifts);
	for (Int i = 0; i < gifts; ++i) {
		cin >> winners[i];
	}

	vector< vector<Int> > graph(n, vector<Int>(n, INF));
	for (Int i = 0; i < terms; ++i) {
		Int a, b, t;
		cin >> a >> b >> t;

		graph[a - 1][b - 1] = graph[b - 1][a - 1] = t;
	}

	for (Int i = 0; i < n; ++i) {
		graph[i][i] = 0;
	}

	Int start;
	cin >> start;
	--start;
	
	
	vector<Int> distances = getDistances(graph, start);
	Int max = 0;
	for (Int i = 0; i < gifts; ++i) {
		if (distances[winners[i] - 1] > max) {
			max = distances[winners[i] - 1];
		}
	}
	
	if (max != INF) {
		cout << "The good sponsor!" << endl;
		cout << max;
	}
	else {
		cout << "It is not fault of sponsor..." << endl;
	}
	
	system("pause");
	return 0;
}


vector<Int> getDistances(vector< vector<Int> > graph, Int start) {
	Int n = graph.size();
	vector<bool> visited(n, false);
	vector<Int> distances(n, INF);
	distances[start] = 0;

	Int current = start;
	while (~current) {
		visited[current] = true;

		for (Int i = 0; i < n; ++i) {
			if (!visited[i] && graph[current][i] + distances[current] < distances[i]) {
				distances[i] = graph[current][i] + distances[current];
			}
		}

		current = getMinDistanceVertex(distances, visited);
	}

	return distances;
}

Int getMinDistanceVertex(vector<Int> dist, vector<bool> visited) {
	Int min = INF;
	Int indx = -1;

	for (Int i = 0; i < dist.size(); ++i) {
		if (!visited[i] && dist[i] < min) {
			min = dist[i];
			indx = i;
		}
	}

	return indx;
}

/*


10 3 3
1 2 3
1 2 10
1 3 15
2 3 20
1


10 3 3
1 1 1
1 3 7
1 5 100
2 5 9
1

	*/