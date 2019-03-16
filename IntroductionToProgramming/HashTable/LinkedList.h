#pragma once

template<typename T>
class LinkedList
{
private:
	template<typename T>
	class Node
	{
	public:
		T name;
		T value;
		Node<T>* next;
		Node<T>* prev;
		Node(T name, T value)
		{
			this->name = name;
			this->value = value;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node<T>* head;
	Node<T>* end;
	int size;
public:
	LinkedList();
	void push (T name, T value);
	T find(T name);
	bool isEmpty();
	int getSize();
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	end = nullptr;
	size = 0;
}

template<typename T>
void LinkedList<T>::push(T name, T value)
{
	Node<T>* newNode = new Node<T>(name, value);
	if (size == 0)
	{
		this->head = newNode;
		this->end = newNode;
	}
	else
	{
		head->next = newNode;
		newNode->prev = head;
		head = newNode;
	}
	size++;
}

template<typename T>
T LinkedList<T>::find(T name)
{
	Node<T>* element = end;
	while (element != nullptr && element->name != name)
	{
		element = element->next;
	}
	return element->value;
}

template<typename T> 
bool LinkedList<T>::isEmpty()
{
	return (size == 0) ? true : false;
}

template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}
