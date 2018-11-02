#include <iostream>

using namespace std;

typedef unsigned u;

int main() {
	u n, sum = 0;
	cin >> n;
	
	u *a = new u[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		u higher = 0;
		
		for (int j = i + 1; j < n; ++j) {
			
			if (a[j] <= a[i]) {

				if (higher <= a[j]) {
					higher = a[j];
					++sum;
				}
			}
			else {
				++sum;
				break;
			}
		}
	}

	delete[] a;
	cout << sum;

	system("pause");
	return 0;
}
