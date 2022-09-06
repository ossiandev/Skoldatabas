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
	void Run();
	void AddStudent();
	void RemoveStudent();
	void AddClass();
	void RemoveClass();
private:
	std::vector<Student> classes;
	std::vector<std::string> schoolClasses;

};