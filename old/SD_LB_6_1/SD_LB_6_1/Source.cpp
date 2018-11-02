#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	double avarage;
	long int num[20], min, max, n, min_pair;
	long long  product = 1;
	cout << "Введіть кількість елементів масиву: ";
	cin >> n;
	if (n > 0) {
		cout << "Введіть n[0] : ";
		cin >> num[0];
		if (num[0] > 0)
			product = num[0];
		avarage = min_pair = min = max = num[0];
		for (long int i = 1; i < n && i<20; i++) {
			cout << "Введіть n[" << i << "] : ";
			cin >> num[i];
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
		cout << "Середнє арифметиччне: " << avarage << endl;
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