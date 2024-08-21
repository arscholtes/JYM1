#pragma once  // Ensures this header file is included only once during compilation to prevent redefinition errors
#include "student.h"  // Includes the header file for the Student class, which is used in the Roster class

class Roster {
private:
    Student* classRosterArray[5];  // Array of pointers to Student objects, representing the class roster

public:
    // Constructor
    Roster() noexcept;  // Initializes the classRosterArray to contain nullptrs, indicating empty slots

    // Adds a new student to the roster
    // Creates a new Student object with the provided parameters and stores it in the first available slot in classRosterArray
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Removes a student from the roster by their student ID
    // Searches for the student in classRosterArray, deletes the object, and sets the pointer to nullptr if found
    void remove(std::string studentID);

    // Prints the details of all students in the roster
    // Loops through classRosterArray and calls the print() method for each non-null Student object
    void printAll() const;

    // Prints the average number of days a student spends in courses
    // Finds the student by ID, calculates the average of their days in the three courses, and prints the result
    void printAverageDaysInCourse(std::string studentID) const;

    // Verifies and prints invalid email addresses from the roster
    // An email is considered invalid if it contains a space, lacks an '@' symbol, or lacks a '.' symbol
    void printInvalidEmails() const;

    // Prints the details of students enrolled in a specific degree program
    // Loops through classRosterArray and calls the print() method for each Student object in the specified degree program
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    // Parses a comma-separated string of student data and adds a new student to the roster
    // The string is parsed into individual data fields, which are then passed to the add() method
    void parseAndAdd(const std::string& data);

    // Returns a pointer to the array of pointers to Student objects
    // Allows external access to classRosterArray for further operations like printing or calculating averages
    const Student* const* getClassRosterArray() const;

    // Destructor
    ~Roster();  // Deletes all dynamically allocated Student objects in classRosterArray to free memory and prevent memory leaks
};
