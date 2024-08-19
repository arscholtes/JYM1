#include "student.h"
#include <iostream>

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}

// Accessors
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Mutators
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(const int daysInCourse[]) {
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print
void Student::print() const {
    std::cout << "ID: " << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
    std::cout << "Degree Program: " << degreeProgram << std::endl;
}
