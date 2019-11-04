#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<float>> inputGraph(int n);

template <class T>
void printGraph(vector<vector<T>> graph, int size);

int main() {
	int v;

	cout << "Enter the number of verticies ";
	cin >> v;

	vector<vector<float>> graph = inputGraph(v);
	vector<vector<float>> distances(graph);
	
	printGraph(graph, v);
	printGraph(distances, v);

	vector<vector<int>> routes(v, vector<int>(v));
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j) {
			routes[i][j] = i;
		}
	}

	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			if (i == k || distances[i][k] == INFINITY) continue;
			
			for (int j = 0; j < v; ++j) {
				if (distances[i][j] > distances[k][j] + distances[i][k]) {
					distances[i][j] = distances[k][j] + distances[i][k];
					routes[i][j] = k;
				}
			}
		}
	}

	printGraph(distances, v);
	printGraph(routes, v);

	int from, to;
	cin >> from >> to;
	stack<int> path;
	
	while (true) {

	}


	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
	return 0;
}



vector<vector<float>> inputGraph(int n) {
	vector<vector<float>> graph(n, vector<float>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (i == j) {
				graph[i][j] = 0;
				continue;
			}

			cout << "\nEnter path length from vertex " << 1 + i << " to vertex " << 1 + j << endl;
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

template <class T>
void printGraph(vector<vector<T>> graph, int size) {
	cout << endl;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << "\t" << graph[i][j];
		}
		cout << endl;
	}
	cout << endl;
}