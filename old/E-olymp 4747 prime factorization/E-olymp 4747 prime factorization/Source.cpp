#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <math.h>

using namespace std;
typedef long long Int;

list<Int> prime_numbers(Int to) {
	vector<bool> simple(to, true);
	
	for (Int i = 3; i * i < to; i += 2) {
		if (simple[i]) {
			for (Int j = i * i; j < to; j += i) {
				simple[j] = false;
			}
		}
	}

	list<Int> ans = { 2 };
	
	for (Int i = 3; i < to; i += 2) {
		if (simple[i]) {
			ans.push_back(i);
		}
		
	}

	return ans;
}

map<Int, Int> factorizate(Int number, list<Int> primes) {
	Int stop = (int)sqrt(number);
	map<Int, Int> ans;

	for (auto i = primes.begin(); i != primes.end(); ++i) {
		Int el = *i;

		if (number <= 1 || el > stop) {
			break;
		}

		while (number % el == 0) {
			++ans[el];
			number /= el;
		}
	}

	// если число ещё простое
	if (number > 1) {
		ans[number] = 1;
	}

	return ans;

}


int main() {

	Int n;
	cin >> n;
	
	list<Int> primes = prime_numbers((int)sqrt(n) + 1);
	map<Int, Int> pairs = factorizate(n, primes);
	
	for (auto& item : pairs) {
		cout << item.first << ' ' << item.second << endl;
	}
	

	return 0;
}