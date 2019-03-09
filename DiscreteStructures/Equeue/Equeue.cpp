#include <iostream>
#include "Equeue.h"
#include "Node.h"


Equeue::Equeue()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

void Equeue::push(int value, int priority)
{
	Node* newElement = new Node(value, priority);
	if (size == 0)
	{
		this->head = newElement;
		this->end = newElement;
	}
	else
	{
		Node* present = end;
		Node* past = end;
		while (newElement->priority > present->priority)
		{
			if (present->next == nullptr)
			{
				break;
			}
			past = present;
			present = present->next;
		}
		if (present->next == nullptr && present->priority < newElement->priority)
		{
			present->next = newElement;
			head = newElement;
		}
		else
		{
			if (present == end)
			{
				newElement->next = present;
				end = newElement;
			}
			else
			{
				past->next = newElement;
				newElement->next = present;
			}
		}
	}
	size++;
}

void Equeue::print()
{
	Node* printer = end;
	std::cout << "Equeue:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << printer->value << " ";
		printer = printer->next;
	}
	std::cout << std::endl;
}

int Equeue::pop()
{
	if (size > 1)
	{
		Node* printer = end;
		int ret = head->value;
		while (printer->next != head || printer->next != nullptr)
		{
			printer = printer->next;
		}
		head = printer;
		size--;
		return ret;
	}
	if (size == 1)
	{
		int ret = head->value;
		size--;
		this->head = nullptr;
		this->end = nullptr;
 	}
	else
	{
		std::cout << "\n--------\nEqueue is Empty\n--------\n";
	}
}

bool Equeue::isEmpty()
{
	return (size == 0) ? true : false;
}

void Equeue::sizeOfEqueue()
{
	std::cout << "Size of Equeue is: " << size << std::endl;
}