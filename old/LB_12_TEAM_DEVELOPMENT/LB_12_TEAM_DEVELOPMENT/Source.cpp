#include "general.h"
#include <fstream>
#include <string>
#include "ioResistance.h"
#include "rwResistance.h"
#include "calculate_resistance.h"




int main()
{
	setNames1251();
start:
	int resQunt;
	double res;
	string filename = "resistances.txt";
	char choise;
	cout << "�� ������� �������?\n";
	cout << "1 - ��������� ��� ����� ���������\n";
	cout << "2 - ������� ���������� ��� ��������\n";
	cin >> choise;
	if (choise == '2') {
		if (!readResistanceFromFile(filename)) {
			cout << "������� ��� ������� �����\n";
		}
	}
	else {
	inp:

		cout << "������ ������� ��������� (2 ��� 3):\n";

		while (!inputNumber(resQunt)) {
			cout << "������� ��������! �������� ���.\n";
		}

		double resistances[3];
		switch (resQunt) {
		case 2:{
			inputResistanses(resistances, resQunt);
			char is_parallel;
			string additional;

			cout << "�'������� ����������?\n(1) - ���, (0) - ͳ\n";
			cin >> is_parallel;
			if (is_parallel == '1') {
				res = resistance_parallel(resistances, resQunt);
				additional = "��� ������������ �'�������: ";
			}
			else {
				res = resistance_successively(resistances, resQunt);
				additional = "��� ����������� �'�������: ";
			}
			if (~(int)res) {
				cout << additional << res << endl;
				cout << "������� ���������� � ����?\n(1) - ���, (0) - ͳ\n";

				cin >> choise;
				if (choise == '1') {
					if (!writeResistanceIntoFile(filename, resistances, resQunt, additional + to_string(res))) {
						cout << "������� ������ � ����!\n";
					}
				}
			}
			else {
				cout << "��� �� ���� ���� ��'�����!!\n";
			}

			break;
		}
		case 3:{
			inputResistanses(resistances, resQunt);

			int parallelQuantity = 0, pr = 0, sr = 0;
			int parallRes[3];
			int successivelyRes[3];
			for (int i = 0; i < resQunt; i++) {
				cout <<"�� "<< i + 1 << "-� �������� ��������� �� ��������� �� �����? (1) - ����������, (0) - ���������\n";
				char is_parallel;
				cin >> is_parallel;
				if (is_parallel == '1') {
					parallelQuantity++;
					parallRes[pr++] = i;
				}
				else {
					successivelyRes[sr++] = i;
				}
			}

			string additional;
			if (parallelQuantity == 3) {
				res = resistance_parallel(resistances, resQunt);
				additional = "��� ����, �� �� ���������: ";
			}
			else if (parallelQuantity == 0) {
				res = resistance_successively(resistances, resQunt);
				additional = "��� ����, �� �� ��������: ";
			}
			else if (parallelQuantity == 1) {
				res = summary_resistance_parallel(resistances[ successivelyRes[0] ], 
												  resistances[ successivelyRes[1] ],
												  resistances[ parallRes[0]		  ]);
				additional = "��� ����, �� " +
					to_string( (int)resistances[successivelyRes[1]] )+
					" �� " + to_string( (int)resistances[successivelyRes[1]] ) +
					" ��������, � " + to_string( (int)resistances[parallRes[0]] ) + " ��'������� ����������: ";
			}
			else {
				res = summary_resistance_successively(resistances[ parallRes[0]		  ],
													  resistances[ parallRes[1]		  ], 
													  resistances[ successivelyRes[0] ]);
				additional = "��� ����, �� " +
					to_string( (int)resistances[ parallRes[0] ] ) +
					" �� " + to_string( (int)resistances[ parallRes[1] ] ) +
					" ���������, � " + to_string( (int)resistances[ successivelyRes[0] ] ) + " ��'������� ���������: ";
			}

			if (~(int)res) {
				cout << "��� ���� �������: " << res << endl;

				cout << "������� ���������� � ����?\n(1) - ���, (0) - ͳ\n";
				cin >> choise;
				if (choise == '1') {
					if (!writeResistanceIntoFile(filename, resistances, resQunt, additional + to_string(res))) {
						cout << "������� ������ � ����!\n";
					}
				}
			}
			else {
				cout << "��� �� ���� ���� ��'�����!!\n";
			}
			
			break;
		}
		default:
			clearStream();
			cout << "������� ��������! �������� ���.\n";
			goto inp;
		}

	}
	cout << "��������� �� ���? (1) - ���. (0) - ͳ.\n";
	cin >> choise;
	if (choise == '1') {
		system("cls");
		goto start;
	}

	system("pause");
	return 0;
}