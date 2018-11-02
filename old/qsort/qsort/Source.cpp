#include <iostream>

using namespace std;
void m_qsort(int *a, int lo, int hi);
void mswap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int *a, size, n1 = 12, n2 = 3;
	mswap(n1, n2);
	cout << n1 << '\t' << n2;
	

	/*
	cin >> size;
	a = new int[size];
	*/


	system("pause");
	return 0;
}


void m_qsort(int *a, int lo, int hi) {
	if (hi <= lo + 1)
		return;
	int pivot = a[lo],
		l = lo + 1,
		r = hi;
	while (r > l) {
		while (a[l] <= pivot)
			l++;
		while (a[r] >= pivot)
			r--;
		if (r > l) {
			
		}

	}

}

