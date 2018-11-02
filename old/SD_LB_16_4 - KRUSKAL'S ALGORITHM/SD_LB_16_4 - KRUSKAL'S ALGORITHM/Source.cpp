#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int vertex1;
	int vertex2;
	int weight;
};

void inputEdges(vector<edge>& edges, int n);
void printEdges(vector<edge>& edges, int n);
void printEdge(const edge& edg);

int main() {
	int verticies, pairs;

	cout << "Enter amount of verticies and amount of pairs: ";
	cin >> verticies >> pairs;

	vector<edge> edges(pairs);
	inputEdges(edges, pairs);

	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
		return a.weight < b.weight;
	});

	vector<int> components(verticies);
	for (int i = 0; i < verticies; ++i) {
		components[i] = i;
	}

	cout << "\n\n\t\t\tKruskal's algorithm:\n";

	for (int i = 0; i < pairs; ++i) {
		int a = edges[i].vertex1;
		int b = edges[i].vertex2;

		if (components[a] == components[b]) continue;

		printEdge(edges[i]);

		int newComponent = components[b];

		for (int j = 0; j < verticies; ++j) {
			if (components[j] == newComponent) {
				components[j] = a;
			}
		}
	}

	/*
	5 6

	1 2 8
	2 4 7
	2 3 8
	3 4 1
	3 5 4
	4 5 5

	*/
	

	
	system("pause");
	system("pause");
	system("pause");

	return 0;
}

/*

1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 4 11
3 6 2
4 5 6
5 6 9

*/

void inputEdges(vector<edge>& edges, int n) {

	for (int i = 0; i < n; ++i) {
		cout << "Edge " << i + 1 << ":\n";

		cout << "Enter vertex 1: ";
		cin >> edges[i].vertex1;
		--edges[i].vertex1;

		cout << "Enter vertex 2: ";
		cin >> edges[i].vertex2;
		--edges[i].vertex2;

		cout << "Enter edge weight: ";
		cin >> edges[i].weight;

	}
}

void printEdges(vector<edge>& edges, int n) {

	for (int i = 0; i < n; ++i) {
		cout << "\nEdge " << i << ":\n";

		printEdge(edges[i]);

	}
}

void printEdge(const edge& edg) {
	
	cout << "Vertex 1: ";
	cout << 1 + edg.vertex1;

	cout << "\nVertex 2: ";
	cout << 1 + edg.vertex2;

	cout << "\nEdge weight: ";
	cout << edg.weight;

	cout << endl;
}