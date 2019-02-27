#include "stdafx.h"
#include "Node.h"


Node::Node(int value, Node* prev, Node* next)
{
	this->value = value;
	this->next = next;
	this->prev = prev;
}
