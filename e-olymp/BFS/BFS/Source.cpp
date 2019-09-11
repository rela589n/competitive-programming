#include <iostream>
#include<algorithm> 
#include <queue>
#include <list>
#include <vector>

using namespace std;

typedef long long Int;
const Int INF = 2147483647;

class Graph
{
	int numVertices;
	vector< list<int> > graph;
	vector<bool> visitedBFS;
	
	vector<Int> distance;
	vector<Int> parent;

	void DFSUtil(int v, vector<bool>& visited);
public:
	Graph(int vertices);
	void addEdge(int src, int dest);
	void BFS(int startVertex);
	
	Int minDistance(int start, int finish);
	vector<int> path(int to);

	void DFS(int v);
};

Graph::Graph(int vertices)
{
	numVertices = vertices;
	graph = vector< list<int> > (vertices);
}

void Graph::addEdge(int src, int dest)
{
	graph[src].push_back(dest);
	//graph[dest].push_back(src);
}

void Graph::BFS(int startVertex)
{
	visitedBFS = vector<bool>(numVertices, false);
	
	queue<int> q;

	visitedBFS[startVertex] = true;
	q.push(startVertex);

	distance = vector<Int>(numVertices);
	parent = vector<Int>(numVertices);

	parent[startVertex] = -1;

	list<int>::iterator i;
	while (!q.empty())
	{
		int currVertex = q.front();
		//cout << "Visited " << currVertex << " ";
		q.pop();

		for (i = graph[currVertex].begin(); i != graph[currVertex].end(); ++i)
		{
			int to = *i;
			if (!visitedBFS[to])
			{
				visitedBFS[to] = true;
				q.push(to);

				distance[to] = distance[currVertex] + 1;
				parent[to] = currVertex;
			}
		}
	}
}

Int Graph::minDistance(int start, int finish) 
{
//	BFS(start);
	return distance[finish];
}
vector<int> Graph::path(int to) {
	if (!visitedBFS[to]) {
		return vector<int>(0);
	}
	vector<int> _path;
	_path.reserve(100);

	for (int v = to; ~v; v = parent[v]) {
		_path.push_back(v);
	}
	
	reverse(_path.begin(), _path.end());
	return _path;
}


void Graph::DFSUtil(int v, vector<bool>& visited)
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	cout << v + 1 << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i;
	for (i = graph[v].begin(); i != graph[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v)
{
	vector<bool> visited(numVertices, false);

	DFSUtil(v, visited);
}

int main()
{
	Int _n, m;
	cin >> _n >> m;
	Graph _g(_n + 1);
	for (int i = 0; i < m; ++i) {
		int s, f;
		cin >> s >> f;
		--s;
		--f;
		_g.addEdge(s, f);
		_g.addEdge(f, s);
	}
	int v;
	cin >> v;
	--v;
	_g.DFS(v);
	
	system("pause");
	return 0;

	Int n, s, f;
	cin >> _n >> s >> f;
	--s;
	--f;
	Graph g(_n);

	bool tmp;
	for (Int i = 0; i < _n; ++i) {
		for (Int j = 0; j < _n; ++j) {
			cin >> tmp;

			if (tmp) {
				_g.addEdge(i, j);
				//g.addEdge(j, i);
			}
			
		}
	}

	cout << _g.minDistance(s, f);

	//system("pause");
	return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
#include "HashMap.h"

typedef long long Int;
const long long INF = 2147483647;
using namespace std;



int main()
{
	Int n, s, f;
	cin >> n >> s >> f;
	vector < vector<bool> > graph(n, vector<bool>(n));
	
	bool tmp;
	for (Int i = 0; i < n; ++i) {
		for (Int j = 0; j < n; ++j) {
			cin >> tmp;
			graph[i][j] = tmp;
		}
	}




	system("pause");
	return 0;
}*/