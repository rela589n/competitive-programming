#pragma once
#include "general.h"


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
