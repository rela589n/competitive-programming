#include <iostream>

using namespace std;

int main() {
	float num, n1, n2;
	bool flag = 0;
	num = 0;
	do {
		n1 = num;
		cin >> num;
		n2 = num;
		if ((n2 == n1) && (n2 != 0)) {
			flag = 1;
		}
	} while (num != 0);
	(flag) ? cout << "YES" : cout << "NO";
	system("pause");
	return 0;
}