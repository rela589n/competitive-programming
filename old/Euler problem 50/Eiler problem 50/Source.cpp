#include <iostream>
#include <ctime>
#include <vector>
#include <utility>

using namespace std;

typedef unsigned uint;
bool isNumberSimple(vector<int>& simpleNumbers, uint simpleNumbersLen, int searchNumber);
pair<int, int> findSimple(int searchNumber, vector<int>& simpleNumbers, uint simpleNumbersLen, uint l, uint r, uint firstQuantityOfUsed, uint& maxQuantityOfUsed);

int main() {
	
	uint n;
	cin >> n;

	size_t start = clock();

	vector<bool> isSimple(n + 1, true);

	for (uint i = 2; i*i <= n; ++i) 
	{
		if (isSimple[i]) 
		{
			for (uint j = i * i; j <= n; j += i) {
				isSimple[j] = false;
			}
		}
			
	}

	vector<int> simple(78499);

	uint simpleLen = 0;
	for (uint i = 2; i <= n; i++) 
	{
		if (isSimple[i]) {
			simple[simpleLen++] = i;
		}
	}

	uint sum = 0;
	uint i;	

	for (i = 0; i < simpleLen; ++i) {
		
		sum += simple[i];

		if (sum >= n) {
			break;
		}		
	}

	uint l = 0;
	uint r = i;
	uint maxq = 2147483647;
	
	pair<int, int> res = findSimple(sum, simple, simpleLen, l, r, r - l, maxq);

	cout << res.first << endl;
	cout << res.second << endl;

	size_t end = clock();
	cout << "Time: " << end - start << endl;

	system("pause");
	return 0;
}
// first is number,
// second is quantity of operations
pair<int, int> findSimple(int searchNumber, vector<int>& simpleNumbers, uint simpleNumbersLen, uint l, uint r, uint firstQuantityOfUsed, uint& maxQuantityOfUsed) 
{
	pair<int, int> result;
	result.first = searchNumber;
	result.second = l + firstQuantityOfUsed - r;

	if (result.second > maxQuantityOfUsed) {
		result.second = 2147483647;
		return result;
	}

	if (isNumberSimple(simpleNumbers, simpleNumbersLen, searchNumber)) {
		maxQuantityOfUsed = result.second;
		return result;
	}

	pair<int, int> a = findSimple(searchNumber - simpleNumbers[l], simpleNumbers, simpleNumbersLen, l + 1, r, firstQuantityOfUsed, maxQuantityOfUsed);
	pair<int, int> b = findSimple(searchNumber - simpleNumbers[r], simpleNumbers, simpleNumbersLen, l, r - 1, firstQuantityOfUsed, maxQuantityOfUsed);

	if (a.second < b.second) {
		return a;
	}

	return b;
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