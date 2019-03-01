#pragma once
#include <string>
#include <vector>

class Student {
	std::string name;
	std::vector<int> marks;
	bool contract;
	double averageMark;
public:
	Student(std::string name = " ", std::vector<int> marks = {}, bool contract = true);
	double getAverageMark();
	bool isContract();
	std::string getName();
};

