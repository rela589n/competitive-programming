#include <iostream>
using namespace std;
typedef unsigned short int a;
int main() {
	a n, costs[100];
	cin >> n;
	costs[0] = 0;
	cin >> costs[1];
	for (a i = 2; i <= n; i++) {
		cin >> costs[i];
		costs[i] += (costs[i - 1] < costs[i - 2]) ? costs[i - 1] : costs[i - 2];
	}
	cout << costs[n];
	return 0;
}