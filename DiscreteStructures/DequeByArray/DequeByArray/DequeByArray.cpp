// DequeByArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Deque {

private:
	
	int* dequeArray;
	int sizeOfArray;
	int sizeOfDeque;
	int head; 
	int end;

public:

	Deque(int sizeOfArray = 5)
	{
		this->sizeOfArray = sizeOfArray;
		this->dequeArray = new int[sizeOfArray];
		sizeOfDeque = 0;
		head = 0;	
		end = 0;
	}

	void push_front(int element)
	{
		if (sizeOfDeque != sizeOfArray)
		{
			if (sizeOfDeque == 0)
			{
				dequeArray[head] = element;
				sizeOfDeque++;
				std::cout << "Element " << dequeArray[head] << " was pushed front" << std::endl;
			}
			else
			{
				head = (head + 1) % sizeOfArray;
				dequeArray[head] = element;
				std::cout << "Element " << dequeArray[head] << " was pushed front" << std::endl;
				sizeOfDeque++;
			}
		}
		else
		{
			std::cout << "deque is overflow" << std::endl;
		}
	}

	int pop_front()
	{
		if (sizeOfDeque == 0)
		{
			std::cout << "Deque is Empty" << std::endl;
			return 0;
		}

		int ret = dequeArray[head];
		head--;
		if (head < 0)
		{
			head = sizeOfArray - 1;
		}

		std::cout << "Element returned!" << std::endl;
		sizeOfDeque--;
		return ret;
	}

	void push_back(int element)
	{
		if (sizeOfDeque != sizeOfArray)
		{
			if (sizeOfDeque == 0)
			{
				dequeArray[end] = element;
				sizeOfDeque++;
				std::cout << "Element " << dequeArray[end] << " was pushed back" << std::endl;
			}
			else
			{
				end--;
				if (end < 0)
				{
					end = sizeOfArray - 1;
				}
				dequeArray[end] = element;
				std::cout << "Element " << dequeArray[end] << " was pushed back" << std::endl;
				sizeOfDeque++;
			}
		}
		else
		{
			std::cout << "deque is overflow" << std::endl;
		}
	}

	int pop_back()
	{
		if (sizeOfDeque == 0)
		{
			std::cout << "Deque is Empty" << std::endl;
			return 0;
		}
		int ret = dequeArray[end];
		end = (end + 1) % sizeOfArray;
		std::cout << "Element returned!" << std::endl;
		sizeOfDeque--;
		return ret;
	}

	void print()
	{
		std::cout << "------------------\nYour deck is:" << std::endl;
		for (int i = 0; i < sizeOfDeque; i++)
		{
			std::cout << dequeArray[(end + i) % sizeOfArray] << " ";
		}
		std::cout << "\n------------------" << std::endl;
	}

	int size()
	{
		return sizeOfDeque;
	}

	void clear()
	{
		head = 0;
		end = 0;
		sizeOfDeque = 0;
	}

	bool isEmpty()
	{
		if (sizeOfDeque == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	int size, numberOfElements;
	std::cout << "Input the size of array:" << std::endl;
	std::cin >> size;
	Deque MyDeque(size);
	std::cout << "Input how many elements do you want to input:" << std::endl;
	std::cin >> numberOfElements;

	for (int i = 0; i < numberOfElements; i++)
	{
		int element;
		std::cin >> element;
		MyDeque.push_front(element);
	}
	MyDeque.print();

	system("pause");
    return 0;
}

