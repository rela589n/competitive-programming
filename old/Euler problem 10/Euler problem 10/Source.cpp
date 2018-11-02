#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef unsigned uint;
bool isNumberSimple(vector<int>& simpleNumbers, uint simpleNumbersLen, int searchNumber);

int main() {
	uint n;
	cin >> n;

	vector<bool> isSimple(n + 1, true);

	for (uint i = 2; i*i <= n; i++) {
		if (isSimple[i]) {
			for (uint j = i * i; j <= n; j += i) {
				isSimple[j] = false;
			}

		}

	}

	vector<int> simple;
	simple.reserve(300000);
	uint simpleLen = 0;

	for (uint i = 2; i <= n; i++)
	{
		if (isSimple[i]) {
			simple.push_back(i);
			++simpleLen;
		}
	}

	unsigned long long sum = 0;

	for (int i = 0; i < simpleLen; ++i) {
		sum += simple[i];
	}

	cout << sum;

	system("pause");
	return 0;
}

bool isNumberSimple(vector<int>& simpleNumbers, uint simpleNumbersLen, int searchNumber) {
	int l = 0,
		r = simpleNumbersLen - 1;

	while (l < r) {
		int cen = (l + r) / 2;

		if (searchNumber > simpleNumbers[cen]) {
			l = cen + 1;
		}
		else if (searchNumber < simpleNumbers[cen]) {
			r = cen - 1;
		}
		else {
			l = r = cen;
		}
	}

	return (simpleNumbers[l] == searchNumber);
}