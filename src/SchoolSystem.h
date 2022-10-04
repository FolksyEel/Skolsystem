#pragma once
#include "Student.h"
#include <vector>
#include <iostream>

class SchoolSystem
{
public:
	void Run();


	void AddStudent();
	void RemoveStudent();
	void CheckStudent();
	void AddClass();

	void InitData();

	std::vector<Student> students;
	std::vector<std::string> schoolClasses;
};
