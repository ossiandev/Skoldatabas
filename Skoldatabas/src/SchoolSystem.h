#pragma once
#include "ConsoleCF.h"
#include "Student.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


//hold student names
//hold vector with students vector called class
class SchoolSys
{
public:
	//functions with algoritms
	void Run(bool running);
	void AddStudent();
	void RemoveStudent();
	void RemoveClass();
	//functions with print 
	void ShowStudents();
	void ShowClasses();
	void Clear();


private:
	std::vector<Student> students;
	std::vector<std::string> schoolClasses;

};