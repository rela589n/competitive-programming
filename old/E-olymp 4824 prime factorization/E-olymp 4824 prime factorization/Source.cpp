#include <iostream>
#include <string>
#include <math.h>

using namespace std;
typedef long long Int;

bool* prime_numbers(Int to) {
	bool *simple = new bool[to];
	
	for (Int i = 0; i < to; ++i) {
		simple[i] = true;
	}


	for (Int i = 3; i * i < to; i += 2) {
		if (simple[i]) {
			for (Int j = i * i; j < to; j += i) {
				simple[j] = false;
			}
		}
	}

	return simple;
}


int main(void) {

	Int n;
	cin >> n;
	Int stop = sqrt(n);

	string ans;
	ans.reserve(stop);
	ans = "[";

	bool* prime = prime_numbers(stop + 1);
	
	Int elems = 0;
	while (!(n & 1)) {
		if (n <= 1) {
			break;
		}

		ans.append("2, ");
		
		++elems;
		n >>= 1;
	}

	
	for (Int i = 3; i <= n; i += 2) {
		if (i > stop || n <= 1) {
			break;
		}

		if (prime[i]) {
			while (n % i == 0) {
				ans.append(to_string(i) + ", ");
				n /= i;
				++elems;
			}
		}
	}
	
	if (n > 1 || !elems) {
		ans.append(to_string(n) + "]");
		cout << ans;
		cin.get();
		cin.get();

		return 0;
	}
	

	cout << ans.substr(0, ans.length() - 2) + "]";
	cin.get();
	cin.get();
	cin.get();
	return 0;
}