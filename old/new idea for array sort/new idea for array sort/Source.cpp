#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

#include "mySort.h"
#include <algorithm>

#if defined(_WIN32)
#include <Windows.h>

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>

#else
#error "Unable to define getCPUTime( ) for an unknown OS."
#endif

/**
 * Returns the amount of CPU time used by the current process,
 * in seconds, or -1.0 if an error occurred.
 */

void merge_sort(int *a, int lo, int hi);
double getCPUTime();

void printArray(int* arr, int length);
void formArray(int *arr, int len);

int main() {
	srand(time(NULL));
		
	int n;

	cin >> n;

	int *arr1 = new int[n],
		*arr2 = new int[n],
		*arr3 = new int[n];
	double time1, time2;

	formArray(arr1, n);

	for (int i = 0; i < n; ++i) {
		arr2[i] = arr3[i] = arr1[i];
	}

	time1 = getCPUTime();
	mySort(arr1, 0, n - 1);
	time2 = getCPUTime();

	cout << "My time: " << (time2 - time1) * 1000 << endl;

	time1 = getCPUTime();
	merge_sort(arr2, 0, n - 1);
	time2 = getCPUTime();

	cout << "Merge sort: " << (time2 - time1) * 1000 << endl;
	
	time1 = getCPUTime();
	sort(arr3, arr3 + n);
	time2 = getCPUTime();

	cout << "q sort: " << (time2 - time1) * 1000 << endl;
	

	system("pause");
	return 0;
}


void formArray(int *arr, int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = rand() % 21;
	}
}

void printArray(int* arr, int length) {
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void merge_sort(int *a, int lo, int hi) {
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;

	merge_sort(a, lo, mid);
	merge_sort(a, mid + 1, hi);

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



double getCPUTime()
{
#if defined(_WIN32)
	/* Windows -------------------------------------------------- */
	FILETIME createTime;
	FILETIME exitTime;
	FILETIME kernelTime;
	FILETIME userTime;
	if (GetProcessTimes(GetCurrentProcess(),
		&createTime, &exitTime, &kernelTime, &userTime) != -1)
	{
		SYSTEMTIME userSystemTime;
		if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
			return (double)userSystemTime.wHour * 3600.0 +
			(double)userSystemTime.wMinute * 60.0 +
			(double)userSystemTime.wSecond +
			(double)userSystemTime.wMilliseconds / 1000.0;
	}

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
	/* AIX, BSD, Cygwin, HP-UX, Linux, OSX, and Solaris --------- */

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0)
	/* Prefer high-res POSIX timers, when available. */
	{
		clockid_t id;
		struct timespec ts;
#if _POSIX_CPUTIME > 0
		/* Clock ids vary by OS.  Query the id, if possible. */
		if (clock_getcpuclockid(0, &id) == -1)
#endif
#if defined(CLOCK_PROCESS_CPUTIME_ID)
			/* Use known clock id for AIX, Linux, or Solaris. */
			id = CLOCK_PROCESS_CPUTIME_ID;
#elif defined(CLOCK_VIRTUAL)
			/* Use known clock id for BSD or HP-UX. */
			id = CLOCK_VIRTUAL;
#else
			id = (clockid_t)-1;
#endif
		if (id != (clockid_t)-1 && clock_gettime(id, &ts) != -1)
			return (double)ts.tv_sec +
			(double)ts.tv_nsec / 1000000000.0;
	}
#endif

#if defined(RUSAGE_SELF)
	{
		struct rusage rusage;
		if (getrusage(RUSAGE_SELF, &rusage) != -1)
			return (double)rusage.ru_utime.tv_sec +
			(double)rusage.ru_utime.tv_usec / 1000000.0;
	}
#endif

#if defined(_SC_CLK_TCK)
	{
		const double ticks = (double)sysconf(_SC_CLK_TCK);
		struct tms tms;
		if (times(&tms) != (clock_t)-1)
			return (double)tms.tms_utime / ticks;
	}
#endif

#if defined(CLOCKS_PER_SEC)
	{
		clock_t cl = clock();
		if (cl != (clock_t)-1)
			return (double)cl / (double)CLOCKS_PER_SEC;
	}
#endif

#endif

	return -1;      /* Failed. */
}
