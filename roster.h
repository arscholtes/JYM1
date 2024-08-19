#pragma once
#include "student.h"
#include <vector>

class Roster {
private:
    std::vector<Student*> classRosterArray;

public:
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    void parseAndAdd(const std::string& data);
    const std::vector<Student*>& getClassRosterArray() const;

    ~Roster();
};
