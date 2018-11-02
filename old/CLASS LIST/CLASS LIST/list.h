#pragma once

template <class L>
class list
{
public:
	list();
	~list();

	void push_front(L data);
	void insert(L data, int index);
	void push_back(L data);
	
	unsigned getSize();
	L& operator [] (int index);

	void pop_front();
	void removeAt(int index);
	void pop_back();
	void clear();

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
	unsigned size;

	int getIndex(int index);
	Node<L>* getElement(int index);
};