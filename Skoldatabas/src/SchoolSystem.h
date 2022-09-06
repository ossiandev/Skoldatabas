#pragma once
#include "Student.h"
#include <vector>
#include <string>
#include <iostream>


//hold student names
//hold vector with students vector called class
class SchoolSys
{
public:
	void Run(bool running);
	void AddStudent();
	void RemoveStudent();
	void AddClass();
	void RemoveClass();
private:
	std::vector<Student> students;
	std::vector<std::string> schoolClasses;

};