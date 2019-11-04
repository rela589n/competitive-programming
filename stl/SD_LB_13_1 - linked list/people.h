#pragma once

#include <string>
using namespace std;

struct people {
	string name;
	bool gender;
	int age;
	int height;
	int weight;
	int minAge;
	int maxAge;
	int minHeightOfPartner;
	int maxHeightOfPartner;
	int minWeightOfPartner;
	int maxWeightOfPartner;

	unsigned id,
			 spouseId = 0;
};

void outputPeople(list<people>& lst);
people inputPerson();
void printHeader();
void printPerson(people p);
unsigned getUniqueID();

void outputPeople(list<people>& lst) {
	unsigned size = lst.getSize();

	if (!size) {
		return;
	}

	printHeader();
	for(int i = 0; i < size; i++) {
		printPerson( lst[i] );
	}
}

people inputPerson() {
	people p;

	char g;
	cout << "Enter gender, (1) - man, (0) - woman: ";
	cin >> g;
	p.gender = (g == '1') ? true : false;

	cin.get();
	cout << "Enter Name: ";
	getline(cin, p.name);

	cout << "Enter age: ";
	cin >> p.age;

	cout << "Enter height: ";
	cin >> p.height;

	cout << "Enter weight: ";
	cin >> p.weight;

	cout << "Enter min age of partner: ";
	cin >> p.minAge;

	cout << "Enter max age of partner: ";
	cin >> p.maxAge;

	cout << "Enter min Height of partner: ";
	cin >> p.minHeightOfPartner;

	cout << "Enter max Height of partner: ";
	cin >> p.maxHeightOfPartner;

	cout << "Enter min Weight of partner: ";
	cin >> p.minWeightOfPartner;

	cout << "Enter max Weight of partner: ";
	cin >> p.maxWeightOfPartner;

	p.id = getUniqueID();

	return p;
}

void printHeader() {
	cout << endl;

	cout.width(15);
	cout << "Name";

	cout.width(10);
	cout << "gender";

	cout.width(8);
	cout << "age";

	cout.width(10);
	cout << "height";

	cout.width(10);
	cout << "weight";

	cout.width(12);
	cout << "min age";

	cout.width(12);
	cout << "max age";

	cout.width(15);
	cout << "min Height";

	cout.width(15);
	cout << "max Height";

	cout.width(15);
	cout << "min Weight";

	cout.width(15);
	cout << "max Weight\n";
}

void printPerson(people p) {
	string gender = (p.gender) ? "man  " : "woman";

	cout.width(15);
	cout << p.name;

	cout.width(10);
	cout << gender;

	cout.width(8);
	cout << p.age;

	cout.width(10);
	cout << p.height;

	cout.width(10);
	cout << p.weight;

	cout.width(12);
	cout << p.minAge;

	cout.width(12);
	cout << p.maxAge;

	cout.width(15);
	cout << p.minHeightOfPartner;

	cout.width(15);
	cout << p.maxHeightOfPartner;

	cout.width(15);
	cout << p.minWeightOfPartner;

	cout.width(15);
	cout << p.maxWeightOfPartner << "\n";
}

unsigned getUniqueID()
{
	static unsigned id = 1;

	return id++;
}