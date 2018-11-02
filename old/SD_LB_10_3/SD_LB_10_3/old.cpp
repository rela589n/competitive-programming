#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;


struct employee {
	string name, specialty;
	int birthYear;
	bool sex; // 1 = male, 0 = female
};

void setNames1251();
void clearStream();
bool inputNumber(int &n);
void inputEmployee(employee employees[], int currentNumber);
void outputEmployee(employee currEmployee);
bool writeEmployee(string filename, employee employees[], int length, bool append = true);
streamoff fileSize(string filename);
int currentYear();

employee* readEmployee(string filename, streamoff &len);

int main()
{
	setNames1251();
	string filename = "employees.dat";	
	currentYear();
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
		case '4':{
			streamoff eLen;
			employee *employees = readEmployee(filename, eLen);

			/*
			// if info got successful
			if (~eLen && employees) {
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
				cout << "Error!\n";
				cout << ~eLen << endl;
			}
			*/
			cout << eLen << endl;
			cout << employees[0].name<<endl;

			//delete[] employees;
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
		goto start;
	}
	system("pause");
	return 0;
}

//void delete

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

void inputEmployee(employee employees[], int currentNumber) {
	int i = currentNumber;
	cin.get();
	cout << "Enter the name of " << i + 1 << " employee: ";
	getline(cin, employees[i].name);

	cout << "Enter the name of specialty: ";
	getline(cin, employees[i].specialty);

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
	if (!(f.is_open())){
		len = -1;
	}
	else{
		len = fileSize(filename) / sizeof(employee);
		employee *employees = new employee[len];
		int i = 0;

		int streamSize = sizeof(employees[0]);
		while (i < len) {
			employee some;
			f.read((char *)&some, streamSize);
			employees[i] = some;
			cout << some.name << endl;
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

int currentYear() {
	time_t t;
	tm loctime;
	t = time(NULL);
	localtime_s(&loctime, &t);
	return loctime.tm_year + 1900;
}
