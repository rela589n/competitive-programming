#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	l: srand(time(NULL));
	
	
	int min, max, i;
	short int level, flag;

	cout << "\t����� ���������� � ���� \"�������� �������\"." << endl;
	cout << "������� ������:\n����� ������ - ���������� ���� � �����, ������� ��������, � ������������ ������ ������� ����� ����� �����" << endl;
	cout << "�� ��� ���� �� ������������ ����� �� ���������� � ����, ��������:" << endl;
	cout << "�� ������� ������ �� ���������� 09, �� ����������� ����� 74. ��-���� ������ �������" << endl;
	cout << "��������� � ��������� �� 10 �� 99" << endl;
	cout << "����� ���� 4 ������ ���������, ��� 1 - ����� ������, � 4 - ����� �������," << endl;
	cout << "�������������� � ������� ����� ������." << endl << "\t������� ���������:" << endl;
	cout << "�������|\t1\t|2\t|3\t|4" << endl;
	cout << "�������|\t99$\t|999$\t|9999$\t|99999$" << endl;
	cout << "���� �� ������ �� ������� ���� ���������: 10$ �� ���" << endl;
	cout << "��� �, ������� �����! ������� ���� ����� ������: ";
	cin >> level;
	bool err = 0;
	switch (level) {
		case 1:
			min = 0;
			max = 9;
			break;
		case 2:
			min = 10;
			max = 99;
			break;
		case 3:
			min = 100;
			max = 999;
			break;
		case 4:
			min = 1000;
			max = 9999;
			break;
		default:
			err = 1;
	}

	if (!err) {
		int ticket = min + rand() % (max - min + 1), attempt, quantity_numbers, correctly, invented_num, user_num;
		invented_num = ticket;
		//cout << ticket << endl;
		
		cout << "�������� �����: ";
		cin >> attempt;
		while (attempt > max) {
			attempt /= 10;
		}
		while (attempt < min) {
			attempt *= 10;
		}
		user_num = attempt;


		quantity_numbers = correctly = 0;
		while (ticket != 0) {
			if (ticket % 10 == attempt % 10) {
				correctly++;
			}
			quantity_numbers++;
			ticket /= 10;
			attempt /= 10;
		}
		if (correctly == quantity_numbers) {
			cout << "JECK POT!!!" << endl;
		}
		else {
			if (correctly == 0) {
				cout << "�� ���������" << endl;
			}
			else {
				cout << "� ��� ����� �����������!" << endl;
				float win = correctly * 100 / quantity_numbers;
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << "�� ������� �� " << win << "%" << endl;
			}
			cout << "���������� �����:\t" << invented_num << endl;
			cout << "���� �����:\t\t" << user_num << endl;
		}
	}
	else {
		cout << "������� �������� �������\a" << endl;

	}
	cout << "������� ��� ���?\n 1 - ��, 0 - ���" << endl;
	cin >> flag;
	if (flag) {
		system("cls");
		goto l;
	}
	system("pause");
	return 0;
}