#include <iostream>
#include "queue_container.cpp"

using namespace std;

struct device {
	char name[30];
	unsigned short yearOfIssue;
	unsigned costInDollars;
};

device& inputDevice();
void printHead();
void printDevice(device current);
void getData(queue_container<device>& obj);

int main() {
	queue_container<device> queueDevices;
	
start:
	char choise;
	cout << "\nEnter what you want to do with queue:\n";
	cout << "- add element to queue (1)\n";
	cout << "- remove element from queue (2)\n";
	cout << "- print queue (3)\n";
	cout << "- exit (4)\n\n";
	cout << "Make your choise: ";
	cin >> choise;
	
	switch (choise) {
	case '1':
		device current;
		current = inputDevice();
		queueDevices.push(current);

		break;
	case '2':
		queueDevices.pop();
		break;
	case '3':
		getData(queueDevices);
		break;

	case '4':
		return 0;
		break;
	default:
		cout << "Error with inputing!\n";
		break;
	}

	cout << "\n Do you want to continue work with queue? (y/n) ";
	cin >> choise;

	if (choise == 'y') {
		goto start;
	}


	/*

	
	computer mouse
	20
	2002
	
	computer monitor
	50
	2009
	
	computer keyboard
	30
	2015
	
	computer HDD
	60
	2018
	
	computer SSD
	100
	2018
	
	
	*/
	return 0;
}

device& inputDevice() {
	device current;
	cout << "Enter the name of device: ";

	cin.get();
	cin.getline(current.name, 30);

	cout << "Enter the cost of device (in $): ";
	cin >> current.costInDollars;

	cout << "Enter the year of issue: ";
	cin >> current.yearOfIssue;

	return current;
}

void printHead() {
	cout.width(30);
	cout << "Name";

	cout.width(8);
	cout << "Cost";

	cout.width(20);
	cout << "Year of issue";

	cout << endl;
}

void printDevice(device current) {

	cout.width(30);
	cout << current.name;

	cout.width(8);
	cout << current.costInDollars;

	cout.width(20);
	cout << current.yearOfIssue;
	
	cout << endl;
}

void getData(queue_container<device>& obj) {
	queue_container<device>::Node<device>* current = obj.head;
	
	if (current == nullptr) {
		cout << "Queue is empty!\n";
		return;
	}

	printHead();
	while (current != nullptr) {
		printDevice( current->data );
		current = current->next;
	}
}
