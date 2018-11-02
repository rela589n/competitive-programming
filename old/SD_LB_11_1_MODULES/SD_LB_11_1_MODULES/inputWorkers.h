#pragma once
#include "general.h"

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
