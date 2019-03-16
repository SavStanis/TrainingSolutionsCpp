#pragma once
#include "Node.h"

class Equeue
{
private:
	Node* head;
	Node* end;
	int size;
public:
	Equeue();
	void push(int value, int priority);
	int pop();
	void print();
	bool isEmpty();
	int sizeOfEqueue();
};

