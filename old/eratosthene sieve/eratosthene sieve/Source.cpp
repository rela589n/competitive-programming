#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
	ull simpleLen;
	cin >> simpleLen;

	vector<bool> isSimple(simpleLen + 1, true);

	for (ull i = 2; i*i <= simpleLen; ++i)
	{
		if (isSimple[i])
		{
			for (ull j = i * i; j <= simpleLen; j += i) {
				isSimple[j] = false;
			}
		}

	}

	for (ull i = 2; i <= simpleLen; ++i) {
		if (isSimple[i]) {
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}