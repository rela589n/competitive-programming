#include "queue_container.h"

template <class L>
queue_container<L>::queue_container() {
	head = nullptr;
	queueSize = 0;
}

template <class L>
queue_container<L>::~queue_container() {
	clear();
}

template<class L>
void queue_container<L>::push(L data)
{
	if (head == nullptr) {
		head = foot = new Node<L>(data);
	} 
	else {
		foot->next = new Node<L>(data);
		foot = foot->next;
	}

	++queueSize;
}

template<typename L>
void queue_container<L>::pop()
{
	Node<L> *tmp = head;

	head = head->next;

	delete tmp;

	--queueSize;
}

template<typename L>
unsigned queue_container<L>::size()
{
	return queueSize;
}

template<typename L>
bool queue_container<L>::empty()
{
	return !queueSize;
}

template<typename L>
L & queue_container<L>::back()
{
	return head->data;
}

template<typename L>
void queue_container<L>::clear()
{
	while (queueSize) {
		pop();
	}
}
