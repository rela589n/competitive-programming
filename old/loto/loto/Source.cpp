#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	l: srand(time(NULL));
	
	
	int min, max, i;
	short int level, flag;

	cout << "\tДобро пожаловать в игру \"Цифровая лотерея\"." << endl;
	cout << "Правила таковы:\nНомер уровня - количество цыфр в числе, которое загадали, а пользователь должен угадать цифры этого числа" << endl;
	cout << "но при этом не одноцифровые числа не начинаются с нуля, например:" << endl;
	cout << "ко второму уровню не принадлежт 09, но принадлежит число 74. То-есть второй уровень" << endl;
	cout << "находится в диапазоне от 10 до 99" << endl;
	cout << "Всего есть 4 уровня сложности, где 1 - самый легкий, а 4 - самый сложный," << endl;
	cout << "соответственно и выигрыш будет разным." << endl << "\tТаблица выигрышей:" << endl;
	cout << "Уровень|\t1\t|2\t|3\t|4" << endl;
	cout << "Выигрыш|\t99$\t|999$\t|9999$\t|99999$" << endl;
	cout << "Игра на каждом из уровней соит одинаково: 10$ за раз" << endl;
	cout << "Что ж, давайте начнём! Введите сюда номер уровня: ";
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
		
		cout << "Угадайте число: ";
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
				cout << "Вы проиграли" << endl;
			}
			else {
				cout << "У вас почти получиллось!" << endl;
				float win = correctly * 100 / quantity_numbers;
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << "Вы угадали на " << win << "%" << endl;
			}
			cout << "Задуманное число:\t" << invented_num << endl;
			cout << "Ваше число:\t\t" << user_num << endl;
		}
	}
	else {
		cout << "Неверно введённый уровень\a" << endl;

	}
	cout << "Сыграем ещё раз?\n 1 - Да, 0 - Нет" << endl;
	cin >> flag;
	if (flag) {
		system("cls");
		goto l;
	}
	system("pause");
	return 0;
}