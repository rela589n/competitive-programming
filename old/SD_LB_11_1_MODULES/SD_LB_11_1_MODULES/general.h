#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

struct worker_illness {
	char full_name[100], name_of_illness[50];
	unsigned int year_of_birthday, duration_of_illness;
};

void scrollDown(int n) {
	for (int i = 0; i <= n; i++)
		cout << endl;
}