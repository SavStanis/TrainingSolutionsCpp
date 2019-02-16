
#include "stdafx.h"
#include <iostream>

class MyStack
{
private:
	
	//Class of the elements
	class Node
	{
	public:
		Node* pnext;
		int value;

		Node(Node* pnext = nullptr, int value = 0)
		{
			this->pnext = pnext;
			this->value = value;
		}
	};

	Node* head;
	int size;

public:
	
	//Constructor
	MyStack(int size = 0, Node*  head = nullptr)
	{
		this->head = head;
		this->size = size;
	}

	//Put element in the Stack
	void push(int _value)
	{
		if (size == 0) 
		{
			head = new Node();
			this->head->value = _value;
		}
		else
		{
			Node* second = new Node();
			second->pnext = this->head;
			second->value = _value;
			head = second;
		}
		size++;
	}

	//Reading of the head of Stack
	int top()
	{
		if(!IsEmpty())
		return this->head->value;
		std::cout << "---\nStack is Empty\n---" << std::endl;
	}

	//Method for the finding size of the Stack
	int Size()
	{
		return size;
	}

	//Reading of the head of Stack and deleting it from the Stack
	int pop()
	{
		if (size)
		{
			int out = this->head->value;
			head = this->head->pnext;
			this->size--;
			return out;
		}
		else
		{
			std::cout << "---\nSorry, the stack is empty\n------" << std::endl;
		}
	}

	//To check is stack empty
	bool IsEmpty()
	{
		if (size)
		{
			return false;
		}
		return true;
	}

	//Full information about stack now
	void info()
	{
		std::cout << "The value of head is: " << top() << "\tThe size of stack is: " << Size() << std::endl;
	}

	//To clear the stack
	void clear()
	{
		while (size>0)
		{
			this->head = this->head->pnext;
			this->size--;
		}
		std::cout << "\n Cleaning was finished. Stack is Empty" << std::endl;
	}
};

//Function for rewriting insormation from one steck to another one
void rewriting(MyStack* First, MyStack* Second);

int main()
{
	MyStack stack;
	int variable, k;
	std::cout << "How many elements do you want to input?" << std::endl;
	std::cin >> variable;
	for(int i = 0; i < variable; i++)
	{
		std::cin >> k;
		stack.push(k);
		stack.info();
	}

	system("pause");
	system("cls");
	stack.info();

	MyStack intermediateStack;
	MyStack finishStack;
	std::cout << "\n\nRewring from first to the intermediate stack:\n\n" << std::endl;
	rewriting(&stack, &intermediateStack);
	std::cout << "\n\nRewring from intermediate to the finished stack:\n\n" << std::endl;
	rewriting(&intermediateStack, &finishStack);

	system("pause");
	return 0;
}

void rewriting(MyStack* First, MyStack* Second)
{
	while ((First->Size()) > 0)
	{
		Second->push(First->pop());
		Second->info();
	}
}