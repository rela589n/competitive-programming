#pragma once

template <class L>
class list
{
public:
	list();
	~list();

	void push_front(const L& data);
	void insert(const L& data, int index);
	void push_back(const L& data);

	unsigned size();
	L& operator [] (int index);
	L& front();
	L& back();

	void pop_front();
	void removeAt(int index);
	void pop_back();
	void clear();

	bool empty();

private:

	template <class T>
	class Node
	{
	public:
		T data;
		Node *next;

		Node(T data = T(), Node *next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};
	Node<L> *head;
	Node<L>* tail;
	unsigned __size;

	int getIndex(int index);
	Node<L>* getElement(int index);
};