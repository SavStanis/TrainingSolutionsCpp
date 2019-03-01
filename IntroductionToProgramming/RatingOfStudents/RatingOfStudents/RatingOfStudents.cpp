
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>    
#include "Student.h"
#include "UsedFunctions.h"



int main()
{
	setlocale(LC_ALL, ".ACP");

	std::ifstream studentsFile("students.csv");
	std::ofstream ratingFile("rating.csv");
	
	std::string line;
	getline(studentsFile, line);
	int numberOfStudents = std::stoi(line);

	std::vector<Student*> streamOfStudents(numberOfStudents);

	
	
	for (int i = 0; i < numberOfStudents; i++) {
		getline(studentsFile,line);
		Student* newStudent = new Student();
		newStudent = parsing(line);
		streamOfStudents[i] = newStudent;
	}

	studentsFile.close();
	ratingFile.close();
	system("pause");
	return 0;
}

