#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<float>> inputGraph(int n);
void printGraph(vector<vector<float>> graph, int size);

int main() {
	int v;

	cout << "Enter the number of verticies ";
	cin >> v;

	vector<vector<float>> graph = inputGraph(v);
	printGraph(graph, v);

	vector<bool> used(v, false);
	vector<float> minEdges(v, INFINITY);
	vector<int> minEdgesStart(v, -1);

	int current = 0;
	while (~current) {
		// Просматриваем вершину current
		used[current] = true;

		// перебираем все рёбра, которые идут в текущую просматриваемую вершину
		// для каждой ещё не выбраной вершины храним минимальный вес ребра, которое идёт из неё в выбраную вершину
		// и еще ищем минимальное среди всех минимальных рёбер, и делаем его поточным
		
		float min = INFINITY;
		int indexOfMin = -1;

		for (int i = 0; i < v; ++i) {
			if (used[i]) continue;

			if (graph[current][i] < minEdges[i])
			{
				minEdges[i] = graph[i][current];
				minEdgesStart[i] = current;
			}

			if (min > minEdges[i])
			{
				min = minEdges[i];
				indexOfMin = i;
			}
		}
		current = indexOfMin;
	}

	for (int i = 1; i < v; ++i) {
		cout << i + 1 << " with " << minEdgesStart[i] + 1 << " => " << minEdges[i] << endl;
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


*/


vector<vector<float>> inputGraph(int n) {
	vector<vector<float>> graph(n, vector<float>(n));
	cout << "\n\nEnter info about routes between verticies" << endl;
	cout << "\n(if path does not exists, enter 0) \n\n";

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (i == j) {
				graph[i][j] = INFINITY;
				continue;
			}

			cout << "\nEnter path length from vertex " << i + 1 << " to vertex " << j + 1 << ": ";
			
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

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << "\t" << graph[i][j];
		}
		cout << endl;
	}
	cout << endl;
}