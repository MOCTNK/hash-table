#pragma once
#include <iostream>
#include <string>
#include "MyHashTable.h"
#include "MyHashTableChain.h"
using namespace std;

class Menu {
private:
public:
	void start();
	template <typename T> void create(MyHashTable<T>& MyHashTable);
	template <typename T> void fillHashTable(MyHashTable<T>& MyHashTable) {};
	template <typename T> void randomFillHashTable(MyHashTable<T>& MyHashTable) {};
	template <typename T> void printHashTable(MyHashTable<T>& MyHashTable) {};
	template <typename T> void addByKey(MyHashTable<T>& MyHashTable) {};
	template <typename T> void deleteNodeByKey(MyHashTable<T>& MyHashTable) {};
	template <typename T> void clearHashTable(MyHashTable<T>& MyHashTable) {};
	template <typename T> void isHashTableEmpty(MyHashTable<T>& MyHashTable) {};
	template <typename T> void getValueByKey(MyHashTable<T>& MyHashTable) {};
	template <typename T> void getSize(MyHashTable<T>& MyHashTable) {};
	template <typename T> void getMenuIterator(MyHashTable<T>& MyHashTable) {};
	void menuIterator(typename MyHashTable<int>::Iterator& iterator);
	template <typename T> void create(MyHashTableChain<T>& MyHashTable);
	template <typename T> void fillHashTable(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void randomFillHashTable(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void printHashTable(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void addByKey(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void deleteNodeByKey(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void clearHashTable(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void isHashTableEmpty(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void getValueByKey(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void getSize(MyHashTableChain<T>& MyHashTable) {};
	template <typename T> void getMenuIterator(MyHashTableChain<T>& MyHashTable) {};
	void menuIterator(typename MyHashTableChain<int>::Iterator& iterator);
	int getRandomNumber(int min, int max);
	string getRandomKey(int size);
	int enterNumber(int min, int max);
	string enterString();
	void testBigO(int n);
	void testBigO2(int n);
	void testX(int P, int m);
	void message(const char* mes);
	int dec2(int num);
	int dec10(string str);
	int toHash(string str);
	int hashFunc(int key, int size);
};

void Menu::start() {
	while (true) {
		bool exit = false;
		int action;
		cout << "Enter type data" << endl;
		cout << "1) int" << endl;
		cout << "2) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		MyHashTable<int> myHashTable;
		MyHashTableChain<int> myHashTableChain;
		cout << endl;

		switch (action) {
		case 1:
			break;
		case 2:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}
		cout << endl;

		cout << "Enter type Hash Table" << endl;
		cout << "1) hash table with open addressing" << endl;
		cout << "2) hash table with collision chains" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);

		switch (action) {
		case 1:
			create<int>(myHashTable);
			break;
		case 2:
			create<int>(myHashTableChain);
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}
	}
}

template <typename T> void Menu::create(MyHashTable<T>& myHashTable) {
	cout << endl;
	cout << endl;
	MyHashTable<T> table = myHashTable;
	int action;
	while (true) {
		bool exit = false;
		cout << "fill the Hash Table:" << endl;
		cout << "1) random" << endl;
		cout << "2) add values" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		cout << endl;

		switch (action) {
		case 1:
			randomFillHashTable(table);
			exit = true;
			break;
		case 2:
			fillHashTable(table);
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu:" << endl;
		cout << "1) print Hash Table" << endl;
		cout << "2) insert Node by key" << endl;
		cout << "3) delete Node by key" << endl;
		cout << "4) search Node by key" << endl;
		cout << "5) clear Hash Table" << endl;
		cout << "6) Hash Table is empty?" << endl;
		cout << "7) menu iterator" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 9);
		cout << endl;

		switch (action) {
		case 1:
			printHashTable(table);
			break;
		case 2:
			addByKey(table);
			break;
		case 3:
			deleteNodeByKey(table);
			break;
		case 4:
			getValueByKey(table);
			break;
		case 5:
			clearHashTable(table);
			break;
		case 6:
			isHashTableEmpty(table);
			break;
		case 7:
			getMenuIterator(table);
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		cout << endl;

		if (exit) {
			break;
		}

		cout << endl;
	}
}

template <> void Menu::fillHashTable(MyHashTable<int>& MyHashTable) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	MyHashTable.setSize(size);
	int value;
	string key;
	for (int i = 0; i < size / 2; i++) {
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) >= 0) {
				cout << "Error! This key exists" << endl;
			}
			else {
				break;
			}
		}
		cout << "Enter value:" << endl;
		value = enterNumber(0, 2147483647);
		MyHashTable.insert(key, value);
	}
	message("HashTable is filled");
	MyHashTable.print();
	cout << endl;
}

template <> void Menu::randomFillHashTable(MyHashTable<int>& MyHashTable) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	MyHashTable.setSize(size);
	for (int i = 0; i < size / 2; i++) {
		string key;
		while (true) {
			key = getRandomKey(8);
			if (MyHashTable.search(key) < 0) {
				break;
			}
		}
		MyHashTable.insert(key, getRandomNumber(1, 100));
	}
	message("HashTable is filled");
	MyHashTable.print();
	cout << endl;
};

template <> void Menu::printHashTable(MyHashTable<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		MyHashTable.print();
	}
	else {
		message("HashTable is empty!");
	}
}

template <> void Menu::getSize(MyHashTable<int>& MyHashTable) {
	cout << "Size: " << MyHashTable.getSize() << endl;
}

template <> void Menu::addByKey(MyHashTable<int>& MyHashTable) {
	string key;
	int value;
	cout << "Enter key:" << endl;
	key = enterString();
	cout << "Enter value:" << endl;
	value = enterNumber(0, 2147483647);
	MyHashTable.insert(key, value);
	message("Node added");
}

template <> void Menu::deleteNodeByKey(MyHashTable<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		string key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) < 0) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				break;
			}
		}
		MyHashTable.deleteByKey(key);
		message("Node deleted");
	}
	else {
		message("Error! HashTable is empty");
	}
}

