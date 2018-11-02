#pragma once

int* formArray(int);
void printArr(int *a, int l);

int* arrayNegative(int* a, int len, int &lengthOfNegative);
int* arrayPositive(int* a, int len, int &lenghtOfPositive);
int arrayNumberOfZeros(int* a, int len);

void convertArr(int *a, int l);

using namespace std;

int* arrayNegative(int* a, int len, int &lengthOfNegative) {
	int *neg   = new int[len],
		negLen = 0;

	for (int i = 0; i < len; ++i) {
		if (a[i] < 0) {
			neg[negLen++] = a[i];
		}
	}

	lengthOfNegative = negLen;
	return neg;
}


int* arrayPositive(int* a, int len, int &lenghtOfPositive) {
	int *pos = new int[len],
		posLen = 0;

	for (int i = 0; i < len; ++i) {
		if (a[i] > 0) {
			pos[posLen++] = a[i];
		}
	}

	lenghtOfPositive = posLen;
	return pos;
}

int arrayNumberOfZeros(int* a, int len) {
	int zerosNum = 0;
	
	for (int i = 0; i < len; ++i) {
		if (!a[i]) {
			zerosNum++;
		}
	}

	return zerosNum;
}

int* formArray(int length) {
	int *arr = new int[length], i;

	for (i = 0; i < length; i++) {
		//cout << "\nEnter " << i + 1 << " element of array: ";
		//cin >> arr[i];
		arr[i] = rand() % 11 - 5;
	}

	return arr;
}

void mergeSort(int *a, int lo, int hi) {
	if (lo >= hi) return;

	int mid = (lo + hi) / 2;

	mergeSort(a, lo, mid);
	mergeSort(a, mid + 1, hi);

	int lenB = hi - lo + 1,
		*b = new int[lenB],
		l = lo,
		r = mid + 1;

	for (int i = 0; i < lenB; ++i) {
		if (l <= mid) {

			if (r <= hi) {

				if (a[l] < a[r]) {
					b[i] = a[l++];
				}
				else {
					b[i] = a[r++];
				}
			}
			else {
				while (l <= mid) {
					b[i++] = a[l++];
				}
				break;
			}
		}
		else {
			while (r <= hi) {
				b[i++] = a[r++];
			}
			break;
		}
	}

	for (int i = lo; i <= hi; i++) {
		a[i] = b[i - lo];
	}

}

void printArr(int *a, int l) {
	for (int i = 0; i < l; ++i) {
		cout << a[i] << '\t';
	}
	cout << endl;
}


void convertArr(int *a, int l) {
	int positiveLen,
		*positive = arrayPositive(a, l, positiveLen),

		quantOfZeros = arrayNumberOfZeros(a, l),

		negativeLen,
		*negative = arrayNegative(a, l, negativeLen);

	mergeSort(positive, 0, positiveLen - 1);
	mergeSort(negative, 0, negativeLen - 1);

	for (int i = 0; i < positiveLen; ++i) {
		a[i] = positive[i];
	}

	for (int i = positiveLen; i < positiveLen + quantOfZeros; i++) {
		a[i] = 0;
	}

	int negativeStart = positiveLen + quantOfZeros;

	for (int i = negativeStart; i < l; i++) {
		a[i] = negative[i - negativeStart];
	}

	delete[] positive;
	delete[] negative;
}
