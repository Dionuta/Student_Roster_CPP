#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"


using namespace std;


class Student {


public:

    //Size of days in Course
    static const int SIZE = 3;

public:

    //Constructors
  
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degree);

    //Mutators
    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    DegreeProgram getDegree();
    int* getDaysInCourse();

    static void printHeader(); //shows the format out data output

    //Accessors
    void print();
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailName(string email);
    void setAge(int age);
    void setDaysInCourse(int* daysInCourse);
    void setDegree(DegreeProgram degree);
 


private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[SIZE];
    DegreeProgram degree;

};




