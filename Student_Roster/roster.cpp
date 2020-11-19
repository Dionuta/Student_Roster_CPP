#pragma once
#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>



Roster::Roster() {
	this->lastIndex = -1;
	this->numStudents = 5;
	this->classRosterArray = nullptr;
}

Roster::Roster(int numStudents) {
	this->numStudents = numStudents;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [numStudents];
}





void Roster::parse(string row) {

	if (lastIndex < numStudents) {
		lastIndex++;
	}

	



	int rhs = row.find(","); // find comma
	string studentID = row.substr(0, rhs);

	int lhs = rhs + 1; // moves to the next comma
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	string tempAge = row.substr(lhs, rhs - lhs);
	int age = stoi(tempAge);

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;  // moves to the next comma
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1; // moves to the next comma
	rhs = row.find(",", lhs);

	DegreeProgram degreeProgram = DegreeProgram::UNDECIDED;
	string degreeStr = row.substr(lhs, rhs - lhs);
	if (degreeStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeStr == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}


	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);


}



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
	
	int parr[3] = { daysInCourse1 , daysInCourse2, daysInCourse3 };

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}

void Roster::printAll() {

	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; ++i){
		this->classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < 5; i++) {
		DegreeProgram tempDegree = classRosterArray[i]->getDegree();
		if (tempDegree == degree) {
			classRosterArray[i]->print();
		}
	}
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i < Roster::lastIndex; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < Roster::lastIndex; ++i) {
		string tempEmail = classRosterArray[i]->getEmail();
		if ((tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) || (tempEmail.find(" ") != string::npos)) {
			cout << tempEmail << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {

	int average = 0;

	for (int i = 0; i < 5; ++i) {
		string tempID = classRosterArray[i]->getID();
		if (tempID == studentID) {
			average = ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3);
			cout << "Student ID " << studentID << " average is: " << average << endl;
		}

	}
}

bool Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i < Roster::lastIndex; ++i) {
		if (classRosterArray[i]->getID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			cout << "Student with ID " << studentID << " removed." << endl;
			classRosterArray[i] = classRosterArray[lastIndex];
			--lastIndex;
		}
	}
	if (!found) {
		cout << "Student with ID not found." << endl;
	}
	return found;
}
