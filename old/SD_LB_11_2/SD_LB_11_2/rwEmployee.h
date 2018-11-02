#pragma once

#include <fstream>
#include "general.h"


bool writeEmployee(string filename, employee employees[], int length, bool append = true);
employee* readEmployee(string filename, streamoff &len);
streamoff fileSize(string filename);


bool writeEmployee(string filename, employee employees[], int length, bool append) {
	bool r = false;
	int mode = (append) ? ios::app : ios::out;
	ofstream f(filename, mode | ios::binary);
	if (f.is_open()) {
		for (int i = 0; i < length; i++) {
			f.write((char *)&employees[i], sizeof(employees[i]));
		}
		r = true;
	}
	f.close();
	return r;
}


employee* readEmployee(string filename, streamoff &len) {
	ifstream f(filename, ios::binary);
	if (!(f.is_open())) {
		len = -1;
	}
	else {
		len = fileSize(filename) / sizeof(employee);
		employee *employees = new employee[len];
		employee some;

		int i = 0;

		int streamSize = sizeof(employees[0]);
		while (i < len) {
			f.read((char *)&some, streamSize);
			employees[i] = some;
			i++;
		}
		f.close();
		return employees;
	}
	f.close();
}


streamoff fileSize(string filename) {
	ifstream fEnd(filename, ios::ate | ios::binary);
	streamoff len;
	if (fEnd.is_open()) {
		len = fEnd.tellg();
	}
	else
	{
		len = -1;
	}
	fEnd.close();
	return len;
}