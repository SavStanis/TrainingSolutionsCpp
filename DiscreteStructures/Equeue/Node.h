#pragma once
class Node
{
public:
	int value;
	Node* next = nullptr;
	int priority;
	Node(int value, int priority);

};

