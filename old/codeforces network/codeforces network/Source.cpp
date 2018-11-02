#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int bfs(map< int, list<int> > &graph, int start, vector<int> &ans) {
	int n = graph.size();
	ans.reserve(n);
	
	int component = 0;
	
	vector<bool> used(n, false);
	used[start] = true;

	queue<int> search_q;
	search_q.push(start);

	while (!search_q.empty()) {
		int current = search_q.front();
		search_q.pop();

		ans.push_back(current);
		++component;

		for (auto i : graph[current]) {
			if (!used[i]) {
				used[i] = true;
				search_q.push(i);
			}
		}
	}

	return component;
}


int main() {
	int n, m;
	cin >> n >> m;
	map< int, list<int> > graph;

	for (int i = 0; i < m; ++i) {
		int quant;
		cin >> quant;
		
		vector<int> line(quant);
		for (int j = 0; j < quant; ++j) {
			int k;
			cin >> k;

			line[j] = k - 1;
		}

		for (int j = 0; j < quant; ++j) {
			for (int k = j + 1; k < quant; ++k)
			{
				graph[line[j]].push_back(line[k]);
				graph[line[k]].push_back(line[j]);
			}
		}

	}

	vector<bool> used(n, false);
	vector<int> components(n);
	

	int current = 0;
	while (~current) {
		vector<int> new_components;
		int similar = bfs(graph, current, new_components);

		for (int i = 0; i < new_components.size(); ++i) {
			components[new_components[i]] = similar;
			used[new_components[i]] = true;
		}

		current = -1;
		for (int i = current + 1; i < n; ++i) {
			if (!used[i]) {
				current = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << components[i] << " ";
	}

	/*
7 5
3 2 5 4
0
2 1 2
1 1
2 6 7
	*/
	
}