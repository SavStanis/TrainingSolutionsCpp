#include <iostream>
#include "HashTable.h"
#include "FileFunctions.h"

int main()
{
	std::fstream input("dict_processed.txt");
	HashTable table(100000);
	hashTableInput(input, table);
	std::cout << "Input the sentence" << std::endl;
	std::string sentence;
	std::getline(std::cin, sentence);
	std::cout << table.find(sentence);
	std::system("pause");
}

