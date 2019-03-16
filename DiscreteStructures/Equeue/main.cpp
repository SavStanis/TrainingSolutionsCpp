#include <iostream>
#include "Equeue.h"

void replace(Equeue &my, int v, int m);

int main()
{
	int helpingVariable;
	Equeue myEqueue;
	std::cout << "How ,many elements do you want to input?" << std::endl;
	std::cin >> helpingVariable;
	for (int i = 0; i < helpingVariable; i++)
	{
		int val, pri;
		std::cout << "Input value and priority:" << std::endl;
		std::cin >> val >> pri;
		myEqueue.push(val, pri);
		myEqueue.print();
	}
	myEqueue.print();
	int v, m;
	std::cout << "Input v and m" << std::endl;
	std::cin >> v >> m;
	replace(myEqueue, v, m);
	myEqueue.print();
	system("pause");
	return 0;
}

void replace(Equeue &my, int v, int m)
{
	Equeue second;
	int thisSize = my.sizeOfEqueue();
	for (int i = 0; i < thisSize; i++)
	{
		int k = my.pop();
		if (k == v)
			second.push(k, 3);
		else
		{
			if (k == m)
				second.push(k, 1);
			else
				second.push(k, 2);
		}

	}
	my = second;
}