template <> void Menu::clearHashTable(MyHashTable<int>& MyHashTable) {
	MyHashTable.clear();
	message("HashTable cleared");
}

template <> void Menu::isHashTableEmpty(MyHashTable<int>& MyHashTable) {
	if (MyHashTable.isEmpty()) {
		cout << "HashTable is empty" << endl;
	}
	else {
		cout << "HashTable is not empty" << endl;
	}
}

template <> void Menu::getValueByKey(MyHashTable<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		string key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) < 0) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				cout << "Value: " << MyHashTable.getValueByKey(key) << endl;
				break;
			}
		}
		cout << endl;
	}
	else {
		message("Error! HashTable is empty");
	}
}

template <> void Menu::getMenuIterator(MyHashTable<int>& table) {
	if (!table.isEmpty()) {
		while (true) {
			bool exit = false;
			MyHashTable<int>::Iterator iter = table.begin();
			int action;
			cout << "Enter iterator" << endl;
			cout << "1) Iterator" << endl;
			cout << "2) exit" << endl;
			cout << "Enter action: " << endl;
			action = enterNumber(1, 3);
			cout << endl;

			switch (action) {
			case 1:
				menuIterator(iter);
				break;
			case 2:
				exit = true;
				break;
			default:
				std::cout << "error";
				break;
			}

			if (exit) {
				break;
			}

			cout << endl;
		}
	}
	else {
		message("Error! HashTable is empty");
	}
}

void Menu::menuIterator(typename MyHashTable<int>::Iterator& iterator) {

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Iterator" << endl;
		cout << "1) print key" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) print key list -->" << endl;
		cout << "5) print key list <--" << endl;
		cout << "6) begin" << endl;
		cout << "7) end" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 8);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Key: " << *iterator << endl;
			break;
		case 2:
			message("Next key selected");
			iterator++;
			break;
		case 3:
			message("Prev key selected");
			iterator--;
			break;
		case 4:
			iterator = iterator.begin();
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << "[" << i << "]  " << *iterator << endl;
				iterator++;
			}
			break;
		case 5:
			iterator = iterator.end();
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << "[" << iterator.getId() << "]  " << *iterator << endl;
				iterator--;
			}
			break;
		case 6:
			message("Iterator is installed to begin");
			iterator = iterator.begin();
			break;
		case 7:
			message("Iterator is installed to end");
			iterator = iterator.end();
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

