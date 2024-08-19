#include "student.h"  // Includes the header file for the Student class, which contains the class definition
#include <iostream>  // Includes the input/output stream library, which allows for console output operations

// Constructor for the Student class
// Initializes a Student object with the provided details: student ID, first name, last name, email address, age, days in courses, and degree program
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    // Initializes the daysInCourse array with the provided values
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}

// Accessor (Getter) Methods

// Returns the student's ID
std::string Student::getStudentID() const { return studentID; }

// Returns the student's first name
std::string Student::getFirstName() const { return firstName; }

// Returns the student's last name
std::string Student::getLastName() const { return lastName; }

// Returns the student's email address
std::string Student::getEmailAddress() const { return emailAddress; }

// Returns the student's age
int Student::getAge() const { return age; }

// Returns a pointer to the array of days in courses
const int* Student::getDaysInCourse() const { return daysInCourse; }

// Returns the student's degree program
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Mutator (Setter) Methods

// Sets the student's ID
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }

// Sets the student's first name
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }

// Sets the student's last name
void Student::setLastName(std::string lastName) { this->lastName = lastName; }

// Sets the student's email address
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }

// Sets the student's age
void Student::setAge(int age) { this->age = age; }

// Sets the days in courses array
// Copies the values from the provided array into the object's daysInCourse array
void Student::setDaysInCourse(const int daysInCourse[]) {
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}

// Sets the student's degree program
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print Method

// Prints the details of the student to the console
void Student::print() const {
    std::cout << "ID: " << studentID << "\t";  // Prints the student ID
    std::cout << "First Name: " << firstName << "\t";  // Prints the first name
    std::cout << "Last Name: " << lastName << "\t";  // Prints the last name
    std::cout << "Age: " << age << "\t";  // Prints the age
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";  // Prints the days in courses array
    std::cout << "Degree Program: " << degreeProgram << std::endl;  // Prints the degree program
}
