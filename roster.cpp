#include "roster.h"  // Includes the header file for the Roster class, which contains class declarations
#include <iostream>  // Includes the input/output stream library, allowing for console output
#include <sstream>   // Includes the string stream library, used for parsing strings

// Constructor for the Roster class
// Initializes the classRosterArray to contain nullptrs, indicating empty slots
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;  // Initialize each element of classRosterArray to nullptr
    }
}

// Adds a new student to the roster
// Creates a new Student object with the provided parameters and stores it in the first available slot in classRosterArray
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] == nullptr) {  // Find the first available (null) slot
            int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};  // Create an array to hold the days in course
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);  // Create a new Student object and assign it to the slot
            break;  // Exit the loop after adding the student
        }
    }
}

// Removes a student from the roster by their student ID
// Searches for the student in classRosterArray, deletes the object, and sets the pointer to nullptr if found
void Roster::remove(std::string studentID) {
    bool found = false;  // Flag to track if the student was found
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {  // Check if the student ID matches
            delete classRosterArray[i];  // Delete the Student object to free memory
            classRosterArray[i] = nullptr;  // Set the pointer to nullptr to mark the slot as available
            found = true;  // Set the flag to true since the student was found
            break;  // Exit the loop after removing the student
        }
    }
    if (!found) {
        std::cout << "Error: Student ID " << studentID << " not found." << std::endl;  // Print an error message if the student ID was not found
    }
}

// Prints the details of all students in the roster
// Loops through classRosterArray and calls the print() method for each non-null Student object
void Roster::printAll() const {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr) {  // Check if the slot contains a Student object
            classRosterArray[i]->print();  // Call the print method of the Student object
        }
    }
}

// Prints the average number of days a student spends in courses
// Finds the student by ID, calculates the average of their days in the three courses, and prints the result
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {  // Check if the student ID matches
            const int* days = classRosterArray[i]->getDaysInCourse();  // Get the array of days in course
            std::cout << "Student ID: " << studentID << ", Average Days in Course: " << (days[0] + days[1] + days[2]) / 3.0 << std::endl;  // Calculate and print the average days
            return;  // Exit the method after printing the average days
        }
    }
    std::cout << "Error: Student ID " << studentID << " not found." << std::endl;  // Print an error message if the student ID was not found
}

// Verifies and prints invalid email addresses from the roster
// An email is considered invalid if it contains a space, lacks an '@' symbol, or lacks a '.' symbol
void Roster::printInvalidEmails() const {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr) {  // Check if the slot contains a Student object
            std::string email = classRosterArray[i]->getEmailAddress();  // Get the student's email address
            if (email.find(' ') != std::string::npos || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {  // Check for invalid email patterns
                std::cout << "Invalid email: " << email << std::endl;  // Print the invalid email address
            }
        }
    }
}

// Prints the details of students enrolled in a specific degree program
// Loops through classRosterArray and calls the print() method for each Student object in the specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {  // Check if the student's degree program matches
            classRosterArray[i]->print();  // Call the print method of the Student object
        }
    }
}

// Parses a comma-separated string of student data and adds a new student to the roster
// The string is parsed into individual data fields, which are then passed to the add() method
void Roster::parseAndAdd(const std::string& data) {
    std::stringstream ss(data);  // Create a stringstream object to parse the data string
    std::vector<std::string> tokens;  // Vector to store parsed tokens
    while (ss.good()) {  // Parse each segment separated by commas
        std::string token;
        std::getline(ss, token, ',');  // Extract each token separated by commas
        tokens.push_back(token);  // Add the token to the vector
    }

    DegreeProgram degreeProgram = SOFTWARE;  // Default degree program
    if (tokens[8] == "SECURITY") degreeProgram = SECURITY;  // Set degree program based on parsed token
    else if (tokens[8] == "NETWORK") degreeProgram = NETWORK;

    // Call the add method with parsed data
    add(tokens[0], tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]), degreeProgram);
}

// Destructor for the Roster class
// Deletes all dynamically allocated Student objects in classRosterArray to free memory and prevent memory leaks
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {  // Loop through the classRosterArray
        if (classRosterArray[i] != nullptr) {  // Check if the slot contains a Student object
            delete classRosterArray[i];  // Delete the Student object to free memory
        }
    }
}
