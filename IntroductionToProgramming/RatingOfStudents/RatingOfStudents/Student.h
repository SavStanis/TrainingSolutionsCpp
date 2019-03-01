#pragma once
#include <string>
#include <vector>

class Student
{
	std::string name;
	std::vector<int> marks;
	std::string Kontr;
public:
	Student(std::string name, std::vector<int> marks, std::string Kontr);
	
	double averageMark();

};

