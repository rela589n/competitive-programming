#pragma once


#pragma once

template <typename L>
class queue_container 
{
public:
	queue_container();
	~queue_container();

	void push(L data);

	void pop();

	unsigned size();
	bool empty();

	L & back();

	void clear();


private:

	template <class T>
	class Node {
	public:
		T data;
		Node *next;

		Node(T data = T(), Node *next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	Node<L> *head, *foot;
	unsigned queueSize;
};
