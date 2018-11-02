#pragma once

void inputResistanses(double resistances[], int len);
void outputResistanses(double resistances[], int len, ostream& stream);


void inputResistanses(double resistances[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << "������ ��� " << i + 1 << "-�� ���������:\n";
		while (!inputNumber(resistances[i])) {
			cout << "������� ��������! �������� ��� " << i << "-�� ���������\n";
		}
	}
}

void outputResistanses(double resistances[], int len, ostream& stream) {
	for (int i = 0; i < len; ++i) {
		stream << "��� " << i + 1 << "-�� ���������:\t\t";
		stream << resistances[i];
		stream << endl;
	}
}