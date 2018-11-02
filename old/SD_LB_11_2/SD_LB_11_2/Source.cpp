#include "ioEmployee.h"
#include "rwEmployee.h"


int main()
{

	setNames1251();
	string filename = "employees.dat";
start:
	cout << "1 - create file\n";
	cout << "2 - append into file\n";
	cout << "3 - output men pensioners\n";
	cout << "4 - read from file\n";
	cout << "5 - exit\n";
	char choise;
	cin >> choise;

	switch (choise) {
	case '1':
	case '2': {
		int emplQuantity;
		cout << "Enter the number of employees: ";
		while (!inputNumber(emplQuantity)) {
			cout << "Input error! please, repeat input: ";
		}
		employee *employees = new employee[emplQuantity];

		for (int i = 0; i < emplQuantity; ++i) {
			inputEmployee(employees, i);
		}
		bool app = (choise == '1') ? false : true;
		writeEmployee(filename, employees, emplQuantity, app);
		delete[] employees;
		break;
	}
	case '3':
	case '4': {
		streamoff eLen;
		employee *employees = readEmployee(filename, eLen);


		// if info got successful
		if (~eLen) {
			if (choise == '4') {
				for (int i = 0; i < eLen; i++) {
					outputEmployee(employees[i]);
				}
			}
			else {
				int *pensioners = new int[eLen], pIndx = 0;
				cout << "Enter retirement age in years: ";
				int retirenmentAge;
				while (!inputNumber(retirenmentAge)) {
					cout << "Input error! please, repeat input: ";
				}
				int year = currentYear();
				for (int i = 0; i < eLen; i++) {
					if (year - employees[i].birthYear >= retirenmentAge) {
						pensioners[pIndx++] = i;
					}
				}
				if (pIndx) {
					cout << "\n\t\t\tPENSIONERS:\n\n";
					for (int i = 0; i < pIndx; i++) {
						outputEmployee(employees[pensioners[i]]);
					}

				}
				else {
					cout << "Your company doesn't have pensioners!\n";
				}
				delete[] pensioners;

			}

		}
		else {
			cout << "Error! File is not exists!\n";
		}


		delete[] employees;
		break;
	}
	case '5':
		return 0;
	default:
		clearStream();
		cout << "Wrong input! Please repeat.\n";
		goto start;
	}
	cout << "Do you want to start program again? (1) - Yes, (0) - No\n";
	cin >> choise;
	if (choise == '1') {
		system("cls");
		goto start;
	}
	system("pause");
	return 0;
}