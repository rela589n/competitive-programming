#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

struct worker_illness {
	char full_name[100], name_of_illness[50];
	unsigned int year_of_birthday, duration_of_illness;
};

void form(worker_illness a[], int len);
void output(worker_illness a[], int len);
void worker_longest_illness(worker_illness a[], int len, worker_illness workers[], int &workers_len);
void sortIllenssUp(worker_illness a[], int lo, int hi);
void scrollDown(int n);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	worker_illness workers[100];

start:	cout << "Enter number of workers: ";
	cin >> n;
	form(workers, n);
	output(workers, n);

	scrollDown(3);
	

info:	cout << "what you want to see?\n\t" <<
		"(1) - info about worker with longest ill\n\t" <<
		"(2) - info about all workers with growth duration of ill\n\n" <<
		"make your choise: ";
	char choise;
	cin >> choise;
	if(choise == '1'){
		worker_illness *long_ill = new worker_illness[n];
		int long_ill_len;
		worker_longest_illness(workers, n, long_ill, long_ill_len);
		cout << "\nInfo about workers with longest duration of issue:\n\n";
		output(long_ill, long_ill_len);
		delete[] long_ill;
	}
	else if (choise == '2') {
		sortIllenssUp(workers, 0, n - 1);
		cout << "\nInfo about workers with growth duration of ill:\n\n";
		output(workers, n);
	}

	cout << "Do you want to see another information?\n(1) - yes;\n(0) - no;\n";
	cin >> choise;
	if (choise == '1')
		goto info;

	cout << "Do you want to process for another workers?\n(1) - yes;\n(0) - no;\n";
	cin >> choise;
	if (choise == '1') {
		system("cls");
		goto start;
	}
	system("pause");
	return 0;
}


void form(worker_illness a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "\t\t\tEnter for " << i + 1 << " worker:\n";
		cout << "Surname and initials: ";
		cin.get();
		gets_s(a[i].full_name);

		cout << "Name of illness: ";
		gets_s(a[i].name_of_illness);

		cout << "Year of birthday: ";
		cin >> a[i].year_of_birthday;

		cout << "Duration of illness in days: ";
		cin >> a[i].duration_of_illness;
	}
}

void output(worker_illness a[], int len) {
	cout << endl << setw(28) << "Surname and initials";
	cout << setw(20) << "Name of illness";
	cout << setw(20) << "Year of birthday";
	cout << setw(35) << "Duration of illness in days\n\n";
	for (int i = 0; i < len; i++) {
		cout << setw(28) << a[i].full_name;
		cout << setw(20) << a[i].name_of_illness;
		cout << setw(19) << a[i].year_of_birthday;
		cout << setw(33) << a[i].duration_of_illness << endl;
	}
	cout << endl;
}

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

void scrollDown(int n) {
	for (int i = 0; i <= n; i++)
		cout << endl;
}