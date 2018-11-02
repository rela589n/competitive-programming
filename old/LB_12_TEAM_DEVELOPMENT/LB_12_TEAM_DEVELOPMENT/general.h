#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

void setNames1251();
void clearStream();
bool inputNumber(double &n);
bool inputNumber(int &n);

void setNames1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

bool inputNumber(double &n) {
	if (!(cin >> n)) {
		clearStream();
		return false;
	}
	return true;
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

