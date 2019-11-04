#include <iostream>
#include <vector>

using namespace std;

vector<vector<float>> inputGraph(int n);
void printGraph(vector<vector<float>> graph, int size);


int main() {
	int v;
	
	cout << "Enter the number of verticies ";
	cin >> v;

	vector<vector<float>> graph = inputGraph(v);
	printGraph(graph, v);

	vector<bool> visited(v + 1, false);

	vector<float> distances(v + 1, INFINITY);
	distances[1] = 0;
	
	vector<float> routes(v + 1, 1);

	int current = 1;

	while (~current) {
		visited[current] = true;
		
		float min = INFINITY;
		int indexOfMin = -1;

		for (int i = 1; i <= v; ++i) {
			if (visited[i]) continue;
			
			if (distances[i] > graph[current][i] + distances[current])
			{
				distances[i] = graph[current][i] + distances[current];
				routes[i] = current;
			}

			if (distances[i] < min) {
				min = distances[i];
				indexOfMin = i;
			}
		}

		current = indexOfMin;
	}

	cout << "Distances: ";
	for (int i = 1; i <= v; ++i) {
		cout << distances[i] << "\t";
	}

	cout << "\n\nRoutes: ";
	for (int i = 1; i <= v; ++i) {
		cout << routes[i] << "\t";
	}

	system("pause");
	system("pause");
	return 0;
}
/*
7
9
0
0
14
10
15
0
0
11
0
2
6
0
9

Distances: 0    7       9       20      20      11

Routes: 1       1       1       3       6       3



*/

vector<vector<float>> inputGraph(int n) {
	vector<vector<float>> graph(n + 1, vector<float>(n + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (i == j) {
				graph[i][j] = 0;
				continue;
			}

			cout << "\nEnter path length from vertex " << i << " to vertex " << j << endl;
			cout << "(if path does not exists, enter 0)\t    ";
			cin >> graph[i][j];
			
			if (!graph[i][j]) {
				graph[i][j] = INFINITY;
			}

			graph[j][i] = graph[i][j];

		}
	}

	return graph;
}

void printGraph(vector<vector<float>> graph, int size) {
	cout << endl;
	
	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= size; ++j) {
			cout << "\t" << graph[i][j];
		}
		cout << endl;
	}
	cout << endl;
}