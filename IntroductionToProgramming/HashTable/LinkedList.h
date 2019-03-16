#pragma once

template<typename T>
class LinkedList
{
private:
	template<typename T>
	class Node
	{
	public:
		T value;
		Node<T>* next;
		Node<T>* prev;
		Node(T value)
		{
			this->value = value;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node<T>* head;
	Node<T>* end;
public:
	LinkedList();
	void push(T value);
	T pop();
	void isEmpty();
	int getSize();
};

