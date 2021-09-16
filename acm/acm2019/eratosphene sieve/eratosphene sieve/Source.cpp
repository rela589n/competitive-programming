#include <iostream>
#include <vector>

using namespace std;

typedef long long Int;

vector<bool> primes(Int to)
{
	vector<bool> isSimple(to + 1, true);
	
	for (Int i = 4; i <= to; i += 2) {
		isSimple[i] = false;
	}

	isSimple[0] = isSimple[1] = false;
	
	for (Int i = 3; i * i <= to; i += 2)
	{
		if (isSimple[i])
		{
			for (Int j = i * i; j <= to; j += i) {
				isSimple[j] = false;
			}
		}
	}

	return isSimple;
}

int main() {
	Int s, f;
	cin >> s >> f;

	vector<bool> simple = primes(f);

	
	for (Int i = s; i <= f; ++i) {
		if (simple[i]) {
			cout << i << " ";
		}
	}

	//system("pause");
	return 0;
}