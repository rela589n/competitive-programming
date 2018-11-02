#include "set_container.h"


template <class S>
set_container<S>::set_container(short (*setCompare)(S a, S b))
{
	root = nullptr;
	sizeOfSet = 0;
	compare = setCompare;
}

template <class S>
set_container<S>::~set_container()
{

}

template <class S>
void set_container<S>::clear() {
	privateClear(root);
	sizeOfSet = 0;
	root = nullptr;
}

template <class S>
void set_container<S>::privateClear(Node<S>*& currentRoot)
{
	if (currentRoot == nullptr) return;

	privateClear(currentRoot->left);
	privateClear(currentRoot->right);
	delete currentRoot;
}


template<class S>
short set_container<S>::defaultCompare(S a, S b)
{
	return (a > b) ? 1 : (a < b)? -1 : 0;
}


template<class S>
unsigned set_container<S>::size()
{
	return sizeOfSet;
}

template <class S>
bool set_container<S>::empty() {
	return !sizeOfSet;
}

template <class S>
void set_container<S>::insert(S data)
{
	privateInsert(data, root);
}


template <class S>
void set_container<S>::privateInsert(S data, Node<S>*& currentRoot)
{
	if (currentRoot == nullptr) {
		currentRoot = new Node<S>(data);
		++sizeOfSet;
		return;
	}

	if (compare(data, currentRoot->data) == 1) {
		privateInsert(data, currentRoot->right);
	}
	else {
		privateInsert(data, currentRoot->left);
	}
}

template <class S>
bool set_container<S>::erase(S elem) {
	unsigned oldSize = sizeOfSet;
	privateErase(elem, root);

	return (oldSize - sizeOfSet);
}


template <class S>
set_container<S>::Node<S>*& set_container<S>::privateErase(S elem, Node<S>*& currentRoot) {
	Node<S> *&toRemove = findNode(elem, currentRoot),
		*toReplace;

	if (toRemove == nullptr) return toRemove;

	if (toRemove->right != nullptr) {

		if (toRemove->left == nullptr) {
			toReplace = toRemove->right;
			delete toRemove;

			toRemove = toReplace;
		}
		else {
			toReplace = toRemove->right;
			Node<S>* beforeToReplace = nullptr;

			while (toReplace->left != nullptr) {
				beforeToReplace = toReplace;
				toReplace = toReplace->left;
			}

			if (beforeToReplace != nullptr)
			{
				beforeToReplace->left = toReplace->right;
			}
			else {
				toRemove->right = toReplace->right;
			}

			Node<S>* elToReplace = new Node<S>(toReplace->data, toRemove->left, toRemove->right);

			delete toReplace;
			delete toRemove;
			toRemove = elToReplace;

		}
	}
	else if (toRemove->left != nullptr) {
		toReplace = toRemove->left;
		delete toRemove;

		toRemove = toReplace;
	}
	else {
		delete toRemove;
		toRemove = nullptr;
	}

	--sizeOfSet;

	return toRemove;
}

template <class S>
bool set_container<S>::erase(S elem, unsigned quantity) {
	unsigned oldSize = sizeOfSet;
	
	privateErase(elem, quantity, root);

	return (oldSize - sizeOfSet);
}

template <class S>
void set_container<S>::privateErase(S elem, unsigned &quantity, Node<S>*& currentRoot) {
	if (currentRoot == nullptr || !quantity) return;
	privateErase(elem, --quantity, privateErase(elem, currentRoot));
}

template <class S>
bool set_container<S>::eraseAll(S elem) {
	unsigned oldSize = sizeOfSet;

	privateEraseAll(elem, root);

	return (oldSize - sizeOfSet);
}

template <class S>
void set_container<S>::privateEraseAll(S elem, Node<S> *& currentRoot) {
	if (currentRoot == nullptr) return;
	privateEraseAll(elem, privateErase(elem, currentRoot));
}

template<class S>
void set_container<S>::each(void (*callback)(const S& current)) 
{
	if (root == nullptr) return;
	privateEach(callback, root);
}

template <class S>
void set_container<S>::privateEach(void (*callback)(const S&), Node<S> * currentRoot)
{
	if (currentRoot->left != nullptr) {
		privateEach(callback,currentRoot->left);
	}

	callback(currentRoot->data);

	if (currentRoot->right != nullptr) {
		privateEach(callback, currentRoot->right);
	}
}

template<class S>
void set_container<S>::eachReverse(void(*callback)(const S& current))
{
	if (root == nullptr) return;
	privateEachReverse(callback, root);
}

template <class S>
void set_container<S>::privateEachReverse(void(*callback)(const S&), Node<S> * currentRoot)
{
	if (currentRoot->right != nullptr) {
		privateEachReverse(callback, currentRoot->right);
	}

	callback(currentRoot->data);

	if (currentRoot->left != nullptr) {
		privateEachReverse(callback, currentRoot->left);
	}
	
}

template <class S>
set_container<S>::Node<S>*& set_container<S>::findNode(S data, Node<S>*& currentRoot) {
	if (currentRoot == nullptr) return currentRoot;

	switch (compare(data, currentRoot->data)) {
	case 1:
		return findNode(data, currentRoot->right);
	case 0:
		return currentRoot;
	case -1:
		return findNode(data, currentRoot->left);
	}
}

template <class S>
std::vector<S> set_container<S>::find(S data) {
	std::vector<S> elements;

	Node<S>* current = findNode(data, root);

	while (current != nullptr) {
		elements.push_back(current->data);

		current = findNode(data, current->left);
	}

	return elements;
}

template<class S>
std::vector<S> set_container<S>::findBiggest()
{
	std::vector<S> elements;
	
	Node<S>* current = root;

	while (current->right != nullptr) {
		current = current->right;
	}

	S data = current->data;

	while (current != nullptr) {
		elements.push_back(current->data);

		current = findNode(data, current->left);
	}

	return elements;
}

template<class S>
std::vector<S> set_container<S>::findLeast()
{
	std::vector<S> elements;

	Node<S>* current = root;

	while (current->left != nullptr) {
		current = current->left;
	}

	S data = current->data;

	while (current != nullptr) {
		elements.push_back(current->data);

		current = findNode(data, current->left);
	}

	return elements;
}
