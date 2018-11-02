#include <iostream>

using namespace std;


int main() {
	int n, mas[45];
	mas[0] = 1;
	mas[1] = 1;
	for (int i = 2; i < 45; i++) {
		mas[i] = mas[i - 1] + mas[i - 2];
	}

	cin >> n;

	cout << mas[n - 1] << endl;


	system("pause");
	return 0;
}