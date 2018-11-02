#pragma once

using namespace std;

void sort3(int* arr, int last);
void sort2(int* arr, int last);
void mySort(int arr[], int lo, int hi);


void mySort(int a[], int lo, int hi) {
	if (hi - lo == 2) {
		sort3(a, hi);
		return;
	}
	if (hi - lo == 1) {
		sort2(a, hi);
		return;
	}
	if (lo >= hi) return;
	
	int mid = lo + (hi - lo) / 2;

	mySort(a, lo, mid);
	mySort(a, mid + 1, hi);

	int len_b = hi - lo + 1;
	int *b = new int[len_b];
	int l = lo, r = mid + 1;
	for (int i = 0; i < len_b; i++)
		if (l <= mid)
			if (r <= hi)
				if (a[l] <= a[r])
					b[i] = a[l++];
				else
					b[i] = a[r++];
			else {
				while (l <= mid)
					b[i++] = a[l++];
				break;
			}
		else {
			while (r <= hi)
				b[i++] = a[r++];
			break;
		}
	for (int i = lo; i <= hi; i++)
		a[i] = b[i - lo];
	delete[] b;
}

void sort2(int* arr, int last) {
	if (arr[last - 1] > arr[last]) {
		swap(arr[last - 1], arr[last]);
	}
}

void sort3(int* arr, int last) {
	int &a = arr[last - 2],
		&b = arr[last - 1],
		&c = arr[last];
	
	if (b < a) {
		swap(a, b);
	}
	if (c < b) {
		swap(b, c);

		if (b < a) {
			swap(a, b);
		}
	}
}
