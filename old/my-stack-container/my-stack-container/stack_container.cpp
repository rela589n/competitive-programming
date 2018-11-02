#include "stack_container.h"


template <class L>
stack_container<L>::stack_container()
{
	head = nullptr;
	stackSize = 0;
}

template <class L>
stack_container<L>::~stack_container()
{
	clear();
}

template<class L>
void stack_container<L>::push(L data)
{
	head = new Node<L>(data, head);
	++stackSize;
}

template<class L>
void stack_container<L>::pop()
{
	Node<L> *tmp = head;

	head = head->next;

	delete tmp;
	--stackSize;
}
template <class L>
void stack_container<L>::clear() {
	while (stackSize) {
		pop();
	}
}

template<class L>
bool stack_container<L>::empty()
{
	return !stackSize;
}

template<class L>
L & stack_container<L>::top()
{
	return head->data;
}

template<class L>
unsigned stack_container<L>::size()
{
	return stackSize;
}
