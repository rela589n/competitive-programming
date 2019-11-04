#include <iostream>
#include "set_container.cpp"

using namespace std;

struct service {
	char name[30];
	unsigned short amountOfEmployees;
	unsigned wage;
};

service& inputService();
void printHead();
void printService(service current);

int main() {

	set_container<service> services( [] (service a, service b) -> int {
		return a.wage - b.wage;
	});

start:
	char choise;
	cout << "\nEnter what you want to do with binary tree:\n";
	cout << "- add element to tree (1)\n";
	cout << "- remove element from tree (2)\n";
	cout << "- clear tree (3)\n";
	cout << "- find in tree (4)\n";
	cout << "- print tree (5)\n";
	cout << "- exit (6)\n\n";
	cout << "Make your choise: ";
	cin >> choise;

	switch (choise) {
	case '1': {

		service current;
		current = inputService();
		services.insert(current);

		break;
	}
	case '2': {
		if (services.empty()) {
			cout << "\nTree is empty!\n\n";
			break;
		}

		cout << "Remove all services with the same wage? (y/n) ";
		cin >> choise;

		bool completed;

		service toDelete;
		if (choise == 'y') {
			cout << "Enter wage: ";
			cin >> toDelete.wage;
			completed = services.eraseAll(toDelete);
		}
		else {
			cout << "Enter info about service what you want to delete from tree...\n\n";
			toDelete = inputService();

			completed = services.erase(toDelete, [](service a, service b) -> int {
				if (a.amountOfEmployees == b.amountOfEmployees &&
					(strcmp(a.name, b.name) == 0) &&
					a.wage == b.wage) {
					return 0;
				}
				return (a.wage > b.wage) ? 1 : -1;
			});
		}

		if (completed) {
			cout << "\nCompleted!\n\n";
		}
		else {
			cout << "\nThere is not such element in the tree!\n";
		}

		break;
	}
	case '3': {
		if (services.empty()) {
			cout << "\nTree is empty!\n\n";
			break;
		}

		services.clear();
		cout << "\nCompleted!\n\n";

		break;
	}
	case '4': {
		if (services.empty()) {
			cout << "\nTree is empty!\n\n";
			break;
		}
		vector<service> found;

		cout << "Find service with biggest (1) or with least (2) wage or input info about service (3)? ";
		cin >> choise;

		if (choise == '1') {
			found = services.findBiggest();
		}
		else if (choise == '2') {
			found = services.findLeast();
		}
		else {
			cout << "Exact match (1) or with the same wage (2)? ";
			cin >> choise;

			service toFind;
			vector<service> newFound;
			if (choise == '1') {
				cout << "Enter info about service what you want to find in tree...\n\n";
				toFind = inputService();
				found = services.find(toFind);

				for (auto i = found.begin(); i < found.end(); ++i) {
					service current = *i;
					if (current.amountOfEmployees == toFind.amountOfEmployees &&
						(strcmp(current.name, toFind.name) == 0) &&
						current.wage == toFind.wage)
					{
						newFound.push_back(current);
					}
				}

				found.clear();
				found = newFound;
			}
			else {
				cout << "Enter wage: ";
				cin >> toFind.wage;
				found = services.find(toFind);
			}
		}

		if (!found.empty()) {
			cout << "Search results: \n\n";
			printHead();
			for (service current : found) {
				printService(current);
			}
		}
		else {
			cout << "There is not such element in tree!\n\n";
		}
		break;
	}
	case '5':
		if (services.empty()) {
			cout << "\nTree is empty!\n\n";
			break;
		}

		printHead();
		services.each( [](const service& current) {
			printService(current);
		});
		cout << endl;

		break;
	case '6':
		return 0;
	default:
		cout << "Error with inputing!\n\n";
		break;
	}

	goto start;
}

service& inputService() {
	service current;
	cout << "Enter the name of service: ";

	cin.get();
	cin.getline(current.name, 30);

	cout << "Enter the amount of employees in service: ";
	cin >> current.amountOfEmployees;

	cout << "Enter the wage per employee: ";
	cin >> current.wage;

	return current;
}


void printHead() {
	cout.width(30);
	cout << "Name";

	cout.width(15);
	cout << "Employees";

	cout.width(10);
	cout << "Wage";

	cout << endl;
}


void printService(service current) {

	cout.width(30);
	cout << current.name;

	cout.width(15);
	cout << current.amountOfEmployees;

	cout.width(10);
	cout << current.wage;

	cout << endl;
}