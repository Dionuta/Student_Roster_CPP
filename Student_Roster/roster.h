#pragma once
#include <iostream>
#include "student.h"

using namespace std;


class Roster {

public:
	int numStudents;

	int lastIndex;

	void parse(string row);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	bool remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degree);

	Student* getStudentAt(int index);

	Student** classRosterArray;


	Roster();

	Roster(int rosterSize);
	

	


	~Roster();




};