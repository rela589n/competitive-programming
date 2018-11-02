#include <iostream>
#include <string>


using namespace std;

static BigInteger ProdTree(int l, int r)
{
    if (l > r)
        return 1;
    if (l == r)
         return l;
    if (r - l == 1)
        return (BigInteger)l * r;
    int m = (l + r) / 2;
    return ProdTree(l, m) * ProdTree(m + 1, r);
}
        
static BigInteger FactTree(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1 || n == 2)
        return n;
    return ProdTree(2, n);
}        


int main() {

	// входные данные
	int n;
	cin >> n;

	vector < vector<int> > g;
	for (int i = 0; i < n; ++i) {
		vector<int> curr(n);
		
		for (int j = 0; j < n; ++j) {
			cin >> curr[j];
		}

		g.push_back(curr);
		curr.clear();
	}
	
	const int INF = 1000000000; // значение "бесконечность"

	// алгоритм
	vector<bool> used(n);
	vector<int> min_e(n, INF), sel_e(n, -1);
	min_e[0] = 0;
	for (int i = 0; i < n; ++i) {
		int v = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INF) {
			cout << "No MST!";
			exit(0);
		}

		used[v] = true;
		if (sel_e[v] != -1)
			cout << v << " " << sel_e[v] << endl;

		for (int to = 0; to < n; ++to)
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}


	system("pause");
	return 0;
}

