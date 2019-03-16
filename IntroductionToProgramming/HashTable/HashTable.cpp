#include "HashTable.h"
#include <cmath>


HashTable::HashTable(int n)
{
	this->maxSize = n;
	table = new LinkedList<std::string>[maxSize];
	size = 0;
}

int HashTable::hash(std::string word)
{
	long long h = 3;
	const int seed = 5;
	for (int i = 0; i < word.length(); i++)
	{
		h += pow((int)word[i], seed);
		h %= maxSize;
	}
	return h; 
}

void HashTable::push(std::string value)
{
	int i = value.find(';');
	std::string name = value.substr(0, i);
	int hashResult = hash(name);
	table[hashResult].push(name, value);
	size++;
}

std::string HashTable::find(std::string name)
{
	for (int i = 0; i < name.size(); i++)
	{
		name[i] = (char)toupper(name[i]);
	}
	int hashResult = hash(name);
	return table[hashResult].find(name);
}
