#include "student.h"



string Student::getID() const
{
    return studentID;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

string Student::getEmail() const
{
    return email;
}

int Student::getAge() const
{
 
    return age;
}

DegreeProgram Student::getDegree()
{
    return this->degree;
}

int* Student::getDaysInCourse() 
{
    
    
    return daysInCourse;
}

void Student::printHeader()
{
    cout << "Output format: ID|First Name|Last Name |Email |Age |Days in Course |Degree  \n";
}

void Student::setID(string studentID)
{
    this->studentID = studentID;
    return;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
    return;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailName(string email)
{
    this->email = email;
}

void Student::setAge(int age)
{
   this-> age = age;
}

void Student::setDaysInCourse(int* daysInCourse)
{
    for (int i = 0; i < SIZE; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::setDegree(DegreeProgram degree)
{
    this->degree = degree;
    return;
}

void Student::print() {
    cout << this->studentID << "\t";
    cout << this->firstName << "\t";
    cout << this->lastName << "\t";
    cout << this->email << "\t";
    cout << this->age << "\t";
    cout << this -> daysInCourse[0] << ", ";
    cout << this->daysInCourse[1] << ", ";
    cout<< this->daysInCourse[2]<< "\t";
    cout << degreeProgramStr[(int)getDegree()] << "\n";
    

}



Student::Student( string studentID, string firstName, string lastName, string email, int age, int daysInCourse [], DegreeProgram degree) {


            this->studentID = studentID;
            this->firstName = firstName;
            this->lastName = lastName;
            this->email = email;
            this->age  = age;
            for (int i = 0; i < SIZE; i++) this->daysInCourse[i] = daysInCourse[i];
            this->degree = degree;
}
