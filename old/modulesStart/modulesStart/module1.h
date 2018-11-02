#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct good {
	int price;
	char name[200];
};

void clearStream();
void outputGoods(good goods[], int len);
void inputGoods(good goods[], int len);
bool put_goods(char* path, good goods[], int len);
bool inputNumber(int &n);



bool inputNumber(int &n) {
	if (!(cin >> n)) {
		clearStream();
		return false;
	}
	return true;
}

bool put_goods(char* path, good goods[], int len) {
	fstream f;
	f.open(path, ios::binary);

	if (!f.is_open()) {
		return false;
	}
	int streamSize = sizeof(goods[0]);
	for (int i = 0; i < len; i++) {
		f.write((char*)&goods[i], streamSize);
	}
	f.close();
	return true;
}


void inputGoods(good goods[], int len) {
	for (int i = 0; i < len; i++) {
		cin.get();

		cout << "Enter the name of " << i + 1 << " good: ";
		cin.getline(goods[i].name, 200);
		cout << "Enter the price of " << i + 1 << " good: ";
		while (!inputNumber(goods[i].price)) {
			cout << "Input error! please, repeat input: ";
		}
	}
}
void outputGoods(good goods[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "Name of " << i + 1 << " good: ";
		cout << goods[i].name << endl;
		cout << "Price of " << i + 1 << " good: ";
		cout << goods[i].price << endl;
	}
}


void clearStream() {
	cin.clear();
	while (cin.get() != '\n');
}