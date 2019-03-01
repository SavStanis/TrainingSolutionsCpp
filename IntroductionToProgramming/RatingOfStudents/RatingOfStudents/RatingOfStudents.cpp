
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>    
#include "Student.h"
#include "UsedFunctions.h"



int main() {

	std::ifstream studentsFile("students.csv");
	std::ofstream ratingFile("rating.csv");
	
	std::string line;
	getline(studentsFile, line);
	int numberOfStudents = std::stoi(line);

	std::vector<Student*> streamOfStudents;
	
	int notContractCounter = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		getline(studentsFile,line);
		Student* newStudent = new Student();
		newStudent = parsing(line);
		if (!newStudent->isContract()) {
			streamOfStudents.push_back(newStudent);
			notContractCounter++;
		}
	}
	
	//Sorting of Students
	sort(streamOfStudents);	

	int minAverageMark = 100;
	int Best = ((notContractCounter + 1) * 4) / 10;

	result(ratingFile, streamOfStudents, Best);

	studentsFile.close();
	ratingFile.close();
	system("pause");
	return 0;
}

