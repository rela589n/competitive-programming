#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

struct employee {
	char name[25], specialty[25];
	int birthYear;
	bool sex; // 1 = male, 0 = female
};

void setNames1251();
void clearStream();
bool inputNumber(int &n);
int currentYear();


void setNames1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

bool inputNumber(int &n) {
	if (!(cin >> n)) {
		clearStream();
		return false;
	}
	return true;
}

void clearStream() {
	cin.clear();
	while (cin.get() != '\n');
}

int currentYear() {
	time_t t;
	tm loctime;
	t = time(NULL);
	localtime_s(&loctime, &t);
	return loctime.tm_year + 1900;
}