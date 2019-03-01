#include "stdafx.h"
#include "Student.h"


Student::Student(std::string name, std::vector<int> marks, bool contract) {
	this->marks = marks;
	this->name = name;
	this->contract = contract;

	int NumberOfSubjects = 0;
	double Sum = 0;
	for (int i : marks) {
		Sum += i;
		NumberOfSubjects++;
	}
	this->averageMark = Sum / NumberOfSubjects;
}

double Student::getAverageMark() {
	return averageMark;
}

bool Student::isContract() {
	return contract;
}

std::string Student::getName() {
	return name;
}