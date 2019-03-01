#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Student.h"
#include "UsedFunctions.h"


Student* parsing(std::string line)
{
	std::vector<std::string> container;
	int counter = 0;
	int lastPos = 0;
	for (char k : line) {
		if (k == ',') {
			container.push_back(line.substr(lastPos, counter - lastPos));
			lastPos = counter + 1;
		}
		if (counter == line.length() - 1) {
			container.push_back(line.substr(lastPos, counter - lastPos + 1));
		}
		counter++;
	}

	std::string name = container[0];
	std::vector<int> marks;

	for (int i = 1; i < 6; i++) {
		marks.push_back(std::stoi(container[i]));
	}

	std::string contract = container[6];
	bool isContract = false;

	if (contract == "TRUE") {
		isContract = true;
	}

	Student* newStudent = new Student(name, marks, isContract);
	return newStudent;
}

void sort(std::vector<Student*> &listOfStudent) {
	
	for (int i = 0; i < listOfStudent.size(); i++) {
		for (int j = i; j < listOfStudent.size(); j++) {
			if (listOfStudent[i]->getAverageMark() < listOfStudent[j]->getAverageMark()) {
				Student* k = new Student();
				k = listOfStudent[i];
				listOfStudent[i] = listOfStudent[j];
				listOfStudent[j] = k;
			}
		}
	}
}

void result(std::ofstream &output, std::vector<Student*> &listOfStudent, int Best) {
	double minAverageMark;
	
	for (int i = 0; i < Best; i++) {
		output << listOfStudent[i]->getName() << ","  << std::fixed<<std::setprecision(3) << listOfStudent[i]->getAverageMark() << "\n";
		minAverageMark = listOfStudent[i]->getAverageMark();
	}
	output << "Min is," << minAverageMark;
}