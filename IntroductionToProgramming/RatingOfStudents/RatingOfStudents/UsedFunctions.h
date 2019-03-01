#pragma once
#include "Student.h"

Student* parsing(std::string line);

void sort(std::vector<Student*> &listOfStudent);

void result(std::ofstream & output, std::vector<Student*> &listOfStudent, int Best);