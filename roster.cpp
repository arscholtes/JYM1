#include "roster.h"
#include <iostream>
#include <sstream>

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram));
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (auto it = classRosterArray.begin(); it != classRosterArray.end(); ++it) {
        if ((*it)->getStudentID() == studentID) {
            delete *it;
            classRosterArray.erase(it);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Error: Student ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() const {
    for (const auto& student : classRosterArray) {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (const auto& student : classRosterArray) {
        if (student->getStudentID() == studentID) {
            const int* days = student->getDaysInCourse();
            std::cout << "Student ID: " << studentID << ", Average Days in Course: " << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
    std::cout << "Error: Student ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() const {
    for (const auto& student : classRosterArray) {
        std::string email = student->getEmailAddress();
        if (email.find(' ') != std::string::npos || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const auto& student : classRosterArray) {
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
}

void Roster::parseAndAdd(const std::string& data) {
    std::stringstream ss(data);
    std::vector<std::string> tokens;
    while (ss.good()) {
        std::string token;
        std::getline(ss, token, ',');
        tokens.push_back(token);
    }

    DegreeProgram degreeProgram = SOFTWARE;
    if (tokens[8] == "SECURITY") degreeProgram = SECURITY;
    else if (tokens[8] == "NETWORK") degreeProgram = NETWORK;

    try {
        add(tokens[0], tokens[1], tokens[2], tokens[3], std::stoi(tokens[4]), std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7]), degreeProgram);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}

const std::vector<Student*>& Roster::getClassRosterArray() const {
    return classRosterArray;
}

Roster::~Roster() {
    for (auto& student : classRosterArray) {
        delete student;
    }
}
