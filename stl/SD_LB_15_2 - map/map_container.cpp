#include "map_container.h"


template<class Key, class Val>
map_container<Key, Val>::map_container(int(*setCompare)(Key a, Key b))
{
	root = nullptr;
	sizeOfMap = 0;
	compare = setCompare;
}

template<class Key, class Val>
map_container<Key, Val>::~map_container()
{

}

template<class Key, class Val>
void map_container<Key, Val>::clear() {
	privateClear(root);
	sizeOfMap = 0;
	root = nullptr;
}

template<class Key, class Val>
void map_container<Key, Val>::privateClear(Node<Key, Val>*& currentRoot)
{
	if (currentRoot == nullptr) return;

	privateClear(currentRoot->left);
	privateClear(currentRoot->right);
	delete currentRoot;
}


template<class Key, 
			class Val>
int map_container<Key, Val>::defaultCompare(Key a, Key b)
{
	return (a > b)? 1: (a < b)? -1 : 0;
}


template<class Key, class Val>
unsigned map_container<Key, Val>::size()
{
	return sizeOfMap;
}

template<class Key, 
			class Val>
bool map_container<Key, Val>::empty() {
	return !sizeOfMap;
}

template<class Key, class Val>
map_container<Key, Val>::Node<Key, Val>*& map_container<Key, Val>::privateInsert(Node<Key, Val>*& currentRoot, Key id, Val data)
{
	if (currentRoot == nullptr) {
		currentRoot = new Node<Key, Val>(id, data);
		++sizeOfMap;
		return currentRoot;
	}

	if (compare(id, currentRoot->key) > 0) {
		return privateInsert(currentRoot->right, id, data);
	}
	else {
		return privateInsert(currentRoot->left, id, data);
	}
}

template<class Key, class Val>
bool map_container<Key, Val>::erase(Key id) {
	unsigned oldSize = sizeOfMap;

	privateErase(id, root);

	return (oldSize - sizeOfMap);
}


template<class Key, class Val>
map_container<Key, Val>::Node<Key, Val>*& map_container<Key, Val>::privateErase(Key id, Node<Key, Val>*& currentRoot) {
	Node<Key, Val> *&toRemove = findNode(id, currentRoot),
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
			Node<Key, Val>* beforeToReplace = nullptr;

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

			Node<Key, Val>* elToReplace = new Node<Key, Val>(toReplace->key, toReplace->value, toRemove->left, toRemove->right);

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

	--sizeOfMap;

	return toRemove;
}

template<class Key, class Val>
Val & map_container<Key, Val>::operator[](Key id)
{
	Node<Key, Val> *found = findNode(id, root);
	
	if (found == nullptr) {
		found = privateInsert(root, id, Val());
	}

	return found->value;
}

template<class Key, class Val>
void map_container<Key, Val>::each(void(*callback)(const Key&, const Val&))
{
	if (root == nullptr) return;
	privateEach(callback, root);
}

template<class Key, class Val>
void map_container<Key, Val>::privateEach(void(*callback)(const Key&, const Val&), Node<Key, Val> * currentRoot)
{
	if (currentRoot->left != nullptr) {
		privateEach(callback, currentRoot->left);
	}

	callback(currentRoot->key, currentRoot->value);

	if (currentRoot->right != nullptr) {
		privateEach(callback, currentRoot->right);
	}
}

template<class Key, class Val>
map_container<Key, Val>::Node<Key, Val>*& map_container<Key, Val>::findNode(Key id, Node<Key, Val>*& currentRoot) {
	if (currentRoot == nullptr) return currentRoot;

	int compared = compare(id, currentRoot->key);

	if (compared > 0) {
		return findNode(id, currentRoot->right);
	}
	if (compared < 0) {
		return findNode(id, currentRoot->left);
	}

	return currentRoot;
}