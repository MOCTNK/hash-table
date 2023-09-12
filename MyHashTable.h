#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T> class MyHashTable {
public:
	class Node {
	public:
		bool free = true;
		string key = "";
		T value = NULL;
		bool isFree() { return free; };
		string getKey() { return key; };
		T getValue() { return value; };
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
	MyHashTable();
	~MyHashTable();
	int getIndex(string key);
	void insert(string key, T value);
	int search(string key);
	void deleteByKey(string key);
	T getValueByKey(string key);
	void print();
	bool isEmpty();
	bool isFull();
	void clear();
	int getSize() { return size; };
	int getCapacity() { return capacity; };
	void setSize(int size);
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
	int quadraticProbing(int key, int i);
	int iterations = 0;
};

template <class T> MyHashTable<T>::MyHashTable() {

}

template <class T> MyHashTable<T>::~MyHashTable() {
	delete[] data;
}

template <class T> int MyHashTable<T>::dec2(int num)
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

template <class T> int MyHashTable<T>::dec10(string str)
{
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		num *= 2;
		num += str[i] - '0';
	}
	return num;
}

template <class T> int MyHashTable<T>::toHash(string str) {
	string str1 = "";
	for (int i = 0; i < str.size(); i++) {
		int num = (int)str[i] - 39;
		str1 += to_string(dec2(num));
	}

	return dec10(str1);
}

template <class T> int MyHashTable<T>::hashFunc(int key) {
	int result = size * fmod(key * 0.6180339887, 1);
	return result < 0 ? -result : result;
}

template <class T> int MyHashTable<T>::quadraticProbing(int key, int i) {
	double c1 = 0.6180339887;
	double c2 = 0.8986039787;
	int result = fmod(hashFunc(key) + c1*i + c2*i*i, size);
	return result < 0 ? -result : result;
}

template <class T> int MyHashTable<T>::getIndex(string key) {
	int hash = toHash(key);
	int id = hashFunc(hash);
	int i = 1;
	while (true) {
		iterations++;
		if (data[id].isFree() or data[id].getKey() == key) {
			return id;
			break;
		}
		else {
			//cout << " QP key: " << key << " i: " << i << endl;
			id = quadraticProbing(hash, i);
			i++;
		}
	}
}

template <class T> void MyHashTable<T>::insert(string key, T value) {
	if (!isFull()) {
		int id = getIndex(key);
		data[id].key = key;
		data[id].value = value;
		data[id].free = false;
		capacity++;
	}
	else {
		cout << "Error! table is full" << endl;
	}
}

template <class T> int MyHashTable<T>::search(string key) {
	int hash = toHash(key);
	int id = hashFunc(hash);
	int i = 1;
	while (i < size - 1) {
		iterations++;
		if (data[id].getKey() == key) {
			return id;
			break;
		}
		else {
			id = quadraticProbing(hash, i);
			i++;
		}
	}
	return -1;
}

template <class T> void MyHashTable<T>::deleteByKey(string key) {
	if (!isEmpty()) {
		int id = search(key);
		if (id >= 0) {
			data[id].key = "";
			data[id].value = NULL;
			data[id].free = true;
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

template <class T> T MyHashTable<T>::getValueByKey(string key) {
	if (!isEmpty()) {
		int id = search(key);
		if (id >= 0) {
			return data[id].value;
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

template <class T> void MyHashTable<T>::print() {
	cout << "size: " << size << " capacity: " << capacity << endl;
	for (int i = 0; i < size; i++) {
		if (!data[i].isFree()) {
			cout << "[" << i << "] " << data[i].key << "(" << data[i].value << ")" << endl;
		}
	}
}

template <class T> bool MyHashTable<T>::isEmpty() {
	return capacity == 0 ? true : false;
}

template <class T> bool MyHashTable<T>::isFull() {
	return capacity == size ? true : false;
}

template <class T> void MyHashTable<T>::clear() {
	delete[] data;
	data = new Node[size];
	capacity = 0;
}

template <class T> void MyHashTable<T>::setSize(int size) {
	this->size = size;
	data = new Node[size];
}

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::begin() {
	Iterator iter(data, size);
	return iter;
};

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::end() {
	Iterator iter(data, size);
	iter.end();
	return iter;
};

template <class T> MyHashTable<T>::Iterator::Iterator(typename MyHashTable<T>::Node *data, int size) {
	this->size = size;
	this->data = data;
	this->status = true;
};

template <class T> typename MyHashTable<T>::Iterator& MyHashTable<T>::Iterator::operator++() {
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

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::Iterator::operator++(int) {
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

template <class T> typename MyHashTable<T>::Iterator& MyHashTable<T>::Iterator::operator--() {
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

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::Iterator::operator--(int) {
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

template <class T> bool MyHashTable<T>::Iterator::operator==(MyHashTable<T>::Iterator other) const {
	return data[id].getKey() == other.data[other.id].getKey();
}

template <class T> bool MyHashTable<T>::Iterator::operator!=(MyHashTable<T>::Iterator other) const {
	return !(*this == other);
}

template <class T> string MyHashTable<T>::Iterator::operator*() const {
	if (status) {
		if (data[id].isFree()) {
			return "";
		}
		else {
			return data[id].getKey();
		}
	}
	else {
		cout << "Iterator is not installed" << endl;
	}
	return "NULL";
}

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::Iterator::begin() {
	id = 0;
	status = true;
	return *this;
}

template <class T> typename MyHashTable<T>::Iterator MyHashTable<T>::Iterator::end() {
	id = size - 1;
	status = true;
	return *this;
}


template <class T> int MyHashTable<T>::getLastIteration() {
	return iterations;
}

template <class T> void MyHashTable<T>::clearLastIteration() {
	iterations = 0;
}