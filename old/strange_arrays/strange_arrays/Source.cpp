#include <iostream>
#include <time.h>

using namespace std;

int** createArr1(int r, int c);
int** createArr2(int r, int c);
void printArr(int** arr, int r, int c);

int count(bool i = false, bool setNull = false) {
	static int c = 0;
	
	if (setNull) {
		c = 0;
	}
	else if (!i) {
		c++;
	}
	return c;
}


int main() {
	count(false, true);
	long long s, e;

	int n;
	cout << "N: ";
	cin >> n;

	s = clock();
	int **arr1 = createArr1(n, n);
	e = clock();

	cout << "Time 1 -----> ";
	cout << e - s << endl;

	cout << "Operations ----> ";
	cout << count(true) << endl;
	count(false, true);

	s = clock();
	int **arr2 = createArr2(n, n);
	e = clock();

	cout << "Time 2 -----> ";
	cout << e - s << endl;

	cout << "Operations ----> ";
	cout << count(true) << endl;
	count(false, true);

	//printArr(arr1, n, n);

	system("pause");
	return 0;
}


int** createArr1(int r, int c) {
	int **arr = new int*[r];

	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];

		for (int j = 0; j < c; j++) {
			arr[i][j] = i + j;
			count();
		}
	}

	return arr;
}

int** createArr2(int r, int c) {
	int **arr = new int*[r];

	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];

		arr[i][i] = i + i;
		count();
		for (int j = 0; j < i; j++) {
			arr[i][j] = arr[j][i] = i + j;
			count();
			count();
		}
	}

	return arr;
}


void printArr(int** arr, int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}