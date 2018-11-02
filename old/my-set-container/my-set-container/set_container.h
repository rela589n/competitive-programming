#pragma once

#include <vector>


template <class S>
class set_container
{
public:
	template <class N>
	class Node;

	set_container(short(*setCompare)(S a, S b) = defaultCompare);
	~set_container();

	unsigned size();
	bool empty();
	void insert(S);

	bool erase(S);
	bool erase(S, unsigned);
	bool eraseAll(S);
	void clear();
	

	void each( void (*callback)(const S& current) );
	void eachReverse( void (*callback)(const S& current) );
	

	std::vector<S> find(S data);
	std::vector<S> findBiggest();
	std::vector<S> findLeast();

private:

	template <class N>
	class Node {
	public:
		N data;
		Node<N> *left, *right;

		Node (N data = N(), Node* left = nullptr, Node* right = nullptr) {
			this->left = left;
			this->right = right;
			this->data = data;
		}
	};

	Node<S>* root;
	unsigned sizeOfSet;

	short(*compare)(S a, S b);
	static short defaultCompare(S a, S b);

	void privateInsert(S data, Node<S>*& currentRoot);
	
	void privateEach( void(*callback)(const S&), Node<S>* currentRoot );
	void privateEachReverse( void(*callback)(const S&), Node<S>* currentRoot );
	Node<S>*& findNode(S data, Node<S>*& currentRoot);

	Node<S>*& privateErase(S elem, Node<S>*& currentRoot);
	void privateErase(S elem, unsigned &quantity, Node<S>*& currentRoot);
	void privateEraseAll(S elem, Node<S>*& currentRoot);
	void privateClear(Node<S>*& currentRoot);

};

