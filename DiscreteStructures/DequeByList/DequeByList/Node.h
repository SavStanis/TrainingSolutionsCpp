#pragma once
class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value = 0, Node* prev = nullptr, Node* next = nullptr);
};

