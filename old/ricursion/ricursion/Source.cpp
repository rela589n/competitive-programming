#include <iostream>
#include <ctime>

using namespace std;
// bad variant
unsigned long long fact_recurse(unsigned long int n) {
	if (n > 1) {
		return n * fact_recurse(n - 1);
	}
	else {
		return 1;
	}
}
// good variant
unsigned long long fact_cicle(unsigned long int n) {
	unsigned long long fact = 1;
	for (unsigned long int i = 2; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

int main() {
	bool flag = 1;
	for (int i = 1; i <= 65; i++) {
		unsigned long long a = fact_recurse(i);
		unsigned long long b = fact_cicle(i);
		if (a != b) {
			flag = 0;
		}
	}
	system("pause");
	return 0;
}