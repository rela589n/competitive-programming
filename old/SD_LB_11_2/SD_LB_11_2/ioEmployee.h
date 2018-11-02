#pragma once

#include <string>
#include "general.h"


void inputEmployee(employee employees[], int currentNumber);
void outputEmployee(employee currEmployee);


void inputEmployee(employee employees[], int currentNumber) {
	int i = currentNumber;
	cin.get();
	cout << "Enter the name of " << i + 1 << " employee: ";
	cin.getline(employees[i].name, 24);

	cout << "Enter the name of specialty: ";
	cin.getline(employees[i].specialty, 24);

	cout << "Enter the year of birthday: ";
	while (!inputNumber(employees[i].birthYear)) {
		cout << "Input error! please, repeat input: ";

	}
	cout << "Is employee men(1) or women(0)? ";
	char choise;
	cin >> choise;

	if (choise == '1') {
		employees[i].sex = true;

	}
	else {
		employees[i].sex = false;

	}
}

void outputEmployee(employee currEmployee) {
	cout << "Name:\t\t\t" << currEmployee.name << endl;
	cout << "Name of specialty:\t" << currEmployee.specialty << endl;
	cout << "Year of birthday:\t" << currEmployee.birthYear << endl;
	string sex = "women";
	if (currEmployee.sex) {
		sex = "men";
	}
	cout << "The person is\t\t" << sex << endl << endl;
}
