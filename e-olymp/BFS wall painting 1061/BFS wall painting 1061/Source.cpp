#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long Int;
const Int INF = 2147483647;

struct item {
	// 0 - new empty space, 1 - wall, 2 - processed empty space
	short status = 0;
	int x, y;
};

void printVector(vector< vector<item> > a) {
	for (Int i = 0; i < a.size(); ++i) {
		for (Int j = 0; j < a[i].size(); ++j) {
			cout << a[i][j].status << " ";
		}

		cout << endl;
	}
	cout << endl;
}

Int paintWalls(vector < vector <item> >& g, int sX, int sY) {
	queue<item> q;

	if (g[sX][sY].status == 0) {
		q.push(g[sX][sY]);
		g[sX][sY].status = 2;
	}

	Int walls = 0;
	while (!q.empty()) {
		item el = q.front();
		q.pop();

		int x = el.x;
		int y = el.y;

		switch (g[x - 1][y].status) {
		case 1:
			++walls;
			break;
		case 0:
			q.push(g[x - 1][y]);
			g[x - 1][y].status = 2;
			break;
		}

		switch (g[x][y - 1].status) {
		case 1:
			++walls;
			break;
		case 0:
			q.push(g[x][y - 1]);
			g[x][y - 1].status = 2;
			break;
		}

		switch (g[x + 1][y].status) {
		case 1:
			++walls;
			break;
		case 0:
			q.push(g[x + 1][y]);
			g[x + 1][y].status = 2;
			break;
		}

		switch (g[x][y + 1].status) {
		case 1:
			++walls;
			break;
		case 0:
			q.push(g[x][y + 1]);
			g[x][y + 1].status = 2;
			break;
		}
	}

	return walls;
}

int main()
{
	Int n;
	cin >> n;
	vector < vector <item> > g(n + 2, vector<item> (n + 2));

	for (Int i = 0; i < n + 2; ++i) {
		g[i][0].status = 1;
		g[i][n + 1].status = 1;
	}

	for (Int j = 0; j < n + 2; ++j) {
		g[0][j].status = 1;
		g[n + 1][j].status = 1;
	}

	for (Int i = 0; i < n + 2; ++i) {
		for (Int j = 0; j < n + 2; ++j) {
			g[i][j].x = i;
			g[i][j].y = j;
		}
	}

	//printVector(g);

	char sym;
	for (Int i = 1; i <= n; ++i) {
		for (Int j = 1; j <= n; ++j) {
			cin >> sym;
			if (sym == '#') {
				g[i][j].status = 1;
			}
		}
	}

	

	g[0][0].status = 2;
	g[1][0].status = 2;
	g[0][1].status = 2;
	g[n + 1][n].status = 2;
	g[n][n + 1].status = 2;
	g[n + 1][n + 1].status = 2;
		
	
	Int walls = paintWalls(g, 1, 1);
	
	walls += paintWalls(g, n, n);
	
	//printVector(g);

	//cout << walls << endl;
	cout << walls * 9 << endl;

	system("pause");
	return 0;
}
