#include <iostream>
#include <vector>
#include "lists.h"

using namespace std;
void printList(list<int>* head);


int main(void) {
	list<int>* head = nullptr;

	pushEnd(head, 12);
	pushEnd(head, 14);
	pushEnd(head, 16);
	pushEnd(head, 18);
	pushEnd(head, 20);

	//getData(lst, 0) = 11;

	cout << getData(head, -2);

	//cout << lst->next;

	system("pause");
	return 0;
}


void printList(list<int>* head) {
	if (head == nullptr) {
		return;
	}
	list<int>* el = head;
	while (el->next != nullptr) {
		cout << el->data << endl;
		el = el->next;
	}
}