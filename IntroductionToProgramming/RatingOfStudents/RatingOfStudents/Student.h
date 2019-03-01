#pragma once
#include <string>
#include <vector>

class Student {
	std::string name;
	std::vector<int> marks;
	bool contract;
public:
	Student(std::string name = " ", std::vector<int> marks = {}, bool contract = true);
	
	double averageMark();

};

