#include <iostream>
#include "roster.h"

using namespace std;

const string studentData[] =
{
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Alex,Scholtes,asch726@wgu.edu,33,10,20,30,SOFTWARE"
};

int main() {
    cout << "Course Title: C867 - Scripting and Programming - Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: [Your Student ID]\n";
    cout << "Name: Alex Scholtes\n";

    Roster classRoster;

    for (const string& data : studentData) {
        classRoster.parseAndAdd(data);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (const auto& student : classRoster.getClassRosterArray()) {
        classRoster.printAverageDaysInCourse(student->getStudentID());
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();

    return 0;
}
