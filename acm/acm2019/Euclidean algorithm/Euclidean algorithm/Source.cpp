#include <iostream>
#include <vector>

using namespace std;

typedef long long Int;
Int gcd(Int a, Int b) {
	while (a && b) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	return a + b;
}

Int lcm(Int a, Int b) {
	return a * b / gcd(a, b);
}


int main() {
	Int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;

	cin.get();
	cin.get();
	return 0;
}