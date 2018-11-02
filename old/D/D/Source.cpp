#include <iostream>
#include <vector>

using namespace std;

void increase(int x, vector<int> &counters) {
	++counters[x];
}

void setVal(int val, vector<int> &counters) {
	int len = counters.size();
	
	for (int i = 0; i < len; ++i) {
		counters[i] = val;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> counters(n, 0);

	int maxNumber = 0, 
	   setMax = n + 1,
	   current;

	for (int i = 0; i < m; ++i) {
		cin >> current;

		if (current == setMax) {
			setVal(maxNumber, counters);
		}
		else {
			increase(current - 1, counters);

			if (maxNumber < counters[current - 1]) {
				maxNumber = counters[current - 1];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << counters[i] << endl;
	}

	system("pause");
	return 0;
}