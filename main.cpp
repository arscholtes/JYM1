#include <iostream>  // Includes the input/output stream library
#include "roster.h"  // Includes the Roster class header file

using namespace std;  // Allows the use of standard C++ library objects and functions without prefixing them with 'std::'

// Constant array of strings representing student data
// Each entry contains a student's ID, first name, last name, email address, age, days to complete 3 courses, and degree program
const string studentData[] =
{
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Alex,Scholtes,asch726@wgu.edu,33,10,20,30,SOFTWARE"
};

// Main function - entry point of the program
int main() {
    // Output the course title, programming language, student ID, and name to the console
    cout << "Course Title: C867 - Scripting and Programming - Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: asch726\n";  // Replace with actual WGU student ID
    cout << "Name: Alex Scholtes\n";  // Replace with actual name if needed

    Roster classRoster;  // Create an instance of the Roster class

    // Parse and add each student's data to the roster
    for (const string& data : studentData) {
        classRoster.parseAndAdd(data);  // Calls the parseAndAdd method to process and add each student's data to the roster
    }

    // Print all students' information
    classRoster.printAll();  // Calls the printAll method to print the details of all students in the roster

    // Print invalid email addresses
    classRoster.printInvalidEmails();  // Calls the printInvalidEmails method to check and print any invalid email addresses

    // Print the average days in course for each student
    for (const auto& student : classRoster.getClassRosterArray()) {
        classRoster.printAverageDaysInCourse(student->getStudentID());  // Calls printAverageDaysInCourse for each student to calculate and print their average days in courses
    }

    // Print students by degree program (SOFTWARE in this case)
    classRoster.printByDegreeProgram(SOFTWARE);  // Calls the printByDegreeProgram method to print the details of students in the SOFTWARE program

    // Remove a student by their ID
    classRoster.remove("A3");  // Removes the student with ID "A3" from the roster
    classRoster.printAll();  // Prints the roster after removing the student

    return 0;  // Returns 0 to indicate successful completion of the program
}
