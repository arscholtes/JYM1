#pragma once  // Ensures this header file is included only once during compilation to prevent redefinition errors
#include <string>  // Includes the string library, which provides the std::string class for handling strings
#include "degree.h"  // Includes the header file that defines the DegreeProgram enum, which is used to specify a student's degree program

class Student {
private:
    // Private member variables to store student details
    std::string studentID;  // The student's unique ID
    std::string firstName;  // The student's first name
    std::string lastName;  // The student's last name
    std::string emailAddress;  // The student's email address
    int age;  // The student's age
    int daysInCourse[3];  // An array storing the number of days the student took to complete each of three courses
    DegreeProgram degreeProgram;  // The student's degree program, represented as an enum of type DegreeProgram

public:
    // Constructor
    // Initializes a Student object with the provided details: student ID, first name, last name, email address, age, days in courses, and degree program
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

    // Accessor (Getter) Methods
    // These methods provide read-only access to the private member variables of the Student class

    // Returns the student's ID
    std::string getStudentID() const;

    // Returns the student's first name
    std::string getFirstName() const;

    // Returns the student's last name
    std::string getLastName() const;

    // Returns the student's email address
    std::string getEmailAddress() const;

    // Returns the student's age
    int getAge() const;

    // Returns a pointer to the array of days in courses
    // The pointer allows access to the array's elements without modifying them
    const int* getDaysInCourse() const;

    // Returns the student's degree program as an enum value
    DegreeProgram getDegreeProgram() const;

    // Mutator (Setter) Methods
    // These methods allow modification of the private member variables of the Student class

    // Sets the student's ID
    void setStudentID(std::string studentID);

    // Sets the student's first name
    void setFirstName(std::string firstName);

    // Sets the student's last name
    void setLastName(std::string lastName);

    // Sets the student's email address
    void setEmailAddress(std::string emailAddress);

    // Sets the student's age
    void setAge(int age);

    // Sets the days in courses array
    // Copies the values from the provided array into the object's daysInCourse array
    void setDaysInCourse(const int daysInCourse[]);

    // Sets the student's degree program
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print Method
    // Outputs the student's details to the console in a formatted manner, including the ID, first name, last name, age, days in courses, and degree program
    void print() const;
};
