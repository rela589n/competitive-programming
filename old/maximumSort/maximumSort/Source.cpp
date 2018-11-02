#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

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

double getCPUTime();

void maximumSort(int *&a, int len);
int* mergeArray(int *&a, int &len1, int*& b, int &len2);

void merge_sort(int *a, int lo, int hi);

void inputArray(int *arr, int len);
void printArray(int *arr, int len);
void copyArray(int *arr1, int *arr2, int len);

using namespace std;

int main() {
	srand(time(0));
	double startTime, endTime;

	start:
	int len;
	cin >> len;

	int *arr1 = new int[len],
		*arr2 = new int[len],
		*arr3 = new int[len];
	
	inputArray(arr1, len);
	copyArray(arr1, arr2, len);

	startTime = getCPUTime();
	maximumSort(arr1, len);
	endTime = getCPUTime();

	cout << "Maximum sort: " << (endTime - startTime) * 1000 << endl;

	startTime = getCPUTime();
	sort(arr2, arr2 + len);
	endTime = getCPUTime();

	cout << "Quick sort: " << (endTime - startTime) * 1000 << endl;

	startTime = getCPUTime();
	merge_sort(arr3, 0, len - 1);
	endTime = getCPUTime();

	cout << "Merge sort: " << (endTime - startTime) * 1000 << endl << endl;

	goto start;

	system("pause");
	return 0;
}

void maximumSort(int *&a, int len) {
	if (len < 2) return;

	int **maximums = new int*[len],
		maximumsLength = 0,
		*maxLengths = new int[len];

	maximums[0] = new int[len];
	maximums[0][0] = a[0];
	maxLengths[0] = 1;
	maximumsLength = 1;

	for (int i = 1; i < len; ++i) {
		int max = a[i];

		int l = 0;
		int r = maximumsLength - 1;

		while (l < r) {
			int cen = (l + r) / 2;
			int currentMaxIndex = maxLengths[cen] - 1;

			if (max < maximums[cen][currentMaxIndex]) {
				l = cen + 1;
			}
			else {
				r = cen;
			}
		}

		int currentMaxIndex = maxLengths[l] - 1;

		if (max < maximums[l][currentMaxIndex]) {
			maximums[maximumsLength] = new int[len - i];
			maximums[maximumsLength][0] = max;

			maxLengths[maximumsLength] = 1;
			++maximumsLength;
		}
		else {
			maximums[l][currentMaxIndex + 1] = max;
			++maxLengths[l];
		}
	}

	for (int i = maximumsLength - 1; i > 0; --i) 
	{
		maximums[i - 1] = mergeArray(maximums[i - 1], maxLengths[i - 1], maximums[i], maxLengths[i]);
	}

	delete[] a;
	a = maximums[0];

	delete[] maximums;
}

int* mergeArray(int *&a, int &len1, int*& b, int &len2) {
	int len3 = len1 + len2;
	int *c = new int[len3];

	int l = 0, r = 0;

	for (int i = 0; i < len3; ++i) 
	{
		if (l < len1) 
		{
			if (r < len2) 
			{
				if (a[l] <= b[r]) {
					c[i] = a[l++];
				}
				else {
					c[i] = b[r++];
				}
			}
			else {
				while (l < len1) {
					c[i++] = a[l++];
				}
				break;
			}
		}
		else {
			while (r < len2) {
				c[i++] = b[r++];
			}
		}
	}

	delete[] b;
	delete[] a;

	len1 = len3;

	return c;
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

void inputArray(int *arr, int len) {
	for (int i = 0; i < len; ++i) {
		//cin >> arr[i];
		arr[i] = rand();
	}
	cout << endl;
}

void printArray(int *arr, int len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void copyArray(int *arr1, int *arr2, int len) {
	for (int i = 0; i < len; ++i) {
		arr2[i] = arr1[i];
	}
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
