#include <iostream>

using namespace std;

int main() {
	long int n, index_res = 0;
	char numbers16[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '\0'};
	char res[10];
	cin >> n;
	while (n > 15) {
		res[index_res++] = numbers16[n - (n / 16 * 16)];
		n /= 16;
	}
	cout << numbers16[n];
	for (int i = index_res - 1; i >= 0; i--) {
		cout << res[i];
	}
	system("pause");
	return 0;
}
