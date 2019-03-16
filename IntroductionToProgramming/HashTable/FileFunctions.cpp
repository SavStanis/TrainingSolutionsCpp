#include "FileFunctions.h"
#include <sstream>
#include <iostream>


void hashTableInput(std::fstream &input, HashTable &table)
{
	std::string line;
	while (!input.eof())
	{
		std::getline(input, line);
		table.push(line);
	}
}