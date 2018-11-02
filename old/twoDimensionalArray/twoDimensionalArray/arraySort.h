#pragma once

void mergeSort(int* a, int lo, int hi);
void mergeSort(int** a, int lo, int hi, int cols);
void twoDimensionalArraySort(int** a, int rows, int cols);

void mergeSort(int* a, int lo, int hi) {
	if (lo >= hi) return;
	int mid = (hi + lo) / 2;

	mergeSort(a, lo,	  mid);
	mergeSort(a, mid + 1, hi);

	int len_b = hi - lo + 1,
		l	  = lo,
		r	  = mid + 1,
		i;

	int *b = new int[len_b];

	for (i = 0; i < len_b; i++) {
		if (l <= mid) {

			if (r <= hi) {

				if (a[l] <= a[r]) {
					b[i] = a[l++];
				} else {
					b[i] = a[r++];
				}
			} else {

				while (l <= mid) {
					b[i++] = a[l++];
				}
				break;
			}
		} else {

			while (r <= hi) {
				b[i++] = a[r++];
			}
			break;
		}
	}
	for (i = lo; i <= hi; i++) {
		a[i] = b[i - lo];
	}
	delete[] b;
}


void mergeSort(int** a, int lo, int hi, int cols) {
	if (lo >= hi) return;
	
	int mid = (lo + hi) / 2;


	mergeSort(a, lo, mid, cols);
	mergeSort(a, mid + 1, hi, cols);

	int len_b = hi - lo + 1,
		l = lo,
		r = mid + 1,
		i;
	int **b = new int*[len_b];

	for (i = 0; i < len_b; i++) {
		if (l <= mid) {

			if (r <= hi) {
				bool flg = true;

				for (int j = 0; j < cols; j++) {
					if (a[l][j] == a[r][j]) continue;
					
					if (a[l][j] < a[r][j]) {
						b[i] = a[l++];
					}
					else {
						b[i] = a[r++];
					}
					flg = false;
					break;
				}
				if (flg) {
					b[i] = a[l++];
				}
			} else {

				while (l <= mid) {
					b[i++] = a[l++];
				}
				break;
			}
		} else {

			while (r <= hi) {
				b[i++] = a[r++];
			}
			break;
		}
	}

	for (i = lo; i <= hi; i++) {
		a[i] = b[i - lo];
	}
	delete[] b;

}

void twoDimensionalArraySort(int** a, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		mergeSort(a[i], 0, cols - 1);
	}
	mergeSort(a, 0, rows - 1, cols);
}