template <typename T> void Menu::create(MyHashTableChain<T>& myHashTable) {
	cout << endl;
	cout << endl;
	MyHashTableChain<T> table = myHashTable;
	int action;
	while (true) {
		bool exit = false;
		cout << "fill the Hash Table:" << endl;
		cout << "1) random" << endl;
		cout << "2) add values" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 2);
		cout << endl;

		switch (action) {
		case 1:
			randomFillHashTable(table);
			exit = true;
			break;
		case 2:
			fillHashTable(table);
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu:" << endl;
		cout << "1) print Hash Table" << endl;
		cout << "2) insert Node by key" << endl;
		cout << "3) delete Node by key" << endl;
		cout << "4) search Node by key" << endl;
		cout << "5) clear Hash Table" << endl;
		cout << "6) Hash Table is empty?" << endl;
		cout << "7) menu iterator" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action:" << endl;
		action = enterNumber(1, 9);
		cout << endl;

		switch (action) {
		case 1:
			printHashTable(table);
			break;
		case 2:
			addByKey(table);
			break;
		case 3:
			deleteNodeByKey(table);
			break;
		case 4:
			getValueByKey(table);
			break;
		case 5:
			clearHashTable(table);
			break;
		case 6:
			isHashTableEmpty(table);
			break;
		case 7:
			getMenuIterator(table);
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		cout << endl;

		if (exit) {
			break;
		}

		cout << endl;
	}
}

template <> void Menu::fillHashTable(MyHashTableChain<int>& MyHashTable) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	MyHashTable.setSize(size);
	int value;
	string key;
	for (int i = 0; i < size / 2; i++) {
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) >= 0) {
				cout << "Error! This key exists" << endl;
			}
			else {
				break;
			}
		}
		cout << "Enter value:" << endl;
		value = enterNumber(0, 2147483647);
		MyHashTable.insert(key, value);
	}
	message("HashTable is filled");
	MyHashTable.print();
	cout << endl;
}

template <> void Menu::randomFillHashTable(MyHashTableChain<int>& MyHashTable) {
	int size;
	while (true) {
		cout << "Enter size:" << endl;
		size = enterNumber(0, 2147483647);
		break;
	}
	MyHashTable.setSize(size);
	for (int i = 0; i < size / 2; i++) {
		string key;
		while (true) {
			key = getRandomKey(8);
			if (MyHashTable.search(key) < 0) {
				break;
			}
		}
		MyHashTable.insert(key, getRandomNumber(1, 100));
	}
	message("HashTable is filled");
	MyHashTable.print();
	cout << endl;
};

template <> void Menu::printHashTable(MyHashTableChain<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		MyHashTable.print();
	}
	else {
		message("HashTable is empty!");
	}
}

template <> void Menu::getSize(MyHashTableChain<int>& MyHashTable) {
	cout << "Size: " << MyHashTable.getSize() << endl;
}

template <> void Menu::addByKey(MyHashTableChain<int>& MyHashTable) {
	string key;
	int value;
	cout << "Enter key:" << endl;
	key = enterString();
	cout << "Enter value:" << endl;
	value = enterNumber(0, 2147483647);
	MyHashTable.insert(key, value);
	message("Node added");
}

template <> void Menu::deleteNodeByKey(MyHashTableChain<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		string key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) < 0) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				break;
			}
		}
		MyHashTable.deleteByKey(key);
		message("Node deleted");
	}
	else {
		message("Error! HashTable is empty");
	}
}

template <> void Menu::clearHashTable(MyHashTableChain<int>& MyHashTable) {
	MyHashTable.clear();
	message("HashTable cleared");
}

template <> void Menu::isHashTableEmpty(MyHashTableChain<int>& MyHashTable) {
	if (MyHashTable.isEmpty()) {
		cout << "HashTable is empty" << endl;
	}
	else {
		cout << "HashTable is not empty" << endl;
	}
}

template <> void Menu::getValueByKey(MyHashTableChain<int>& MyHashTable) {
	if (!MyHashTable.isEmpty()) {
		string key;
		while (true) {
			cout << "Enter key:" << endl;
			key = enterString();
			if (MyHashTable.search(key) < 0) {
				cout << "Error! This key not exists" << endl;
			}
			else {
				cout << "Value: " << MyHashTable.getValueByKey(key) << endl;
				break;
			}
		}
		cout << endl;
	}
	else {
		message("Error! HashTable is empty");
	}
}

template <> void Menu::getMenuIterator(MyHashTableChain<int>& table) {
	if (!table.isEmpty()) {
		while (true) {
			bool exit = false;
			MyHashTableChain<int>::Iterator iter = table.begin();
			int action;
			cout << "Enter iterator" << endl;
			cout << "1) Iterator" << endl;
			cout << "2) exit" << endl;
			cout << "Enter action: " << endl;
			action = enterNumber(1, 3);
			cout << endl;

			switch (action) {
			case 1:
				menuIterator(iter);
				break;
			case 2:
				exit = true;
				break;
			default:
				std::cout << "error";
				break;
			}

			if (exit) {
				break;
			}

			cout << endl;
		}
	}
	else {
		message("Error! HashTable is empty");
	}
}

