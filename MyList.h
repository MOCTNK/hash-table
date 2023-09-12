#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T> class MyList {
public:
	class Element {
	public:
		Element* next = NULL;
		string key = "";
		T value = NULL;
	};
	Element* begin = NULL;
	MyList();
	~MyList();
	void insertElement(string key, T value);
	void deleteElement(string key);
	Element* getElement(string key);
	void clear();
	string printList();
	bool isEmpty() {
		return begin == NULL ? true : false;
	}
private:
};

template <class T> MyList<T>::MyList() {

}

template <class T> MyList<T>::~MyList() {
	clear();
}

template <class T> void MyList<T>::insertElement(string key, T value) {
	if (begin == NULL) {
		begin = new Element;
		begin->key = key;
		begin->value = value;
	}
	else {
		Element* e = getElement(key);
		if (e == NULL) {
			Element* b = begin;
			while (true) {
				if (b->next == NULL) {
					break;
				}
				b = b->next;
			}
			b->next = new Element;
			b = b->next;
			b->key = key;
			b->value = value;
		}
		else {
			e->value = value;
		}
	}
}

template <class T> void MyList<T>::deleteElement(string key) {
	if (begin == NULL) {
		return;
	}
	Element* e = getElement(key);
	if (e == NULL) {
		return;
	}
	if (e == begin) {
		begin = e->next;
		delete e;
	}
	else {
		Element* b = begin;
		while (true) {
			if (b->next == e) {
				break;
			}
			b = b->next;
		}
		b->next = e->next;
		delete e;
	}
}

template <class T> typename MyList<T>::Element* MyList<T>::getElement(string key) {
	if (begin == NULL) {
		return NULL;
	}
	Element* b = begin;
	while (true) {
		if (b == NULL) {
			break;
		}
		if (b->key == key) {
			break;
		}
		b = b->next;
	}
	return b;
}

template <class T> void MyList<T>::clear() {
	Element* b = begin;
	while (true) {
		if (b == NULL) {
			break;
		}
		Element* e = b->next;
		delete b;
		b = e;
	}
}

template <class T> string MyList<T>::printList() {
	Element* b = begin;
	string s = "";
	while (true) {
		if (b == NULL) {
			break;
		}
		s += b->key + "(" + to_string(b->value) + ") ";
		b = b->next;
	}
	return s;
}