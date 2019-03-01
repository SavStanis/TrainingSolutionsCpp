#include "stdafx.h"
#include "Student.h"


Student::Student(std::string name, std::vector<int> marks, bool contract) {
	this->marks = marks;
	this->name = name;
	this->contract = contract;
}

double Student::averageMark() {
	int NumberOfSubjects = 0;
	double Sum = 0;
	for (int i : marks) {
		Sum += i;
		NumberOfSubjects++;
	}
	return Sum / NumberOfSubjects;
}

