#include <iostream>
using namespace std;

int main() {
	int n, numb[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numb[i];
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && numb[j - 1] > numb[j]; j--)
			swap(numb[j - 1], numb[j]);
	for (int i = 0; i < n; i++) {
		cout << numb[i]<<endl;
	}
	system("pause");
	return 0;
}