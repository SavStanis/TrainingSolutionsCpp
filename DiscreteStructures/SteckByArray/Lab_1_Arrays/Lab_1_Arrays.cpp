
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
			if (NumberOfHead >= SizeOfStack - 1)
			{
				std::cout << "Stack overflow\n we need to resize it" << std::endl;
				resize();
				NumberOfHead++;
				StackArray[NumberOfHead] = newElement;
			}
			else 
			{
				NumberOfHead++;
				StackArray[NumberOfHead] = newElement;
			}
		}

		//It's check is this steck is empty
		bool isEmpty() 
		{
			if (NumberOfHead == -1)
			{
				return true;
			}
			return false;
		}

		//return value of the top elemetdnt of steck and delete this elevent
		int pop()
		{
			if (!isEmpty()) 
			{
				NumberOfHead--;
				return StackArray[NumberOfHead + 1];
			}
			std::cout << "\n Stack is empty" << std::endl;
			return NAN;
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

		void resize()
		{
			int newSize = SizeOfStack * 2;
			int* NewArray = new int[newSize];
			for (int i = 0; i < SizeOfStack; i++)
			{
				NewArray[i] = StackArray[i];
			}
			this->StackArray = NewArray;
			this->SizeOfStack = newSize;
		}
};

//Function for rewriting of information step by step
MyStack rewriting(MyStack* firstStack);

int main()
{
	std::cout << "Input the start size of stack:" << std::endl;

	int size = 5, numberOfElements, element;
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
	system("pause");
    return 0;
}

MyStack rewriting(MyStack* firstStack)
{
	int outputingVariable;
	MyStack secondStack(firstStack->size());
	int firstStackSize = firstStack->size();
	for (int i = 0; i < firstStackSize; i++)
	{
		outputingVariable = firstStack->pop();
		secondStack.push(outputingVariable);
		secondStack.info();
	}
	return secondStack;
}