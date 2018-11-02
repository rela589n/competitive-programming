#include <iostream>
#include <string>
#include "map_container.cpp"

using namespace std;

int main() {
	map_container<string, string> a;

start:
	char choise;
	cout << "\nActions with map:\n\n";
	cout << "Add element to map      (1)\n"; 
	cout << "Remove element from map (2)\n";
	cout << "Get element by key      (3)\n";
	cout << "Print all elements      (4)\n";
	cout << "Clear map               (5)\n";
	cout << "Exit                    (6)\n\n";

	cout << "Make your choise: ";
	cin >> choise;

	switch (choise) {
	case '1':{
		string key;
		
		cin.get();
		cout << "Enter key: ";
		getline(cin, key);

		cout << "Enter value: ";
		getline(cin, a[key]);

		break;
	}
	case '2': {
		string key;

		cin.get();
		cout << "Enter key: ";
		getline(cin, key);

		a.erase(key);
		
		break;
	}
	case '3': {
		string key;

		cin.get();
		cout << "Enter key: ";
		getline(cin, key);

		if (a[key].length()) {
			cout << "\nValue: " << a[key] << endl;
		}
		else {
			cout << "There is not such element!\n";
			a.erase(key);
		}

		break;
	}
	case '4':
		cout << "\nmap_container {\n";
		
		a.each([](const string& key, const string& val) {
			cout << "\t" << key << " => " << val << endl;
		});

		cout << "}\n\n";

		break;
	case '5':
		a.clear();
		break;
	case '6':
		return 0;
	default:
		cout << "\nInputing error!\n";
	}
	goto start;

}