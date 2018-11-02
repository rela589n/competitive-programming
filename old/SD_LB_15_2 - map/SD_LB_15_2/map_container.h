#pragma once

template <class Key, 
			class Val>
class map_container
{
public:
	template <class nKey,
		class nVal>
	class Node;

	map_container(int(*setCompare)(Key a, Key b) = defaultCompare);
	~map_container();

	unsigned size();
	bool empty();

	bool erase(Key);
	void clear();

	void each(void(*callback)(const Key&, const Val&));

	Val& operator [] (Key);

private:
	template <class nKey,
		class nVal>
	class Node {
	public:
		nKey key;
		nVal value;
		Node<nKey, nVal> *left, *right;

		Node(nKey key, nVal value, Node* left = nullptr, Node* right = nullptr) {
			this->left = left;
			this->right = right;
			this->key = key;
			this->value = value;
		}
	};

	Node<Key, Val>* root;
	unsigned sizeOfMap;

	int(*compare)(Key a, Key b);
	static int defaultCompare(Key a, Key b);

	Node<Key, Val>*& privateInsert(Node<Key, Val>*& currentRoot, Key id, Val data);

	void privateEach(void(*callback)(const Key&, const Val&), Node<Key, Val>* currentRoot);
	Node<Key, Val>*& findNode(Key id, Node<Key, Val>*& currentRoot);

	Node<Key, Val>*& privateErase(Key elem, Node<Key, Val>*& currentRoot);
	void privateClear(Node<Key, Val>*& currentRoot);

};