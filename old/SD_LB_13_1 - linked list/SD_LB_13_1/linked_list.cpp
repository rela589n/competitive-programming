#include "linked_list.h"

template <class L>
list<L>::list() {
	head = nullptr;
	tail = nullptr;
	__size = 0;
}

template <class L>
list<L>::~list() {
	clear();
}

template <class L>
void list<L>::push_front(const L& data) {
	head = new Node<L>(data, head);
	++__size;
}

template <class L>
void list<L>::insert(const L& data, int index) {
	index = getIndex(index);

	if (index == 0) {
		push_front(data);
		return;
	}

	if (index == __size - 1) {
		push_back(data);
		return;
	}

	Node<L> *previous = getElement(index - 1);

	if (previous == nullptr) {
		return;
	}

	Node<L> *newEl = new Node<L>(data, previous->next);
	previous->next = newEl;

	++__size;
}

template <class L>
void list<L>::push_back(const L& data) {
	if (__size == 0) {
		push_front(data);

		tail = head;

		return;
	}

	Node<L> *newTail = new Node<L>(data, nullptr);

	tail->next = newTail;
	tail = newTail;

	++__size;
}

template<class L>
unsigned list<L>::size()
{
	return __size;
}

template<class L>
L & list<L>::operator[](int index)
{
	return getElement(index)->data;
}

template <class L>
L & list<L>::front()
{
	return head->data;
}

template <class L>
L& list<L>::back()
{
	return tail->data;
}


template <class L>
void list<L>::pop_front()
{
	Node<L> *old = head;

	head = head->next;

	delete old;

	--__size;
}

template<class L>
void list<L>::removeAt(int index) {
	index = getIndex(index);

	if (index == 0) {
		pop_front();
		return;
	}

	if (index == __size - 1) {
		pop_back();
		return;
	}

	Node<L> *prev = getElement(index - 1);

	if (prev == nullptr || prev->next == nullptr) {
		return;
	}

	Node<L> *toDel = prev->next;

	prev->next = toDel->next;

	delete toDel;

	--__size;

}

template <class L>
void list<L>::pop_back() {
	if (__size == 1) {
		pop_front();

		tail = head;

		return;
	}

	Node<L>* oldTail = tail;

	tail = getElement(-2);

	delete oldTail;
	--__size;

	tail->next = nullptr;
}

template<class L>
void list<L>::clear() {
	while (__size) {
		pop_front();
	}
}

template<class L>
bool list<L>::empty() {
	return !__size;
}

template<class L>
int list<L>::getIndex(int index)
{
	if (index < 0) {
		index += __size;
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