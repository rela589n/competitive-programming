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
int* hardSort(int* arr, int len);



int main() {
	srand(time(NULL));
	int *a = new int[100000], b[100000], a1, b1, i, j, *a3 = new int[100000];
	cout << "size: ";
	cin >> a1;
	

	//42 22 45 12 29
	//a1 = 1000;
	
	
	for (i = 0; i < a1; i++){
		//cin >> a[i];
		a[i] = rand() % 51;
		//a[i] = a1 - i;
		a3[i] = a[i];
		cout << a[i] << '\t';
	}
	cout << endl;
	double t1 = getCPUTime();
	sort(a3, a3 + a1);
	//sort(a, a + a1);
	double t2 = getCPUTime();
	//a = hardSort(a, a1);
	cout << "not my time: " << (t2 - t1)*1000 << endl;
	t1 = getCPUTime();
	a = hardSort(a, a1);
	t2 = getCPUTime();
	cout << "My time: " << (t2 - t1)*1000 << endl;
	
	cout << "\n\nA:\n\n";
	for (i = 0; i < a1; i++)
		cout << a[i] << '\t';
	
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

int* hardSort(int* arr, int len) {
	//cout << "\nhardSort\n";
	int 
		centeri = (len + 1) / 2,
		centerj = len / 2, 
		i = 1,
		j = centerj + 1,
		*a1 = new int[centeri],
		*a_1 = new int[centeri],
		*a2 = new int[centerj],
		*a_2 = new int[centerj],
		indx_a1 = 1, 
		indx__a1 = 1, 
		indx_a2 = (len % 2 == 0)? 1:0,
		indx__a2 = indx_a2,
		*b_i = new int[centeri],
		*b_i_2 = new int[centeri],
		*b_j = new int[centerj],
		*b_j_2 = new int[centerj],
		indx_b_i = 0, 
		indx_b_i_2 = 0, 
		indx_b_j = 0, 
		indx_b_j_2 = 0, 
		indx_b_2 = 0, 
		maxi,
		maxj,
		maxi_2,
		maxj_2;
	//cout << "centeri: " << centeri << endl;
	//cout << "centerj: " << centerj << endl;
	a1[0] = maxi = arr[0];
	a_1[0] = maxi_2 = arr[centeri - 1];
	a2[0] = maxj = arr[centeri];
	a_2[0] = maxj_2 = arr[len - 1];
	for (;i < centeri; j = centerj + ++i){
		//cout << "i: " << i << endl;
		//cout << "j: " << j << endl;
		if (maxi <= arr[i]) {
			maxi = arr[i];
			a1[indx_a1++] = maxi;
		}
		else{
			b_i[indx_b_i++] = arr[i];
		}
		if (maxi_2 <= arr[centeri - 1 - i]) {
			maxi_2 = arr[centeri - 1 - i];
			a_1[indx__a1++] = maxi_2;
		}
		else
			b_i_2[indx_b_i_2++] = arr[centeri - 1 - i];



		if (maxj <= arr[j]) {
			maxj = arr[j];
			a2[indx_a2++] = maxj;
		}
		else
			b_j[indx_b_j++] = arr[j];
		
		if (maxj_2 <= arr[len - j + centerj]) {
			maxj_2 = arr[len - j + centerj];
			a_2[indx__a2++] = maxj_2;
		}
		else
			b_j_2[indx_b_j_2++] = arr[len - j + centerj];
	}
	/*
	cout << "\nA1:\t";
	for (i = 0; i < indx_a1; i++) {
		cout << a1[i] << '\t';
	}
	cout << "\n\nA2:\t";
	for (i = 0; i < indx_a2; i++) {
		cout << a2[i] << '\t';
	}
	cout << "\n\nB:\t";
	for (i = 0; i < indx_b; i++) {
		cout << b[i] << '\t';
	}
	cout << endl;
	*/

	//a1, indx_a1, b_i, indx_b_i, a2, indx_a2, indx_b_j
	if (indx__a1 > indx_a1) {
		indx_a1 = indx__a1;
		a1 = a_1;
		b_i = b_i_2;
		indx_b_i = indx_b_i_2;
		delete[] a_1;
		delete[] b_i_2;
	}

	if (indx__a2 > indx_a2) {
		indx_a2 = indx__a2;
		a2 = a_2;
		b_j = b_j_2;
		indx_b_j = indx_b_j_2;
		delete[] a_2;
		delete[] b_j_2;
	}

	if (indx_b_i > 1) {
		b_i = hardSort(b_i, indx_b_i);
	}
	if (indx_b_j > 1) {
		b_j = hardSort(b_j, indx_b_j);
	}

	return glue(glue(a1, indx_a1, a2, indx_a2), b_len, glue(b_i, indx_b_i, b_j, indx_b_j), indx_b_i + indx_b_j);
}



