#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));
	int n, num[100], numPositive[99], max = -1, indx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		num[i] = rand() % 1001 - 5000;
		cout << num[i] << "\t";
		
		if (num[i] > max) {
			max = num[i];
		}
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		if (num[i] > 0 && num[i] != max) {
			numPositive[indx++] = num[i];
		}
	}
	if (indx > 0) {
		cout << "New array: " << endl << "{";
		for (int i = 0; i < indx; i++)
			cout << numPositive[i] <<"\t";
		cout << "}";
	}
	else {
		cout << "err";
	}
	system("pause");
	return 0;
}