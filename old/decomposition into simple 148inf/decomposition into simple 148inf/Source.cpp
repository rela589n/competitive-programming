#include <iostream>

using namespace std;

bool is_simple(unsigned long int n);

int main() {
	unsigned long int n, nc, res[33], divider = 2, index_res = 0;

	cin >> n;
	nc = n;
	if (!is_simple(nc)) {
		while (nc > 1) {
			if (nc % divider == 0) {
				res[index_res++] = divider;
				nc /= divider;
			}
			else {
				if (!is_simple(nc)) {
					do {
						divider++;
					} while (!is_simple(divider));
				}
				else {
					res[index_res++] = nc;
					break;
				}
			}
		}
		for (int i = 0; i < index_res; i++) {
			cout << res[i] << endl;
		}
	}
	else {
		cout << nc << endl;
	}
	
	system("pause");
	return 0;
}

bool is_simple(unsigned long int n) {
	for (long int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}