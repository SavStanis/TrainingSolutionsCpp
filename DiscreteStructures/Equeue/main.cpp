#include <iostream>
#include "Equeue.h"

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
	system("pause");
	return 0;
}