void Menu::menuIterator(typename MyHashTableChain<int>::Iterator& iterator) {

	while (true) {
		bool exit = false;
		int action;
		cout << "Menu Iterator" << endl;
		cout << "1) print key" << endl;
		cout << "2) next" << endl;
		cout << "3) prev" << endl;
		cout << "4) print key list -->" << endl;
		cout << "5) print key list <--" << endl;
		cout << "6) begin" << endl;
		cout << "7) end" << endl;
		cout << "8) exit" << endl;
		cout << "Enter action: ";
		action = enterNumber(1, 8);
		cout << endl;

		switch (action) {
		case 1:
			cout << "Key: " << *iterator << endl;
			break;
		case 2:
			message("Next key selected");
			iterator++;
			break;
		case 3:
			message("Prev key selected");
			iterator--;
			break;
		case 4:
			iterator = iterator.begin();
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << "[" << i << "]  " << *iterator << endl;
				iterator++;
			}
			break;
		case 5:
			iterator = iterator.end();
			for (int i = 0; i < iterator.getSize(); i++) {
				cout << "[" << iterator.getId() << "]  " << *iterator << endl;
				iterator--;
			}
			break;
		case 6:
			message("Iterator is installed to begin");
			iterator = iterator.begin();
			break;
		case 7:
			message("Iterator is installed to end");
			iterator = iterator.end();
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "error";
			break;
		}

		if (exit) {
			break;
		}

		cout << endl;
	}
}

int Menu::getRandomNumber(int min, int max) {
	return min + rand() % (max - min + 1);
}

string Menu::getRandomKey(int size) {
	string s = "";
	for (int i = 0; i < size; i++) {
		int c = getRandomNumber(65, 90);
		s += (char)c;
	}
	return s;
}

int Menu::enterNumber(int min, int max) {
	int number = min - 1;
	while (true) {
		cout << ">> ";
		cin >> number;
		if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
			break;
		}
		else {
			cout << "Incorrect value!" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
		cout << endl;
	}
	return number;
}

string Menu::enterString() {
	string line;
	while (true) {
		cout << ">> ";
		cin >> line;
		//getline(cin, line);
		bool error = false;
		for (int i = 0; i < line.size(); i++) {
			if (!((int)line[i] >= 65 and (int)line[i] <= 90)) {
				error = true;
			}
		}
		if (!error && (cin.peek() == '\n')) {
			break;
		}
		else {
			cout << "Incorrect value!" << endl;
			cin.clear();
			while (cin.get() != '\n') {}
		}
		cout << endl;
	}
	return line;
}

void Menu::testBigO(int n) {
	MyHashTable<int> myHashTableChain;
	myHashTableChain.setSize(n);

	string* m = new string[n/2];

	srand(time(0));

	for (int i = 0; i < n/2; i++) {
		m[i] = getRandomKey(6);
	}
	for (int i = 0; i < n/2; i++) {
		myHashTableChain.insert(m[getRandomNumber(0, n / 2 - 1)], 6);

	}
	string ss = m[getRandomNumber(0, n / 2 - 1)];

	cout << "items count before test:" << myHashTableChain.getCapacity() << endl;

	double I = 0;
	double D = 0;
	double S = 0;

	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0)		
		{
			myHashTableChain.clearLastIteration();
			myHashTableChain.deleteByKey(m[getRandomNumber(0, n / 2 - 1)]);
			D += myHashTableChain.getLastIteration();

			myHashTableChain.clearLastIteration();
			myHashTableChain.insert(getRandomKey(6), 5);
			I += myHashTableChain.getLastIteration();

			myHashTableChain.clearLastIteration();
			try {
				myHashTableChain.search(m[getRandomNumber(0, n / 2 - 1)]);
				S += myHashTableChain.getLastIteration();
			}

			catch (exception) { S += myHashTableChain.getLastIteration(); }
		}
		else
		{
			myHashTableChain.clearLastIteration();
			myHashTableChain.deleteByKey(m[getRandomNumber(0, n / 2 - 1)]);
			D += myHashTableChain.getLastIteration();

			myHashTableChain.clearLastIteration();
			myHashTableChain.insert(getRandomKey(6), 5);
			I += myHashTableChain.getLastIteration();

			myHashTableChain.clearLastIteration();
			try {
				myHashTableChain.search(m[getRandomNumber(0, n / 2 - 1)]);
				S += myHashTableChain.getLastIteration();
			}

			catch (exception) { S += myHashTableChain.getLastIteration(); }

		}


	cout << "items count after test:" << myHashTableChain.getCapacity() << endl;

	int a = myHashTableChain.getCapacity() / myHashTableChain.getSize();
	cout << "1/2(1+1/(1-a)) = " << (0.5 * (1 + 1 / (1 - a))) << endl;

	cout << "Count insert: " << I / (n / 2) << endl;

	cout << "Count delete: " << D / (n / 2) << endl;

	cout << "Count search: " << S / (n / 2) << endl << endl;

	delete[] m;
}

