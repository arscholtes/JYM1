#include "roster.h"
#include <iostream>
#include <sstream>

// Adds a new student to the roster
// Takes individual student details as parameters and constructs a new Student object using them
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};  // Creates an array for days in course
    classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram));  // Adds the new Student object to the classRosterArray
}

// Removes a student from the roster by student ID
// If the student is found, it deletes the object and removes it from the array
// If not found, it prints an error message
void Roster::remove(std::string studentID) {
    bool found = false;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it) {  // Iterates through the roster
        if ((*it)->getStudentID() == studentID) {  // Checks if the current student's ID matches the given ID
            delete *it;  // Deletes the Student object to free memory
            classRosterArray.erase(it);  // Removes the pointer from the roster array
            found = true;
            break;  // Exits the loop once the student is found and removed
        }
    }
    if (!found) {
        std::cout << "Error: Student ID " << studentID << " not found." << std::endl;  // Error message if student ID not found
    }
}

// Prints the details of all students in the roster
void Roster::printAll() const {
    for (const auto& student : classRosterArray) {  // Iterates through the roster
        student->print();  // Calls the print method of each Student object
    }
}

// Prints the average number of days in courses for a given student ID
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (const auto& student : classRosterArray) {  // Iterates through the roster
        if (student->getStudentID() == studentID) {  // Checks if the current student's ID matches the given ID
            const int* days = student->getDaysInCourse();  // Retrieves the days in course array
            std::cout << "Student ID: " << studentID << ", Average Days in Course: " << (days[0] + days[1] + days[2]) / 3.0 << std::endl;  // Calculates and prints the average
            return;  // Exits the method once the average is printed
        }
    }
    std::cout << "Error: Student ID " << studentID << " not found." << std::endl;  // Error message if student ID not found
}

// Verifies student email addresses and prints all invalid emails
// An email is considered invalid if it contains a space, lacks an '@' sign, or lacks a period ('.')
void Roster::printInvalidEmails() const {
    for (const auto& student : classRosterArray) {  // Iterates through the roster
        std::string email = student->getEmailAddress();  // Retrieves the student's email address
        if (email.find(' ') != std::string::npos || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {  // Checks for invalid email patterns
            std::cout << "Invalid email: " << email << std::endl;  // Prints the invalid email
        }
    }
}

// Prints the details of students enrolled in a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const auto& student : classRosterArray) {  // Iterates through the roster
        if (student->getDegreeProgram() == degreeProgram) {  // Checks if the current student's degree program matches the given program
            student->print();  // Calls the print method of each matching Student object
        }
    }
}

// Parses a comma-separated string and adds a new student to the roster
void Roster::parseAndAdd(const std::string& data) {
    std::stringstream ss(data);  // Creates a stringstream object to parse the data string
    std::vector<std::string> tokens;  // Vector to store parsed tokens
    while (ss.good()) {  // Parses each segment separated by commas
        std::string token;
        std::getline(ss, token, ',');  // Extracts each token separated by commas
        tokens.push_back(token);  // Adds the token to the vector
    }

    DegreeProgram degreeProgram = SOFTWARE;  // Default degree program
    if (tokens[8] == "SECURITY") degreeProgram = SECURITY;  // Sets degree program based on parsed token
    else if (tokens[8] == "NETWORK") degreeProgram = NETWORK;

    try {
        // Calls the add method with parsed data
        add(tokens[0], tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]), degreeProgram);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;  // Catches and prints invalid argument exceptions (e.g., from std::stoi)
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;  // Catches and prints out of range exceptions (e.g., from std::stoi)
    }
}

// Returns the vector containing all student pointers
const std::vector<Student*>& Roster::getClassRosterArray() const {
    return classRosterArray;
}

// Destructor: Deletes all dynamically allocated Student objects in the roster
Roster::~Roster() {
    for (auto& student : classRosterArray) {  // Iterates through the roster
        delete student;  // Deletes each Student object to free memory
    }
}
