#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
	ull n = 600851475143;
	ull simpleLen = ceil(sqrt(n));

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

	ull max = 0;
	for (ull i = 2; i <= simpleLen; ++i) {
		if (isSimple[i] && n % i == 0 && i > max) {
			max = i;
		}
	}
	cout << max;

	system("pause");
	return 0;
}