void Menu::testBigO2(int n) {
	MyHashTable<int> myHashTable;
	myHashTable.setSize(n);

	string* m = new string[n / 2];

	srand(time(0));

	for (int i = 0; i < n / 2; i++) {
		m[i] = getRandomKey(6);
	}
	for (int i = 0; i < n / 2; i++) {
		myHashTable.insert(m[getRandomNumber(0, n / 2 - 1)], 6);

	}
	string ss = m[getRandomNumber(0, n / 2 - 1)];

	cout << "items count before test:" << myHashTable.getCapacity() << endl;

	double I = 0;
	double D = 0;
	double S = 0;

	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0)
		{
			myHashTable.clearLastIteration();
			myHashTable.deleteByKey(m[getRandomNumber(0, n / 2 - 1)]);
			D += myHashTable.getLastIteration();

			myHashTable.clearLastIteration();
			myHashTable.insert(getRandomKey(6), 5);
			I += myHashTable.getLastIteration();

			myHashTable.clearLastIteration();
			try {
				myHashTable.search(m[getRandomNumber(0, n / 2 - 1)]);
				S += myHashTable.getLastIteration();
			}

			catch (exception) { S += myHashTable.getLastIteration(); }
		}
		else
		{
			myHashTable.clearLastIteration();
			myHashTable.deleteByKey(m[getRandomNumber(0, n / 2 - 1)]);
			D += myHashTable.getLastIteration();

			myHashTable.clearLastIteration();
			myHashTable.insert(getRandomKey(6), 5);
			I += myHashTable.getLastIteration();

			myHashTable.clearLastIteration();
			try {
				myHashTable.search(m[getRandomNumber(0, n / 2 - 1)]);
				S += myHashTable.getLastIteration();
			}

			catch (exception) { S += myHashTable.getLastIteration(); }

		}


	cout << "items count after test:" << myHashTable.getCapacity() << endl;

	int a = myHashTable.getCapacity() / myHashTable.getSize();
	cout << "1/2(1+1/(1-a)) = " << (0.5 * (1 + 1 / (1 - a))) << endl;

	cout << "Count insert: " << I / (n / 2) << endl;

	cout << "Count delete: " << D / (n / 2) << endl;

	cout << "Count search: " << S / (n / 2) << endl << endl;

	delete[] m;
}

void Menu::testX(int P, int m) {
	string* keys = new string[P];
	for (int i = 0; i < P; i++) {
		keys[i] = getRandomKey(20);
	}

	double result = 0;
	for (int j = 0; j < m; j++)
	{
		int f = 0;
		for (int i = 0; i < P; i++)
		{
			if (hashFunc(toHash(keys[i]), m) == j) f++;
		}
		result += pow(f - P / (double)m, 2);
	}
	double X = result * ((double)m / (double)P);

	double ver = 0.0;
	for (int i = 1; i <= 20; ++i) ver += pow(26, i);
	
	cout << "Mosh = " << ver << endl;
	cout << "X^2 = { " << m - sqrt(m) << " ; " << m + sqrt(m) << " }" << endl;
	cout << "Real X^2 = " << X << endl;
}

int Menu::dec2(int num)
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

int Menu::dec10(string str)
{
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		num *= 2;
		num += str[i] - '0';
	}
	return num;
}

int Menu::toHash(string str) {
	string str1 = "";
	for (int i = 0; i < str.size(); i++) {
		int num = (int)str[i] - 39;
		str1 += to_string(dec2(num));
	}

	return dec10(str1);
}

int Menu::hashFunc(int key, int size) {
	int result = size * fmod(key * 0.6180339887, 1);
	return result < 0 ? -result : result;
}

void Menu::message(const char* mes) {
	cout << endl << "------- " << mes << " -------" << endl << endl;
}