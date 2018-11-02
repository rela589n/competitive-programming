#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ball {
	int cost;
	int refill;
	bool white;
};

bool m_compare(const ball& a, const ball& b) {
	return a.cost > b.cost;
}


int main() {
	int n;
	cin >> n;

	vector<ball> balls(n);
	for (int i = 0; i < n; ++i) {
		cin >> balls[i].cost;
	}
	
	for (int i = 0; i < n; ++i) {
		cin >> balls[i].refill;
	}
	cin.get();

	for (int i = 0; i < n; ++i) {
		char tmp;
		cin.get(tmp);

		balls[i].white = tmp == 'W';
	}

	sort(balls.begin(), balls.end(), m_compare);

	bool player = true;
	unsigned long long first = 0,
		second = 0;

	for (int i = 0; i < n; ++i)
	{
		if (balls[i].refill % 2) 
		{
			balls[i].white = player;

			player = !player;
		}

		if (balls[i].white) {
			first += balls[i].cost;
		}
		else {
			second += balls[i].cost;
		}
	}

	cout << first << ' ' << second << endl;

	return 0;
}
