#pragma once
#include <iostream>
#include <string>
#include "MyList.h"
using namespace std;

template <class T> class MyHashTableChain {
public:
	class Node {
	public:
		MyList<T> myList;
	};
	class Iterator {
	private:
		int id;
		int size;
		Node* data;
		bool status;
	public:
		Iterator(Node* data, int size);
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);
		bool operator==(Iterator other) const;
		bool operator!=(Iterator other) const;
		string operator*() const;
		Iterator begin();
		Iterator end();
		int getSize() { return size; };
		int getId() { return id; };
	};
	MyHashTableChain();
	~MyHashTableChain();
	void insert(string key, T value);
	int search(string key);
	void deleteByKey(string key);
	T getValueByKey(string key);
	void print();
	bool isEmpty();
	bool isFull();
	void clear();
	void setSize(int size);
	int getSize() { return size; };
	int getCapacity() { return capacity; };
	Iterator begin();
	Iterator end();
	int getLastIteration();
	void clearLastIteration();
private:
	int size = 0;
	int capacity = 0;
	Node* data = NULL;
	int dec2(int num);
	int dec10(string str);
	int toHash(string str);
	int hashFunc(int key);
	int iterations = 0;
};

template <class T> MyHashTableChain<T>::MyHashTableChain() {

}

template <class T> MyHashTableChain<T>::~MyHashTableChain() {
	delete[] data;
}

template <class T> int MyHashTableChain<T>::dec2(int num)
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}

template <class T> int MyHashTableChain<T>::dec10(string str)
{
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		num *= 2;
		num += str[i] - '0';
	}
	return num;
}

template <class T> int MyHashTableChain<T>::toHash(string str) {
	string str1 = "";
	for (int i = 0; i < str.size(); i++) {
		int num = (int)str[i] - 39;
		str1 += to_string(dec2(num));
	}

	return dec10(str1);
}

template <class T> int MyHashTableChain<T>::hashFunc(int key) {
	int result = size * fmod(key * 0.6180339887, 1);
	return result < 0 ? -result : result;
}

template <class T> void MyHashTableChain<T>::insert(string key, T value) {
	int hash = toHash(key);
	int id = hashFunc(hash);
	data[id].myList.insertElement(key, value);
	capacity++;
}

template <class T> void MyHashTableChain<T>::print() {
	cout << "size: " << size << " capacity: " << capacity << endl;
	for (int i = 0; i < size; i++) {
		if (!data[i].myList.isEmpty()) {
			cout << "[" << i << "] " << data[i].myList.printList() << endl;
		}
	}
}

template <class T> int MyHashTableChain<T>::search(string key) {
	int hash = toHash(key);
	int id = hashFunc(hash);
	typename MyList<T>::Element* e = data[id].myList.getElement(key);
	if (e != NULL) {
		return id;
	}
	return -1;
}

template <class T> void MyHashTableChain<T>::deleteByKey(string key) {
	if (!isEmpty()) {
		int id = search(key);
		if (id >= 0) {
			data[id].myList.deleteElement(key);
			capacity--;
		}
		else {
			cout << "Error! Key is not found!" << endl;
		}
	}
	else {
		cout << "Error! table is empty!" << endl;
	}
}

template <class T> T MyHashTableChain<T>::getValueByKey(string key) {
	if (!isEmpty()) {
		int id = search(key);
		if (id >= 0) {
			typename MyList<T>::Element* e = data[id].myList.getElement(key);
			return e->value;
		}
		else {
			cout << "Error! Key is not found!" << endl;
		}
	}
	else {
		cout << "Error! table is empty!" << endl;
	}
	return NULL;
}

template <class T> bool MyHashTableChain<T>::isEmpty() {
	return capacity == 0 ? true : false;
}

template <class T> bool MyHashTableChain<T>::isFull() {
	return capacity == size ? true : false;
}

template <class T> void MyHashTableChain<T>::clear() {
	delete[] data;
	data = new Node[size];
	capacity = 0;
}

template <class T> void MyHashTableChain<T>::setSize(int size) {
	this->size = size;
	data = new Node[size];
}

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::begin() {
	Iterator iter(data, size);
	return iter;
};

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::end() {
	Iterator iter(data, size);
	iter.end();
	return iter;
};

template <class T> MyHashTableChain<T>::Iterator::Iterator(typename MyHashTableChain<T>::Node* data, int size) {
	this->size = size;
	this->data = data;
	this->status = true;
};

template <class T> typename MyHashTableChain<T>::Iterator& MyHashTableChain<T>::Iterator::operator++() {
	if (status) {
		if (id == size - 1) {
			status = false;
			return *this;
		}
		id++;
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::Iterator::operator++(int) {
	if (status) {
		if (id == size - 1) {
			status = false;
			return *this;
		}
		id++;
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyHashTableChain<T>::Iterator& MyHashTableChain<T>::Iterator::operator--() {
	if (status) {
		if (id > 0) {
			id--;
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::Iterator::operator--(int) {
	if (status) {
		if (id > 0) {
			id--;
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return *this;
}

template <class T> bool MyHashTableChain<T>::Iterator::operator==(MyHashTableChain<T>::Iterator other) const {
	return data[id].getKey() == other.data[other.id].getKey();
}

template <class T> bool MyHashTableChain<T>::Iterator::operator!=(MyHashTableChain<T>::Iterator other) const {
	return !(*this == other);
}

template <class T> string MyHashTableChain<T>::Iterator::operator*() const {
	if (status) {
		if (data[id].myList.isEmpty()) {
			return "";
		}
		else {
			return data[id].myList.printList();
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return "NULL";
}

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::Iterator::begin() {
	id = 0;
	status = true;
	return *this;
}

template <class T> typename MyHashTableChain<T>::Iterator MyHashTableChain<T>::Iterator::end() {
	id = size - 1;
	status = true;
	return *this;
}


template <class T> int MyHashTableChain<T>::getLastIteration() {
	return iterations;
}

template <class T> void MyHashTableChain<T>::clearLastIteration() {
	iterations = 0;
}