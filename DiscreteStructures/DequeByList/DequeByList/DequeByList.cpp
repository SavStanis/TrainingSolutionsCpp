

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Deque.h"

//function for moving the element
void moving(Deque &MyDeque);

int main()
{
	int numberOfElements;
	Deque MyDeque;
	std::cout << "Input how many elements do you want to input:" << std::endl;
	std::cin >> numberOfElements;

	for (int i = 0; i < numberOfElements; i++)
	{
		int element;
		std::cin >> element;
		MyDeque.push_front(element);
	}
	MyDeque.print();
	moving(MyDeque);
	MyDeque.print();

	system("pause");
	return 0;
}

void moving(Deque &MyDeque)
{
	int k, n;	
	std::cout << "Input the number of element which you want to move and the number of positions on which you want to move it" << std::endl;
	std::cin >> k >> n;
	std::cout << "Input 'l', if if you want to move element on the left" << std::endl;
	std::string choice;
	std::cin >> choice;
	int ourElement, intermediateElement, sizeD = MyDeque.sizeOfDeque();
	bool ourElemIsEmpty = false;
	if (choice == "l")
	{
		for (int i = sizeD; i > 1; i--)
		{
			if (i == k)
			{
				ourElement = MyDeque.pop_front();
			}
			if (i == k - n)
			{
				MyDeque.push_back(ourElement);
				ourElemIsEmpty = true;
			}
			intermediateElement = MyDeque.pop_front();
			MyDeque.push_back(intermediateElement);
			if (i == 2 && !ourElemIsEmpty)
			{
				MyDeque.push_back(ourElement);
			}
		}
	}
	else
	{
		for (int i = 1; i < sizeD; i++)
		{
			if (i == k)
			{
				ourElement = MyDeque.pop_back();
			}
			if (i == k + n)
			{
				MyDeque.push_front(ourElement);
				ourElemIsEmpty = true;
			}
			intermediateElement = MyDeque.pop_back();
			MyDeque.push_front(intermediateElement);
			if (i == sizeD - 1 && !ourElemIsEmpty)
			{
				MyDeque.push_front(ourElement);
			}
		}
	}
}