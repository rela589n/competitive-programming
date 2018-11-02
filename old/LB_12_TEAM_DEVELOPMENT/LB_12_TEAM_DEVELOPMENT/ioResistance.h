#pragma once

void inputResistanses(double resistances[], int len);
void outputResistanses(double resistances[], int len, ostream& stream);


void inputResistanses(double resistances[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << "Введіть опір " << i + 1 << "-го резистора:\n";
		while (!inputNumber(resistances[i])) {
			cout << "Помилка введення! Повторіть ввід " << i << "-го резистора\n";
		}
	}
}

void outputResistanses(double resistances[], int len, ostream& stream) {
	for (int i = 0; i < len; ++i) {
		stream << "Опір " << i + 1 << "-го резистора:\t\t";
		stream << resistances[i];
		stream << endl;
	}
}