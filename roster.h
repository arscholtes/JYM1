#pragma once  // Ensures the header file is included only once during compilation to prevent redefinition errors
#include "student.h"  // Includes the header file for the Student class, which is used in the Roster class
#include <vector>  // Includes the standard vector library, allowing the use of the std::vector container

class Roster {
private:
    std::vector<Student*> classRosterArray;  // A vector that stores pointers to Student objects, representing the class roster

public:
    // Adds a new student to the roster
    // Takes individual student details as parameters and constructs a new Student object
    // The new Student object is then added to classRosterArray
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Removes a student from the roster by student ID
    // Searches classRosterArray for the student with the given ID, deletes the object, and removes the pointer from the vector
    // If the student is not found, it prints an error message
    void remove(std::string studentID);

    // Prints the details of all students in the roster
    // Iterates through classRosterArray and calls the print() method for each Student object
    void printAll() const;

    // Prints the average number of days a student spends in courses
    // Takes the student ID as a parameter, finds the corresponding student, calculates the average days across three courses, and prints the result
    void printAverageDaysInCourse(std::string studentID) const;

    // Verifies and prints invalid email addresses from the roster
    // An email is considered invalid if it contains a space, lacks an '@' symbol, or lacks a '.' symbol
    void printInvalidEmails() const;

    // Prints the details of students enrolled in a specific degree program
    // Takes the DegreeProgram enum as a parameter and prints the students who are enrolled in that program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // Parses a comma-separated string and adds a new student to the roster
    // The string contains student details, which are parsed and passed to the add() method to create and store a new Student object
    void parseAndAdd(const std::string& data);

    // Returns a reference to the vector containing all student pointers
    // Allows external access to classRosterArray for further operations like printing or calculating averages
    const std::vector<Student*>& getClassRosterArray() const;

    // Destructor for the Roster class
    // Deletes all dynamically allocated Student objects in classRosterArray to free memory and prevent memory leaks
    ~Roster();
};
