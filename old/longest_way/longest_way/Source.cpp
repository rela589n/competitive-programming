#include <iostream>

using namespace std;

typedef unsigned short int usi;

int main() {
	long int n, num[10000], currlength = 1, length = 1, longest;
	cin >> n;
	cin >> num[0];
	longest = num[0];
	for (long int i = 1; i < n; i++) {
		cin >> num[i];
		if (num[i] == num[i - 1]) {
			currlength++;
			if (currlength > length) {
				longest = num[i];
				length = currlength;
			}
		}
		else {
			currlength = 1;
		}
	}
	cout << longest << " " << length;
	system("pause");
	return 0;
}