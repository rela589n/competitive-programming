#include "linked_list.h"

template <class L>
list<L>::list() {
	head = nullptr;
	size = 0;
}

template <class L>
list<L>::~list() {
	clear();
}

template <class L>
void list<L>::push_front(L data) {
	head = new Node<L>(data, head);
	size++;
}

template <class L>
void list<L>::insert(L data, int index) {
	index = getIndex(index);

	if (index == 0) {
		push_front(data);
		return;
	}
	Node<L> *previous = getElement(index - 1);

	if (previous == nullptr) {
		return;
	}

	Node<L> *newEl = new Node<L>(data, previous->next);
	previous->next = newEl;

	size++;
}

template <class L>
void list<L>::push_back(L data) {
	insert(data, size);
}

template<class L>
unsigned list<L>::getSize()
{
	return size;
}

template<class L>
L & list<L>::operator[](int index)
{
	return getElement(index)->data;
}

template <class L>
void list<L>::pop_front()
{
	Node<L> *old = head;

	head = head->next;

	delete old;

	size--;
}

template<class L>
void list<L>::removeAt(int index) {
	index = getIndex(index);

	if (index == 0) {
		pop_front();
		return;
	}

	Node<L> *prev = getElement(index - 1);

	if (prev == nullptr || prev->next == nullptr) {
		return;
	}

	Node<L> *toDel = prev->next;

	prev->next = toDel->next;

	delete toDel;

	size--;

}

template <class L>
void list<L>::pop_back() {
	removeAt(-1);
}

template<class L>
void list<L>::clear() {
	while (size) {
		pop_front();
	}
}

template<class L>
int list<L>::getIndex(int index)
{
	if (index < 0) {
		index += size;
	}
	return index;
}

template<class L>
list<L>::Node<L> * list<L>::getElement(int index) {
	index = getIndex(index);

	if (index < 0) {
		return nullptr;
	}
	Node<L> *current = head;

	for (int i = 0; i < index; i++) {
		if (current == nullptr) break;

		current = current->next;
	}

	return current;
}