#include <iostream>
#include <ctime>
#include <vector>
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


using namespace std;
void merge_sort(int *a, int lo, int hi);
template <class T>
void merge_sort(vector<T> a, int lo, int hi) {
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;

	merge_sort(a, lo, mid);
	merge_sort(a, mid + 1, hi);

	int len_b = hi - lo + 1;
	T* b = new T[len_b];
	int l = lo, r = mid + 1;
	for (int i = 0; i < len_b; ++i)
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
	for (int i = lo; i <= hi; ++i)
		a[i] = b[i - lo];
	delete[] b;
}
double getCPUTime();

int main() {
	srand(time(NULL));
	int size, i, *a2;
	double t1, t2;

	cin >> size;
	vector<int> a(size);
	a2 = new int[size];
	cout << "A:\n";
	for (i = 0; i < size; i++) {
		a[i] = rand() % 101;
		a2[i] = a[i];
		cout << a[i] << '\t';
	}
	cout << '\n';

	t1 = getCPUTime();
	merge_sort(a, 0, size - 1);
	t2 = getCPUTime();

	cout << "merge sort time: " << (t2 - t1) * 1000 << endl;

	t1 = getCPUTime();
	sort(a2, a2 + size);
	t2 = getCPUTime();

	cout << "sort time: " << (t2 - t1) * 1000 << endl;
	
	cout << "A:\n";
	for (i = 0; i < size; i++) {
		cout << a2[i] << '\t';
	}
	cout << '\n';
	
	system("pause");
	return 0;
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
		if(l <= mid)
			if(r <= hi)
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
