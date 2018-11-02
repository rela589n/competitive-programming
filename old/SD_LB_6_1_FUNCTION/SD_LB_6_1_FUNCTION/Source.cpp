#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

float my_func(int param);
int main() {
	SetConsoleOutputCP(1251);
	double avarage, num[20], min, max, min_pair;
	long double product = 1;
	long int n;
	cout << "Введіть кількість елементів масиву: ";
	cin >> n;
	if (n > 0) {
		num[0] = my_func(0);
		cout.precision(5);
		cout << "n[0] = " << num[0] << endl;
		if (num[0] > 0)
			product = num[0];
		avarage = min_pair = min = max = num[0];
		for (long int i = 1; i < n && i < 20; i++) {
			num[i] = my_func(i);
			cout << "n[" << i << "] = " << num[i] << endl;
			if (num[i] > 0)
				product *= num[i];
			if (i % 2 == 0 && min_pair > num[i])
				min_pair = num[i];
			if (min > num[i])
				min = num[i];
			if (max < num[i])
				max = num[i];
			avarage += num[i];
		}
		if (product != 1)
			cout << "Добуток додатніх елементів масиву: " << product;
		else
			cout << "Додатніх елементів не зустрічалось";
		cout << endl;
		avarage /= n;
		cout << "Середнє арифметичне: " << avarage << endl;
		cout << "Найбільш віддалений елемент від середнього арифметичного: ";
		if (avarage - min > max - avarage)
			cout << min;
		else
			cout << max;
		cout << endl;
		cout << "Найменший елемент з парним номером: " << min_pair << endl;
	}
	else {
		cout << "Немає елементів";
	}
	system("pause");
	return 0;
}

float my_func(int param) {
	return sin(param) - cos(param);
}