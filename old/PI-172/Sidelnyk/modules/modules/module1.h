#pragma once


#include <fstream>


struct good {
	int price;
	char name[200];
};


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
