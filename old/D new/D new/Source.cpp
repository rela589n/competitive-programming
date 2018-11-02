#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int counters[100001] = { 0 };

	int maximumCounter = 0;
	int operation;
	int prevOperation = n + 1; 

	for (int i = 0; i < m; ++i) {
		cin >> operation;

		if (operation == n + 1)
		{
			if (prevOperation == n + 1) continue;

			for (int j = 0; j < n; ++j) {	
				counters[j] = maximumCounter;
			}
			prevOperation = n + 1;
		}
		else {
			int checkMax = ++counters[operation - 1];

			if (maximumCounter < checkMax) {
				maximumCounter = checkMax;
			}

			prevOperation = operation;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << counters[i] << ' ';
	}

	//system("pause");
	return 0;
}