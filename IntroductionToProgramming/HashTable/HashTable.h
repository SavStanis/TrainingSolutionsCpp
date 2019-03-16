#pragma once
#include <string>
#include "LinkedList.h"

class HashTable
{
private:
	int size;
	int maxSize;
	LinkedList<std::string>* table;
public:
	HashTable(int n = 1000);
	int hash(std::string name);
	void push(std::string value);
	std::string find(std::string name);
	void resizeOfTable();
};

