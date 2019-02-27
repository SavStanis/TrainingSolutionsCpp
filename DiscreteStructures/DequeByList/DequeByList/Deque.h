#pragma once

#include "Node.h"

class Deque
{
	Node* head;
	Node* end;
	int size;

public:
	Deque();

	void push_front(int element);
	void push_back(int element);

	int pop_front();
	int pop_back();

	void print();
	void clear();
	int sizeOfDeque();
	bool isEmpty();

};