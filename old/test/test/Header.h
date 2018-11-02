#pragma once

template <class T>
struct list {
	T data;
	list *next;
};


template <class T>
list<T>* newElem(T data = T(), list<T>*next = nullptr);

template <class T>
void pushEnd(list<T>*& head, T data);

template <class T>
void pushStart(list<T>*& head, T data);

template <class T>
bool push(list<T>*& head, T data, int index);

template <class T>
bool push(list<T>*& previous, T data);

template <class T>
unsigned listSize(list<T>*& head);

template <class T>
int getIndex(list<T>*& head, int index);

template <class T>
list<T>* getElement(list<T>*& head, int index);

template <class T>
T& getData(list<T>*& head, int index);

template <class T>
T& getData(list<T>*& element);

template <class T>
void removeElStart(list<T>*& head);

template <class T>
void clearList(list<T>*& head);

template <class T>
void removeElEnd(list<T>*& head);

template <class T>
bool removeEl(list<T>*& head, int index);

template <class T>
list<T>* listMerge(list<T>*& head1, list<T>*& head2);

template <class T>
list<T>* newElem(T data, list<T>*next) {
	list<T>* el = new list<T>;

	el->data = data;
	el->next = next;

	return el;
}

template <class T>
void pushEnd(list<T>*& head, T data) {
	if (head == nullptr) {
		head = newElem(data);
		return;
	}

	list<T>* el = head;

	while (el->next != nullptr) {
		el = el->next;
	}

	el->next = newElem(data);
}

template <class T>
void pushStart(list<T>*& head, T data) {
	if (head == nullptr) {
		head = newElem(data);
		return;
	}

	list<T>* el = newElem(data, head);
	head = el;
}

template <class T>
unsigned listSize(list<T>*& head) {
	if (head == nullptr) {
		return 0;
	}

	unsigned size = 1;
	list<T>* el = head;

	while (el->next != nullptr) {
		el = el->next;
		size++;
	}

	return size;
}

template <class T>
int getIndex(list<T>*& head, int index) {
	if (index < 0) {
		unsigned size = listSize(head);
		index = size + index;
	}
	return index;
}

template <class T>
list<T>* getElement(list<T>*& head, int index) {

	index = getIndex(head, index);
	if (head == nullptr || index < 0) {
		return nullptr;
	}

	list<T>* el = head;

	for (int i = 0; i < index; i++) {
		if (el == nullptr) {
			return nullptr;
		}
		el = el->next;
	}

	return el;
}

template <class T>
T& getData(list<T>*& head, int index) {
	return getElement(head, index)->data;
}

template <class T>
T& getData(list<T>*& element) {
	if (element == nullptr) {
		return NAN;
	}
	return element->data;
}


template <class T>
bool push(list<T>*& head, T data, int index) {

	index = getIndex(head, index);
	if (index < 0) {
		return false;
	}

	if (index == 0) {
		pushStart(head, data);
		return true;
	}

	list<T>* previous = getElement(head, index - 1);
	if (previous == nullptr) {
		return false;
	}

	list<T>* next = previous->next;
	list<T>* el = newElem(data, next);
	previous->next = el;

	return true;
}

template <class T>
bool push(list<T>*& previous, T data) {	
	if (previous == nullptr) {
		previous = newElem(data);
		return true;
	}
	list<T>* next = previous->next;
	list<T>* el = newElem(data, next);
	previous->next = el;
	return true;
}

template <class T>
void removeElStart(list<T>*& head) {
	if (head == nullptr) {
		return;
	}
	list<T>* el = head->next;
	delete head;
	head = el;
}

template <class T>
void clearList(list<T>*& head) {
	while (head != nullptr) {
		removeElStart(head);
	}
}

//question
template <class T>
void removeElEnd(list<T>*& head) {
	if (head == nullptr) {
		return;
	}

	list<T>* el = head;

	while (el->next->next != nullptr) {
		el = el->next;
	}

	delete el->next;
	el->next = nullptr;
}

//question
template <class T>
bool removeEl(list<T>*& head, int index) {
	if (head == nullptr) {
		return false;
	}

	index = getIndex(head, index);
	if (index < 0) {
		return false;
	}
	if (index == 0) {
		removeElStart(head);
		return true;
	}

	list<T>* previous = getElement(head, index - 1);
	if (previous == nullptr || previous->next == nullptr) {
		return false;
	}
	list<T>* next = previous->next->next;

	delete previous->next;
	previous->next = next;
	return true;
}

template <class T>
list<T>* listMerge(list<T>*& head1, list<T>*& head2) {
	list<T>* el = head1;
	list<T>* lastEl = getElement(el, -1);
	lastEl->next = head2;

	head1 = nullptr;
	head2 = nullptr;

	return el;
}