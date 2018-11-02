#include <iostream>
#include <ctime>
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


using namespace std;

int* glue(int* a, int lenA, int* b, int lenB);
int* superSort(int* arr, int len);
int* superSort(int* arr, int len);


int main() {
	srand(time(NULL));
	int *a = new int[5000000], a1, *a3 = new int[5000000], i;
	cout << "size: ";
	cin >> a1;

	for (i = 0; i < a1; i++) {
		//cin >> a[i];
		a[i] = rand() % 300;
		//a[i] = a1 - i;
		a3[i] = a[i];
		//cout << a[i] << '\t';
	}

	//cout << endl;
	double t1 = getCPUTime();
	sort(a3, a3 + a1);
	//sort(a, a + a1);
	double t2 = getCPUTime();
	//a = hardSort(a, a1);
	cout << "not my time: " << (t2 - t1) * 1000 << endl;
	t1 = getCPUTime();
	a = superSort(a, a1);
	//a = hardSort(a, a1);
	t2 = getCPUTime();
	cout << "My time: " << (t2 - t1) * 1000 << endl;
	/*
	cout << "\n\nA:\n\n";
	for (i = 0; i < a1; i++)
		cout << a[i] << '\t';
		*/
	system("pause");
	return 0;

}


int *glue(int* a, int lenA, int* b, int lenB) {
	int lenC = lenA + lenB, *c = new int[lenC], indx_a = 0, indx_b = 0, i = 0;
	for (; i < lenC; i++) {
		if (indx_a < lenA)
			if (indx_b < lenB)
				c[i] = (a[indx_a] < b[indx_b]) ? a[indx_a++] : b[indx_b++];
			else {
				while (indx_a < lenA)
					c[i++] = a[indx_a++];
				break;
			}
		else {
			while (indx_b < lenB)
				c[i++] = b[indx_b++];
			break;
		}
	}
	return c;
}

int* insertionSort(int *arrayPtr, int start, int length)
{
	int temp, j, *arr = new int[length];
	for (int i = start + 1; i < length + start; i++)
	{
		temp = arrayPtr[i];
		arr[i - start - 1] = arrayPtr[i];
		for (j = i; j > start && arrayPtr[j - 1] > temp; j--){
			arrayPtr[j] = arrayPtr[j - 1];
			arr[j - start] = arrayPtr[j];
		}
		arrayPtr[j] = temp;
		arr[j - start] = temp;
		//cout << "temp = " << temp << endl;
	}
	return arr;
}

int* superSort(int* arr, int len) {
	if (len < 2)
		return arr;
	int i = 10, *a = new int[len];
	for (; i <= len; i += 10) {
		a = glue(a, i - 10, insertionSort(arr, i - 10, 10), 10);
	}
	a = glue(a, i - 10, insertionSort(arr, i - 10, len + 10 - i), len + 10 - i);
	return a;
}