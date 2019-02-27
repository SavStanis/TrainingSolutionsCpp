#include "stdafx.h"
#include <iostream>
#include "Deque.h"


Deque::Deque()
{
	 this->head = nullptr;
	 this->end = nullptr;
	 this->size = 0;
}

void Deque::push_front(int element)
{
	if (size == 0)
	{
		Node* newElement = new Node(element);
		this->end = newElement;
		this->head = newElement;
	}
	else
	{
		Node* newElement = new Node(element);
		this->head->next = newElement;
		newElement->prev = head;
		this->head = newElement;
	}
	this->size++;
	std::cout << "\n---------------\nNew element " << element << " was pushed front\n-----------" << std::endl;
}

void Deque::push_back(int element)
{
	if (size == 0)
	{
		Node* newElement = new Node(element);
		this->end = newElement;
		this->head = newElement;
	}
	else
	{
		Node* newElement = new Node(element);
		this->end->prev = newElement;
		newElement->next = end;
		this->end = newElement;
	}
	this->size++;
	std::cout << "\n--------------\nNew element " << element << " was pushed back\n-----------" << std::endl;
}

int Deque::pop_front()
{
	if (isEmpty())
	{
		std::cout << "-------------\nDeque is Empty\n------------" << std::endl;
		return 0;
	}
	int ret = this->head->value;
	this->head = head->prev;
	this->head->next = nullptr;
	std::cout << "\n--------------\nElement " << ret << " was poped front\n-----------" << std::endl;
	this->size--;
	return ret;
}

int Deque::pop_back()
{
	if (isEmpty())
	{
		std::cout << "-------------\nDeque is Empty\n------------" << std::endl;
		return 0;
	}
	int ret = this->end->value;
	this->end = end->next;
	this->end->prev = nullptr;
	std::cout << "\n--------------\nElement " << ret << " was poped back\n-----------" << std::endl;
	this->size--;
	return ret;
}

void Deque::print()
{
	Node* printer = new Node();
	printer = end;
	for (int i = 0; i < size; i++)
	{
		std::cout << printer->value << " ";
		printer = printer->next;
	}
	if (isEmpty())
	{
		std::cout << "\n----------\nThe Deque is Empty\n----------" << std::endl;
	}
}

void Deque::clear()
{
	this->head = nullptr;
	this->end = nullptr;
	this->size = 0;
}

int Deque::sizeOfDeque()
{
	return size;
}

bool Deque::isEmpty()
{
	if (size == 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}