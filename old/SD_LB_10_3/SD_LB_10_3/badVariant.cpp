#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


struct employee {
	string name, specialty;
	int birthYear;
	bool sex; // 1 = male, 0 = female
};

void setNames1251();
bool inputNumber(int &n);
void inputEmployee(employee employees[], int currentNumber);
void outputEmployee(employee currEmployee);
bool reWriteEmployee(string filename, employee employees[], int length);
bool appendEmployee(string filename, employee employees[], int length);

employee* read_from_binary_file(string filename, int &len);

int main()
{
	setNames1251();
	string filename = "employees.dat";
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
			if (choise == '1') {
				reWriteEmployee(filename, employees, emplQuantity);
			}
			else {
				appendEmployee(filename, employees, emplQuantity);
			}
			delete[] employees;
			break;
		}
		case '3': 
		case '4':{
			int eLen;
			employee *employees = read_from_binary_file(filename, eLen);

			// if info get successful
			if (~eLen && employees) {
				if (choise == '4') {
					for (int i = 0; i < eLen; i++) {
						outputEmployee(employees[i]);
					}
				}
				else {

				}
				
			}
			else {
				cout << "Error!\n";
				cout << ~eLen << endl;
			}
			break;
		}
	}
	
	
	
	system("pause");
	return 0;
}


void setNames1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

bool inputNumber(int &n) {
	if (!(cin >> n)) {
		cin.clear();
		while (cin.get() != '\n');
		return false;
	}
	return true;
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
	cout << "The person is\t\t" << sex << ";\n";
}


bool reWriteEmployee(string filename, employee employees[], int length) {
	bool r = false;
	ofstream f(filename, ios::binary);
	if (f.is_open() &&
		f.write((char*)&length, sizeof(length)) &&
		f.write((char*)employees, sizeof(employee) * length)
		) {
		r = true;
	}
	f.close();
	return r;
}

bool appendEmployee(string filename, employee employees[], int length){
	bool r = false;
	fstream f(filename, ios::in | ios::binary);
	int lengthOld;
	if (
		f.is_open() &&
		f.read((char*)&lengthOld, sizeof(lengthOld))
		)
	{
		length += lengthOld;
		employee *employeesFromFile = new employee[length];
		cout << employeesFromFile << endl;
		cout << &employeesFromFile << endl;
		//f.read((char*)employeesFromFile, sizeof(employee) * lengthOld);
		f.close();

		//int eIndx = 0, i;
		//for (i = lengthOld; i < length; ++i) {
		//	employeesFromFile[i] = employees[eIndx];
		//	++eIndx;
		//}
		//r = reWriteEmployee(filename, employeesFromFile, length);

		delete[] employeesFromFile;

	}
	f.close();
	return r;
}

employee* read_from_binary_file(string filename, int &len) {
	fstream f(filename, ios::in | ios::binary);
	if (!(f.is_open())){
		len = -1;
		cout << "error read" << endl;
	}
	else{
		f.read((char*)&len, sizeof(len));
		employee *employees = new employee[len];
		f.read((char*)employees, sizeof(employee) * len);
		f.close();
		return employees;
	}
	f.close();
	return false;
}