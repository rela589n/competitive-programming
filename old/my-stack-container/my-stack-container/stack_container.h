#pragma once

template <class L>
class stack_container
{
public:
	stack_container();
	~stack_container();

	void push(L data);
	void pop();
	void clear();
	bool empty();
	L& top();

	unsigned size();

private:
	template <class T>
	class Node {
	public:
		T data;
		Node* next;

		Node(T data = T(), Node* next = nullptr) {
			this->data = data;
			this->next = next;
		};
	};

	Node<L> * head;
	unsigned stackSize;

};