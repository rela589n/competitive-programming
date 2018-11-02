#include <iostream>
#include "linked_list.cpp"
#include "people.h"
#include "find_spouse.h"

void printSymbol(char sym, int num);

int main(void) {
	list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	lst.removeAt(3);

	lst.removeAt(0);

	lst.pop_back();
	lst.pop_back();
	
	lst.push_back(5);

	cout << lst.front();
	cout << lst.back();

	


	list<people> men;
	list<people> women;
	people p1, p2;
	
	cout.width(80);

	cout << "Input information about people:\n";

	char c = 'y';
	while (c != 'n') {
		people p = inputPerson();
		if (p.gender) {
			men.push_back(p);
		}
		else {
			women.push_back(p);
		}
		cout << "Do you want to continue inputing? (y/n)";
		cin >> c;
	}

	cout << "\t\t\t\t\t\tlist of man:\n";
	outputPeople(men);

	cout << "\n\n\t\t\t\t\t\tlist of woman:\n";
	outputPeople(women);

	cout << "\n\n\t\t\t\t\t\tlist of couples:\n";
	bool is_empty = true;
	for (int i = 0; i < men.size(); i++) {

		for (int j = 0; j < women.size(); j++) {
			if (is_spouse(men[i], women[j])) {
				printHeader();
				printPerson(men[i]);
				cout << endl;
				cout.width(75);
				cout << "WITH";
				cout << endl << endl;
				printPerson(women[i]);
				printSymbol('-', 150);
				cout << "\n";
				is_empty = false;
			}
		}
	}
	if (is_empty) {
		cout << "Is empty!\n";
	}

	system("pause");
	return 0;
}

void printSymbol(char sym, int num) {
	for (int i = 0; i < num; i++) {
		cout << sym;
	}
}