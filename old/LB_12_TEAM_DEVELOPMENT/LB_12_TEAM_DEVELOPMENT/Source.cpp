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
	cout << "Що потрібно зробити?\n";
	cout << "1 - обчислити для нових резисторів\n";
	cout << "2 - вивести інформацію про існуючих\n";
	cin >> choise;
	if (choise == '2') {
		if (!readResistanceFromFile(filename)) {
			cout << "Помилка при відкритті файла\n";
		}
	}
	else {
	inp:

		cout << "Введіть кількість резисторів (2 або 3):\n";

		while (!inputNumber(resQunt)) {
			cout << "Помилка введення! Повторіть ввід.\n";
		}

		double resistances[3];
		switch (resQunt) {
		case 2:{
			inputResistanses(resistances, resQunt);
			char is_parallel;
			string additional;

			cout << "З'єднання паралельне?\n(1) - Так, (0) - Ні\n";
			cin >> is_parallel;
			if (is_parallel == '1') {
				res = resistance_parallel(resistances, resQunt);
				additional = "Опір паралельного з'єднання: ";
			}
			else {
				res = resistance_successively(resistances, resQunt);
				additional = "Опір послідовного з'єднання: ";
			}
			if (~(int)res) {
				cout << additional << res << endl;
				cout << "Потрібно записувати в файл?\n(1) - Так, (0) - Ні\n";

				cin >> choise;
				if (choise == '1') {
					if (!writeResistanceIntoFile(filename, resistances, resQunt, additional + to_string(res))) {
						cout << "Помилка запису в файл!\n";
					}
				}
			}
			else {
				cout << "Опір не може бути від'ємним!!\n";
			}

			break;
		}
		case 3:{
			inputResistanses(resistances, resQunt);

			int parallelQuantity = 0, pr = 0, sr = 0;
			int parallRes[3];
			int successivelyRes[3];
			for (int i = 0; i < resQunt; i++) {
				cout <<"Як "<< i + 1 << "-й резистор приєднаний по відношенню до інших? (1) - паралельно, (0) - послідовно\n";
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
				additional = "При умові, що всі паралельні: ";
			}
			else if (parallelQuantity == 0) {
				res = resistance_successively(resistances, resQunt);
				additional = "При умові, що всі послідовні: ";
			}
			else if (parallelQuantity == 1) {
				res = summary_resistance_parallel(resistances[ successivelyRes[0] ], 
												  resistances[ successivelyRes[1] ],
												  resistances[ parallRes[0]		  ]);
				additional = "При умові, що " +
					to_string( (int)resistances[successivelyRes[1]] )+
					" та " + to_string( (int)resistances[successivelyRes[1]] ) +
					" послідовні, а " + to_string( (int)resistances[parallRes[0]] ) + " під'єднаний паралельно: ";
			}
			else {
				res = summary_resistance_successively(resistances[ parallRes[0]		  ],
													  resistances[ parallRes[1]		  ], 
													  resistances[ successivelyRes[0] ]);
				additional = "При умові, що " +
					to_string( (int)resistances[ parallRes[0] ] ) +
					" та " + to_string( (int)resistances[ parallRes[1] ] ) +
					" паралельні, а " + to_string( (int)resistances[ successivelyRes[0] ] ) + " під'єднаний послідовно: ";
			}

			if (~(int)res) {
				cout << "Опір такої системи: " << res << endl;

				cout << "Потрібно записувати в файл?\n(1) - Так, (0) - Ні\n";
				cin >> choise;
				if (choise == '1') {
					if (!writeResistanceIntoFile(filename, resistances, resQunt, additional + to_string(res))) {
						cout << "Помилка запису в файл!\n";
					}
				}
			}
			else {
				cout << "Опір не може бути від'ємним!!\n";
			}
			
			break;
		}
		default:
			clearStream();
			cout << "Помилка введення! Повторіть ввід.\n";
			goto inp;
		}

	}
	cout << "Запустити ще раз? (1) - Так. (0) - Ні.\n";
	cin >> choise;
	if (choise == '1') {
		system("cls");
		goto start;
	}

	system("pause");
	return 0;
}