#include "stdafx.h"
#include "Student.h"


Student::Student(std::string name, std::vector<int> marks, std::string Kontr)
{
	this->marks = marks;
	this->name = name;
	this->Kontr = Kontr;
}

double Student::averageMark()
{
	int NumberOfSubjects = 0;
	double Sum = 0;
	for (int i : marks)
	{
		Sum += i;
		NumberOfSubjects++;
	}
	return Sum / NumberOfSubjects;
}

