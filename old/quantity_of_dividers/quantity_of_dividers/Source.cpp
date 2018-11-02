#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned long int n;
	unsigned short int quantity = 0, i = 1;

	cin >> n;
	for (; i*i < n; i++) {
		if (n % i == 0) quantity+=2;
	}
	if ((n % i == 0) && (n / i == sqrt(n))) quantity++;
	cout << quantity << endl;

	system("pause");
	return 0;
}