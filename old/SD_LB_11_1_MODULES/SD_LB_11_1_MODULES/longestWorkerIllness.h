#pragma once
#include "general.h"

void worker_longest_illness(worker_illness a[], int len, worker_illness workers[], int &workers_len) {
	int max = a[0].duration_of_illness;
	workers[0] = a[0];
	workers_len = 1;
	for (int i = 1; i < len; i++) {
		if (a[i].duration_of_illness > max) {
			max = a[i].duration_of_illness;
			workers_len = 1;
			workers[0] = a[i];
		}
		else if (max == a[i].duration_of_illness) {
			workers[workers_len++] = a[i];
		}
	}
}

void sortIllenssUp(worker_illness a[], int lo, int hi) {
	if (lo >= hi)
		return;
	int mid = (hi + lo) / 2;

	sortIllenssUp(a, lo, mid);
	sortIllenssUp(a, mid + 1, hi);

	int len_b = hi - lo + 1,
		l = lo,
		r = mid + 1,
		i;

	worker_illness *b = new worker_illness[len_b];

	for (i = 0; i < len_b; i++)
		if (l <= mid)
			if (r <= hi)
				if (a[l].duration_of_illness <= a[r].duration_of_illness)
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
	for (i = lo; i <= hi; i++)
		a[i] = b[i - lo];
	delete[] b;
}