
#include "stdafx.h"
#include <iostream>


class MyStack 
{
private:
		int SizeOfStack;
		int* StackArray;
		int NumberOfHead = -1;
		
public:
		//Constructor
		MyStack(int N = 5) 
		{
			SizeOfStack = N;
			StackArray = new int[SizeOfStack];
		}

		//put new element in steck
		void push(int newElement) 
		{
			if (NumberOfHead >= SizeOfStack)
			{
				std::cout << "Stack overflow" << std::endl;
			}
			else 
			{
				StackArray[++NumberOfHead] = newElement;
			}
		}

		//It checks if this steck is empty
		bool isEmpty() 
		{
			if (NumberOfHead == -1)
			{
				return true;
			}
			return false;
		}

		//return value of the top element of steck and delete this elevent
		int pop()
		{
			if (!isEmpty()) 
			{
				return StackArray[NumberOfHead--];
			}
			return 0;
		}

		//return the size of stack
		int size()
		{
			return NumberOfHead + 1;
		}

		//return value of the top element of steck
		int top() 
		{
			if (isEmpty())
			{
				return 0;
			}
			return StackArray[NumberOfHead];
		}

		//Full information about the stack
		void info()
		{
			std::cout << " The head of stack is: " 
			<< top() << " Size of stack now: " 
			<< size() << std::endl;
		}

		//clear the steck
		void clear()
		{
			NumberOfHead = -1;
		}
};

//Function for rewriting of information step by step
MyStack rewriting(MyStack* firstStack);

int main()
{
	std::cout << "Input the size of stack:" << std::endl;

	int size, numberOfElements, element;
	std::cin >> size;

	MyStack stack(size);
	std::cout << "Input how many elements do you want to push in this steck:" << std::endl;
	std::cin >> numberOfElements;

	for (int i = 0; i < numberOfElements; i++)
	{
		std::cout << "Input next element:" << std::endl;
		std::cin >> element;
		stack.push(element);
		stack.info();
	}

	system("pause");
	system("cls");
	stack.info();
	system("pause");

	std::cout << "------\n\n\n\nRewriting from first in intemediate steck:\n------" << std::endl;
	MyStack intermediateStack = rewriting(&stack);
	system("pause");

	std::cout << "------\n\n\n\nRewriting from intemediate in second steck:\n------" << std::endl;
	MyStack secondStack = rewriting(&intermediateStack);
	std::cout << std::endl;

	/*This block of code was made to check all another methods in class MyStack
	{
		system("pause");
		system("cls");
		secondStack.info();
		int k = secondStack.pop();
		secondStack.info();
		secondStack.clear();
		system("pause");
	}
	*/

	system("pause");
    return 0;
}

MyStack rewriting(MyStack* firstStack)
{
	int outputingVariable;
	MyStack secondStack;
	int firstStackSize = firstStack->size();
	for (int i = 0; i < firstStackSize; i++)
	{
		outputingVariable = firstStack->pop();
		secondStack.push(outputingVariable);
		secondStack.info();
	}
	return secondStack;
}